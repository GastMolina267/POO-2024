#include "galeriafotos.h"
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QDebug>

GaleriaFotos::GaleriaFotos(QWidget *parent) : QMainWindow(parent), indiceActual(0) {
    // Crear la interfaz de usuario
    imagenLabel = new QLabel(this);
    avanzarButton = new QPushButton("Avanzar", this);
    retrocederButton = new QPushButton("Retroceder", this);
    urlLineEdit = new QLineEdit(this);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(imagenLabel);
    layout->addWidget(avanzarButton);
    layout->addWidget(retrocederButton);
    layout->addWidget(urlLineEdit);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Conectar señales y slots
    connect(avanzarButton, &QPushButton::clicked, this, &GaleriaFotos::avanzar);
    connect(retrocederButton, &QPushButton::clicked, this, &GaleriaFotos::retroceder);

    // Cargar las URL de las imágenes desde el archivo de texto
    QFile file("/imagenes.txt"); // Ruta relativa al directorio de trabajo actual
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error al abrir el archivo:" << file.errorString();
        return;
    }

    while (!file.atEnd()) {
        QString url = file.readLine();
        urls.append(url.trimmed());
    }

    file.close();

    if (urls.isEmpty()) {
        qDebug() << "El archivo está vacío.";
        return;
    }

    // Mostrar la primera imagen
    imagenLabel->setPixmap(QPixmap(urls.first()));
    urlLineEdit->setText(urls.first());
}

void GaleriaFotos::avanzar() {
    indiceActual = (indiceActual + 1) % urls.size();
    QMetaObject::invokeMethod(imagenLabel, "setPixmap", Qt::QueuedConnection, Q_ARG(QPixmap, QPixmap(urls[indiceActual])));
    urlLineEdit->setText(urls[indiceActual]);
}

void GaleriaFotos::retroceder() {
    indiceActual = (indiceActual - 1 + urls.size()) % urls.size();
    QMetaObject::invokeMethod(imagenLabel, "setPixmap", Qt::QueuedConnection, Q_ARG(QPixmap, QPixmap(urls[indiceActual])));
    urlLineEdit->setText(urls[indiceActual]);
}
