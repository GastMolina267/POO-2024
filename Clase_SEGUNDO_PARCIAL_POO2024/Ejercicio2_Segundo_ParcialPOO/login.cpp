#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->leClave->setEchoMode(QLineEdit::Password);

    blockCheck = 0;

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_descargaFinalizada(QNetworkReply * )));
    QNetworkRequest request(QUrl("https://img.freepik.com/vector-gratis/fondo-futurista-degradado-geometrico_23-2149116406.jpg"));
    ui->leURL->setText("https://img.freepik.com/vector-gratis/fondo-futurista-degradado-geometrico_23-2149116406.jpg");
    manager->get(request);

    adminDB = new AdminDB( this );
    qDebug() << "La base se abrio bien" << adminDB->conectar( "C:/Users/marin/OneDrive/Imágenes/Documentos/base_poo.sqlite" );

    connect(ui->pbIngresar, SIGNAL(clicked(bool)), this, SLOT(slot_verificar_usuario()));
}

Login::~Login()
{
    delete ui;
}

void Login::slot_verificar_usuario() {
    if (adminDB->validarUsuario( "usuarios", ui->leUsuario->text(), ui->leClave->text()))  {
        ventana = new Ventana();
        ventana->show();
        this->close();
    }
    else  {
        blockCheck++;
        ui->leClave->setText("");
        if(blockCheck == 3) {
            this->close();
        }
    }
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
