#include <QCoreApplication>
#include <QVector>
#include <memory>
#include "instrumentos.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QVector<std::shared_ptr<Instrumento>> instrumentos;

    auto guitarra1 = std::make_shared<Guitarra>();
    auto guitarra2 = std::make_shared<Guitarra>(12);
    auto bateria = std::make_shared<Bateria>();
    auto teclado1 = std::make_shared<Teclado>();
    auto teclado2 = std::make_shared<Teclado>(61, 110); // Diferente voltaje

    instrumentos.append(guitarra1);
    instrumentos.append(guitarra2);
    instrumentos.append(bateria);
    instrumentos.append(teclado1);
    instrumentos.append(teclado2);

    for (const auto& instrumento : instrumentos) {
        instrumento->verlo();
        instrumento->sonar();
    }

    {
        auto tempTeclado = std::make_shared<Teclado>();
        tempTeclado->verlo();
        tempTeclado->sonar();
        // tempTeclado goes out of scope here, triggering its destructor
    }

    // Usando la clase friend
    Teclado myTeclado;
    AmigoClase amigo;
    amigo.mostrarVoltaje(myTeclado);

    // Mostrar detalles específicos de Guitarra y Bateria
    std::cout << "\nDetalles específicos:\n";
    guitarra1->mostrarCuerdas();
    guitarra2->mostrarCuerdas();
    bateria->mostrarTambores();

    return a.exec();
}
