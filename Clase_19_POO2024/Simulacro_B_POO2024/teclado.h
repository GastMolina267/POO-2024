#ifndef TECLADO_H
#define TECLADO_H

#include "instrumento.h"

class Teclado : public Instrumento {
public:
    Teclado(const QString& marca, float precio, int cantidad_de_teclas)
        : cantidad_de_teclas(cantidad_de_teclas) {
        this->marca = marca;
        this->precio = precio;
    }

    void afinar() const override {
        std::cout << "Afinando teclado: Marca = " << marca.toStdString()
                  << ", Precio = " << precio
                  << ", Cantidad de Teclas = " << cantidad_de_teclas << std::endl;
    }

    int getCantidadDeTeclas() const { return cantidad_de_teclas; }

private:
    int cantidad_de_teclas;
};

#endif // TECLADO_H
