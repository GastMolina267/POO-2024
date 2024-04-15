#include "barra.h"
#include <QGridLayout>
#include <QTimer>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

ProgressBarEx::ProgressBarEx(QWidget *parent)
    : QWidget(parent), progress(0)
{
    QGridLayout *grid = new QGridLayout(this);
    grid->setColumnStretch(2, 1);

    pbar = new QProgressBar();
    grid->addWidget(pbar, 0, 0, 1, 3);

    lineEditURL = new QLineEdit();
    grid->addWidget(lineEditURL, 1, 0);

    downloadButton = new QPushButton("Descargar", this);
    connect(downloadButton, &QPushButton::clicked, this, &ProgressBarEx::startDownload);
    grid->addWidget(downloadButton, 1, 1);

    setLayout(grid);
}

void ProgressBarEx::startDownload() {
    QString url = lineEditURL->text();
    if (url.isEmpty()) {
        QMessageBox::warning(this, "Error", "Por favor, ingrese una URL válida.");
        return;
    }

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request(url);
    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::downloadProgress, this, [=](qint64 bytesReceived, qint64 bytesTotal){
        progress = static_cast<int>((bytesReceived * 100) / bytesTotal);
        pbar->setValue(progress);
    });

    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() != QNetworkReply::NoError) {
            QMessageBox::warning(this, "Error", "Error al descargar el archivo: " + reply->errorString());
        } else {
            QMessageBox::information(this, "Descarga completada", "La descarga se ha completado exitosamente.");
        }
        reply->deleteLater();
    });
}


void ProgressBarEx::setPorcentaje(int porcentaje)
{
    if (porcentaje >= 0 && porcentaje <= MAX_VALUE) {
        progress = porcentaje;
        pbar->setValue(progress);
    }
}
