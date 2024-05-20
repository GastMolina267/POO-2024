#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->barra, &Barra::setPorcentaje, ui->barra, &Barra::setPorcentaje);

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::onDownloadFinished);

    QObject::connect(ui->lineEditURL, &QLineEdit::returnPressed, [=](){
        QUrl url(ui->lineEditURL->text());
        QNetworkRequest request(url);
        QNetworkReply *reply = manager->get(request);
        connect(reply, &QNetworkReply::downloadProgress, this, [=](qint64 bytesReceived, qint64 bytesTotal){
            int porcentaje = static_cast<int>((bytesReceived * 100) / bytesTotal);
            ui->barra->setPorcentaje(porcentaje);
        });
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onDownloadFinished(QNetworkReply *reply)
{
    if(reply->error()) {
        QMessageBox::warning(this, "Error", reply->errorString());
    }
    reply->deleteLater();
}
