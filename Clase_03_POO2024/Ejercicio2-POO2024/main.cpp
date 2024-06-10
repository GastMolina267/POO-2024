#include <QCoreApplication>
#include <iostream>
#include <string>
#include <cstdlib>
#include "LIB.dll"
using namespace std;

void Ejecucion() {
    Decir_Hola();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Ejecucion();
    return a.exec();
}
