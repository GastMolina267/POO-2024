#include <QCoreApplication>
#include <iostream>
#include <vector>
#include "class.h"
using namespace std;

void Ejecucion() {
    Calculadora* UNO = new Calculadora();
    Calculadora* DOS = new Calculadora('+', '1', '2');
    Calculadora* TRES = new Calculadora('-', '3', '4');
    Calculadora* CUATRO = new Calculadora('*', '5', '6');
    Calculadora* CINCO = new Calculadora('/', '7', '8');
    vector <Calculadora*>* POINTER = new vector <Calculadora*>;
    POINTER->push_back(UNO);
    POINTER->push_back(DOS);
    POINTER->push_back(TRES);
    POINTER->push_back(CUATRO);
    POINTER->push_back(CINCO);

    // Para Ordenarlo podriamos utilizar el Metodo SORT incluido con iostream, la cual se puede utilizar para ordenar Vectores
    sort(POINTER->begin(), POINTER->end());
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Ejecucion();
    return a.exec();
}
