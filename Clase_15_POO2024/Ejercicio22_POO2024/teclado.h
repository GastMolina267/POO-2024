#ifndef TECLADO_H
#define TECLADO_H

#include "instrumento.h"
#include "electrico.h"

class Teclado : public Instrumento, public Electrico {
public:
    Teclado(int teclas = 61, int voltaje = 220)
        : Instrumento("Yamaha"), Electrico(voltaje), teclas(teclas) {}
    void sonar() const override {
        qDebug() << "Teclado suena...";
    }
    void setTeclas(int t) {
        teclas = t;
    }
    int getTeclas() const {
        return teclas;
    }
private:
    int teclas;
};

#endif // TECLADO_H
