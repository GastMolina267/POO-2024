#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager();
    connect(ui->pbVerificar, SIGNAL(clicked(bool)), this, SLOT(slot_verificar_usuario()));
    connect(ui->pbCerrar, SIGNAL(clicked(bool)), this, SLOT(slot_cerrar_programa()));
}

Login::~Login()
{
    delete ui;
}

void Login::slot_verificar_usuario() {
    if (!(ui->leNombre->text().isEmpty()) && !(ui->leApellido->text().isEmpty())) {
        qDebug() << "Verificando Usuarios...";
        connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_verificar_usuario(QNetworkReply * )));
        QString url = "http://127.0.0.1:8000/verify?user_name=" + ui->leNombre->text();
        QNetworkRequest request(url);
        manager->get(request);
    } else {
        qDebug() << "Alguno de los Dos Campos estan Vacios";
    }
}

void Login::slot_cerrar_programa() {
    QApplication::quit();
}

void Login::slot_verificar_usuario(QNetworkReply * reply) {
    qDebug() << "Verificando si Existe el Usuario...";
    QString temp = reply->readAll();
    qDebug() << temp;
    if (temp == "\"DENEGADO\"" || temp == "") {
        qDebug() << "Persona no Existe";
        return;
    } else {
        qDebug() << "Persona existe con este temp" << temp;
        this->close();
    }
}
