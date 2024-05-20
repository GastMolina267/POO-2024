#ifndef WEATHER_H
#define WEATHER_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>

class Weather : public QWidget
{
    Q_OBJECT

public:
    Weather(double latitud, double longitud);

private:
    double latitud, longitud, temperatura;
    QNetworkAccessManager* manager;

signals:
    void weatherChanged(const QString &temperatura);

public slots:
    void obtenerTemperatura();

private slots:
    void slot_descargaFinalizada(QNetworkReply* reply);
};

#endif // WEATHER_H
