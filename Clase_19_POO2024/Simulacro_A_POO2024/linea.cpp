#include "linea.h"

Linea::Linea(int xInicial, int yInicial, int xFinal, int yFinal)
    : x_inicial(xInicial), y_inicial(yInicial), x_final(xFinal), y_final(yFinal)
{}

int Linea::getXInicial() const { return x_inicial; }
int Linea::getYInicial() const { return y_inicial; }
int Linea::getXFinal() const { return x_final; }
int Linea::getYFinal() const { return y_final; }
