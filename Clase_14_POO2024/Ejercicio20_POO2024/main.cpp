#include "ventana.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Ventana w;

    return a.exec();
}
