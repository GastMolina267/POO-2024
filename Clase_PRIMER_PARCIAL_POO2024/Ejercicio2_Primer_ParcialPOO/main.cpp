#include <QApplication>
#include "descargador.h"

int main (int argc, char** argv) {
    QApplication a(argc, argv);
    Descargador descargador;

    descargador.show();

    return a.exec();
}
