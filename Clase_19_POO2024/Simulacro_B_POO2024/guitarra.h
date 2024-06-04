#ifndef GUITARRA_H
#define GUITARRA_H

#include "instrumento.h"

class Guitarra : public Instrumento {
public:
    Guitarra(const QString& marca, float precio, int cantidad_de_cuerdas)
        : cantidad_de_cuerdas(cantidad_de_cuerdas) {
        this->marca = marca;
        this->precio = precio;
    }

    void afinar() const override {
        std::cout << "Afinando guitarra: Marca = " << marca.toStdString()
                  << ", Precio = " << precio
                  << ", Cantidad de Cuerdas = " << cantidad_de_cuerdas << std::endl;
    }

    int getCantidadDeCuerdas() const { return cantidad_de_cuerdas; }

private:
    int cantidad_de_cuerdas;
};

#endif // GUITARRA_H
