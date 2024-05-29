//ventana.cpp

#include "ventana.h"

Ventana::Ventana() {
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_descargaFinalizada(QNetworkReply * )));
    QNetworkRequest request(QUrl("https://www.gastroactitud.com/wp-content/uploads/2021/07/frisona.jpg"));
    manager->get(request);

    lMAIN = new QLabel ("URL de la IMG");
    lMAIN->setAlignment(Qt::AlignCenter);
    QFont fontMAIN = lMAIN->font();
    fontMAIN.setBold(true);
    fontMAIN.setPointSize(12);
    lMAIN->setFont(fontMAIN);

    lURL = new QLabel ("https://media.geeksforgeeks.org/wp-content/uploads/20230426115225/computer-image-660.jpg");
    lURL->setAlignment(Qt::AlignCenter);
    pbSalir = new QPushButton ("Salir");
    layout = new QGridLayout;

    layout->addWidget(lURL, 0, 1, 1, 3);
    layout->addWidget(lURL, 1, 1, 1, 3);
    layout->addWidget(pbSalir, 2, 1, 1, 3);

    QObject::connect( pbSalir, SIGNAL( clicked(bool) ), this , SLOT( slot_cerrar() ) );
    this->setLayout(layout);
}

void Ventana::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    if(!im.isNull()) {
        this->show();
        painter.drawImage(0, 0, im.scaled(this->size()));
    }
}

void Ventana::slot_descargaFinalizada(QNetworkReply* reply) {
    im = QImage::fromData(reply->readAll());
    this->repaint();
}

void Ventana::slot_cerrar() {
    QApplication::quit();
}
