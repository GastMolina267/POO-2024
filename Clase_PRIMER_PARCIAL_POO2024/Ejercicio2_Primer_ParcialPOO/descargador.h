#ifndef DESCARGADOR_H
#define DESCARGADOR_H

#include <QApplication>
#include <QWidget>

#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QImage>
#include <QPainter>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>

#include <QProgressBar>

class Descargador : public QWidget {
    Q_OBJECT
    private:
        QLineEdit* leUrl;
        QPushButton* pbDescargar;
        QProgressBar* pbBarra;

        QNetworkAccessManager* manager;
        QImage img;

        QGridLayout* layout;

    public:
        Descargador();

    private slots:
        void slot_iniciarDescarga();
        void slot_descargaFinalizada(QNetworkReply* reply);
        void slot_DownloadProgress(qint64 ist, qint64 max);

    protected:
        void paintEvent(QPaintEvent *event);
};

#endif // DESCARGADOR_H
