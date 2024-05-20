#ifndef ELECTRICO_H
#define ELECTRICO_H

#include <QDebug>

class Electrico {
public:
    Electrico(int voltaje = 220) : voltaje(voltaje) {}
    virtual ~Electrico() {
        qDebug() << "Desenchufado";
    }
    int getVoltaje() const {
        return voltaje;
    }
    void setVoltaje(int v) {
        voltaje = v;
    }
private:
    int voltaje;
};

#endif // ELECTRICO_H
