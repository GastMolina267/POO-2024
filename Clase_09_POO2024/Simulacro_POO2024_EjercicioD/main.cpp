#include <QApplication>
#include "galeriafotos.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    GaleriaFotos ventana;
    ventana.show();

    return app.exec();
}
