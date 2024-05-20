#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_descargaFinalizada(QNetworkReply * )));
    QNetworkRequest request(QUrl("https://img.freepik.com/vector-gratis/fondo-abstracto-liquido-degradado_23-2148922974.jpg"));
    manager->get(request);

    connect(ui->pbIngresar, SIGNAL(clicked(bool)), this, SLOT(slot_verificar_usuario()));
    connect(ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_verificar_usuario()));
    connect(ui->pbRegistrarse, SIGNAL(clicked(bool)), this, SLOT(slot_registrarse()));
}

Login::~Login()
{
    delete ui;
}

void Login::slot_verificar_usuario() {
    adminDB = new AdminDB( this );
    adminDB->conectar("C:/Users/marin/OneDrive/Imágenes/Documentos/db.sqlite");
    if(ui->leUsuario->text()!="" && ui->leUsuario->text()!=""){
        if (adminDB->validarUsuario( "usuarios", ui->leUsuario->text(), ui->leClave->text()))  {
            QMessageBox::information(this, "Registro exitoso!", "Usuario logueado con éxito.");
            qDebug() << "Información: Usuario logueado con éxito.";
            emit signal_logging_in();
            ui->leUsuario->setText("");
            ui->leClave->setText("");
            this->hide();
        }
        else  {
            QMessageBox::warning(this, "Registro fallido!", "El usuario o la contrasena son incorrectos.");
            qDebug() << "Información: Registro de usuario fallido.";
            ui->leClave->setText("");
        }
    }else{
        QMessageBox::warning(this, "Login incompleto!", "Complete todos los campos.");
        qDebug() << "Información: Logueo de usuario incompleto.";
    }
}

void Login::slot_registrarse() {
    emit signal_go_to_registry();
    ui->leUsuario->setText("");
    ui->leClave->setText("");
    this->hide();
}

void Login::slot_descargaFinalizada(QNetworkReply* reply) {
    im = QImage::fromData(reply->readAll());
    this->repaint();
}

void Login::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    if(!im.isNull()) {
        painter.drawImage(0, 0, im.scaled(this->size()));
    }
}
