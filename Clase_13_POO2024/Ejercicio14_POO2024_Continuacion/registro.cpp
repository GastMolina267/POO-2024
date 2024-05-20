#include "registro.h"
#include "ui_registro.h"
#include <QMessageBox>

Registro::Registro(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Registro)
{
    ui->setupUi(this);

    adminDB = new AdminDB( this );
    qDebug() << "La base se abrio bien" << adminDB->conectar( "C:/Users/marin/OneDrive/Imágenes/Documentos/db.sqlite" );

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_descargaFinalizada(QNetworkReply * )));
    QNetworkRequest request(QUrl("https://img.freepik.com/vector-gratis/fondo-futurista-degradado-geometrico_23-2149116406.jpg"));
    manager->get(request);

    connect(ui->pbRegistrarse, SIGNAL(clicked(bool)), this, SLOT(slot_registrarUsuario()));
}

Registro::~Registro()
{
    delete ui;
}

void Registro::slot_registrarUsuario() {
    if (ui->leUsuario->text() != "" && ui->leClave->text() != "" && ui->leNombre->text() != "" && ui->leApellido->text() != "") {
        if (adminDB->existeUsuario("usuarios", ui->leUsuario->text()) == true) {
            ui->pbRegistrarse->setText("Usuario ya Existe - Intente con otro Usuario");
            QMessageBox::warning(this, "Advertencia", "El usuario ya existe. Por favor, intente con otro usuario.");
            qDebug() << "Advertencia: El usuario ya existe.";
        } else {
            adminDB->ingresarUsuario("usuarios", ui->leUsuario->text(), ui->leClave->text(), ui->leNombre->text(), ui->leApellido->text());
            QMessageBox::information(this, "Registro exitoso", "Usuario registrado con éxito.");
            qDebug() << "Información: Usuario registrado con éxito.";
            this->close();
        }
    }else{
        QMessageBox::warning(this, "Advertencia", "Por favor, complete todos los campos.");
        qDebug() << "Advertencia: Algunos campos están vacíos.";
    }
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
