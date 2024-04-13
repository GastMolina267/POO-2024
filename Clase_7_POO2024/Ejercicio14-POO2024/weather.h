#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

class Weather : public QObject {
    Q_OBJECT
public:
    explicit Weather(QObject *parent = nullptr);

    void obtenerTemperatura(const QString &ciudad);

signals:
    void climaObtenido(const QString &temperatura);

private:
    QNetworkAccessManager *manager;

private slots:
    void respuestaRecibida(QNetworkReply *reply);
};

#endif // WEATHER_H
