#include "weather.h"

Weather::Weather(QObject *parent) : QObject(parent) {
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &Weather::respuestaRecibida);
}

void Weather::obtenerTemperatura(const QString &ciudad) {
    QString apiKey = "5eae1e4eaf478d8ddc69ad0e75badc26"; // Reemplaza "TU_API_KEY" con tu propia API Key
    QString url = "http://api.openweathermap.org/data/2.5/weather?q=" + ciudad + "&appid=" + apiKey;
    manager->get(QNetworkRequest(QUrl(url)));
}

void Weather::respuestaRecibida(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QJsonDocument jsonResponse = QJsonDocument::fromJson(reply->readAll());
        QJsonObject jsonObject = jsonResponse.object();
        QJsonObject mainObject = jsonObject["main"].toObject();
        double temperatura = mainObject["temp"].toDouble();
        temperatura -= 273.15; // Convertir de Kelvin a Celsius
        QString temperaturaStr = QString::number(temperatura, 'f', 1) + "°C";
        emit climaObtenido(temperaturaStr);
    } else {
        QMessageBox::warning(nullptr, "Error", "No se pudo obtener la temperatura actual.");
    }
    reply->deleteLater();
}
