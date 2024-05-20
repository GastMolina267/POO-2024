#include <QCoreApplication>
#include <QVector>
#include <memory>
#include "guitarra.h"
#include "bateria.h"
#include "teclado.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QVector<std::shared_ptr<Instrumento>> instrumentos;

    instrumentos.append(std::make_shared<Guitarra>());
    instrumentos.append(std::make_shared<Guitarra>(12));
    instrumentos.append(std::make_shared<Bateria>());
    instrumentos.append(std::make_shared<Teclado>());
    instrumentos.append(std::make_shared<Teclado>(220));

    for (const auto& instrumento : instrumentos) {
        instrumento->verlo();
        instrumento->sonar();
    }

    {
        auto tempTeclado = std::make_shared<Teclado>();
        tempTeclado->verlo();
        tempTeclado->sonar();
    }

    return a.exec();
}
