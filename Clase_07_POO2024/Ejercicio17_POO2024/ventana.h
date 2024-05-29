#ifndef VENTANA_H
#define VENTANA_H

#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QImage>
#include <QPainter>

class Ventana : public QWidget {
    Q_OBJECT
private:
    QLabel* lMAIN, *lURL;
    QPushButton* pbSalir;
    QGridLayout* layout;

    QNetworkAccessManager* manager;
    QImage im;

public:
    Ventana();

private slots:
    void slot_descargaFinalizada(QNetworkReply* reply);
    void slot_cerrar();

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // VENTANA_H
