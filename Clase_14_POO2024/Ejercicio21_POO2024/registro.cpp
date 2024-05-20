#include "registro.h"
#include "ui_registro.h"
#include <QMessageBox>

Registro::Registro(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Registro)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_descargaFinalizada(QNetworkReply * )));
    QNetworkRequest request(QUrl("https://img.freepik.com/vector-gratis/fondo-abstracto-liquido-degradado_23-2148922974.jpg"));
    manager->get(request);

    connect(ui->pbRegistrarse, SIGNAL(clicked(bool)), this, SLOT(slot_registrarUsuario()));
    connect(ui->pbVolver, SIGNAL(clicked(bool)), this, SLOT(slot_go_to_login()));
}

Registro::~Registro()
{
    delete ui;
}

void Registro::slot_registrarUsuario() {
    adminDB = new AdminDB( this );
    adminDB->conectar("C:/Users/marin/OneDrive/Imágenes/Documentos/db.sqlite");
    if (ui->leUsuario->text() != "" && ui->leClave->text() != "" && ui->leNombre->text() != "" && ui->leApellido->text() != "") {
        if (adminDB->existeUsuario("usuarios", ui->leUsuario->text()) == true) {
            ui->pbRegistrarse->setText("Usuario ya Existe - Intente con otro Usuario");
            QMessageBox::warning(this, "Usuario ya Existente", "El usuario ingresado ya existe. Intente nuevamente.");
            qDebug() << "Información: Usuario registrado ya existente.";
        } else {
            adminDB->ingresarUsuario("usuarios", ui->leUsuario->text(), ui->leClave->text(), ui->leNombre->text(), ui->leApellido->text());
            QMessageBox::information(this, "Registro exitoso", "Usuario registrado con éxito.");
            qDebug() << "Información: Usuario registrado con éxito.";
            emit signal_go_to_login();
            ui->leNombre->setText("");
            ui->leApellido->setText("");
            ui->leClave->setText("");
            ui->leUsuario->setText("");
            this->hide();
        }
    }else{
        QMessageBox::warning(this, "Registro incompleto!", "Por favor, complete todos los campos.");
        qDebug() << "Información: Registro de usuario incompleto.";
    }
}

void Registro::slot_go_to_login() {
    emit signal_go_to_login();
    ui->leNombre->setText("");
    ui->leApellido->setText("");
    ui->leClave->setText("");
    ui->leUsuario->setText("");
    this->hide();
}

void Registro::slot_descargaFinalizada(QNetworkReply* reply) {
    im = QImage::fromData(reply->readAll());
    this->repaint();
}

void Registro::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    if(!im.isNull()) {
        painter.drawImage(0, 0, im.scaled(this->size()));
    }
}
