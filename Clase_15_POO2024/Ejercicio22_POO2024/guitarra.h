#ifndef GUITARRA_H
#define GUITARRA_H

#include "instrumento.h"

class Guitarra : public Instrumento {
public:
    Guitarra(int cuerdas = 6) : cuerdas(cuerdas) {}
    void sonar() const override {
        qDebug() << "Guitarra suena...";
    }
    void setCuerdas(int c) {
        cuerdas = c;
    }
    int getCuerdas() const {
        return cuerdas;
    }
private:
    int cuerdas;
};

#endif // GUITARRA_H
