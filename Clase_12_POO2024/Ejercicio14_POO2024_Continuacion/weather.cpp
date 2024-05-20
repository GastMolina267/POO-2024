#include "weather.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

Weather::Weather(double latitud, double longitud) :
    latitud(latitud),
    longitud(longitud)
{
    manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_descargaFinalizada(QNetworkReply*)));
    // connect(manager, &QNetworkAccessManager::finished, this, &Weather::slot_descargaFinalizada);
}

void Weather::obtenerTemperatura() {
    QString apiKey = "fc739a78ea881ebb04608c9c327629c5";
    QUrl apiUrl("http://api.openweathermap.org/data/2.5/weather");
    QUrlQuery query;
    query.addQueryItem("lat", QString::number(latitud));
    query.addQueryItem("lon", QString::number(longitud));
    query.addQueryItem("appid", apiKey);
    apiUrl.setQuery(query);

    QNetworkRequest request(apiUrl);
    manager->get(request);
}

void Weather::slot_descargaFinalizada(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
        QJsonObject jsonObj = jsonDoc.object();

        if (jsonObj.contains("main")) {
            QJsonObject mainObj = jsonObj["main"].toObject();
            if (mainObj.contains("temp")) {
                double temperaturaKelvin = mainObj["temp"].toDouble();
                double temperaturaCelsius = temperaturaKelvin - 273.15;
                emit weatherChanged(QString::number(temperaturaCelsius, 'f', 1) + " °C");
            }
        }
    } else {
        qDebug() << "Error:" << reply->errorString();
    }

    reply->deleteLater();
}
