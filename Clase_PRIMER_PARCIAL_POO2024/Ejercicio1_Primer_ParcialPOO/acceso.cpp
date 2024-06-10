#include "acceso.h"
#include "ui_acceso.h"

Acceso::Acceso(QWidget *parent) : QWidget(parent),
                                ui(new Ui::Acceso),
                                manager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_descarga_finalizada(QNetworkReply*)));

    QString sUrl = "https://upload.wikimedia.org/wikipedia/commons/0/0a/Newlands_-_geograph.org.uk_-_283875.jpg";
    manager->get(QNetworkRequest(QUrl(sUrl)));

    ui->leUsuario->setFocus();

    connect(ui->pbIngresar, SIGNAL(pressed()), this, SLOT(slot_verificar_usuario()));
    connect(ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_verificar_usuario()));
}

Acceso::~Acceso()
{
    delete ui;
}

void Acceso::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if (! im.isNull()) {
        painter.drawImage(0, 0, im.scaled(this->width(), this->height()));
    }
}

void Acceso::slot_descarga_finalizada(QNetworkReply *reply)
{
    im = QImage::fromData(reply->readAll());
    this->repaint();
    this->show();
}


void Acceso::slot_verificar_usuario()
{
    if ((ui->leUsuario->text() == "admin" && ui->leClave->text() == "1234") || (ui->leUsuario->text() == "user" && ui->leClave->text() == "4321")) {
        qDebug() << "Usuario Valido";
        ventana = new Ventana();
        this->hide();
        if (ui->leUsuario->text() == "admin") {
            ventana->set_user("admin");
        } else {
            ventana->set_user("user");
        }
        ventana->show();
    }
    else {
        qDebug() << "Usuario no Valido";
        ui->leClave->setText(NULL);
        intentos++;
        if (intentos == 3) {
            this->close();
        }
    }
}

