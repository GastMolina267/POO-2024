#include <descargador.h>

Descargador::Descargador() {
    this->setMinimumSize(800, 800);

    layout = new QGridLayout;
    leUrl = new QLineEdit("https://images.pexels.com/photos/417074/pexels-photo-417074.jpeg");
    leUrl->setReadOnly(true);

    pbDescargar = new QPushButton("Descargar");

    pbBarra = new QProgressBar(this);
    pbBarra->setAlignment(Qt::AlignCenter);

    layout->addWidget(leUrl, 0, 0, 1, 1);
    layout->addWidget(pbDescargar, 0, 1, 1, 1);
    layout->addWidget(pbBarra, 1, 0, 1, 2);

    this->setLayout(layout);
    connect(pbDescargar, SIGNAL(clicked(bool)), this, SLOT(slot_iniciarDescarga()));
}

void Descargador::slot_iniciarDescarga() {
    manager = new QNetworkAccessManager;
    connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_descargaFinalizada(QNetworkReply * )));
    QNetworkRequest request(QUrl(leUrl->text()));
    QNetworkReply *reply = manager->get(request);
    // connect(reply, &QNetworkReply::downloadProgress, this, &slot_DownloadProgress); // Para actualizar la Barra de Progreso
    connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(slot_DownloadProgress(qint64,qint64)));
}

void Descargador::slot_descargaFinalizada(QNetworkReply* reply) {
    img = QImage::fromData(reply->readAll()); // Guarda los Datos obtenidos de la Descarga en IMG
    this->repaint();
}

void Descargador::paintEvent(QPaintEvent *) { // Pinta la Imágen de Fondo
    QPainter painter(this);
    if(!img.isNull()) {
        this->show();
        painter.drawImage(0, 0, img.scaled(this->size()));
    }
}

void Descargador::slot_DownloadProgress(qint64 ist, qint64 max) { // Actualiza la Barra de Progreso
    pbBarra->setRange(0,max);
    pbBarra->setValue(ist);
}
