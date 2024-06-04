#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <QString>
#include <iostream>

class Instrumento {
public:
    virtual ~Instrumento() {}
    virtual void afinar() const = 0;
    QString getMarca() const { return marca; }
    float getPrecio() const { return precio; }

protected:
    QString marca;
    float precio;
};

#endif // INSTRUMENTO_H
