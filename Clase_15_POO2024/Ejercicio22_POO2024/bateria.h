#ifndef BATERIA_H
#define BATERIA_H

#include "instrumento.h"

class Bateria : public Instrumento {
public:
    Bateria(int tambores = 5) : tambores(tambores) {}
    void sonar() const override {
        qDebug() << "Batería suena...";
    }
    void setTambores(int t) {
        tambores = t;
    }
    int getTambores() const {
        return tambores;
    }
private:
    int tambores;
};

#endif // BATERIA_H
