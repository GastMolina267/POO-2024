#ifndef VIENTO_H
#define VIENTO_H

#include "instrumento.h"

class Viento : public Instrumento {
public:
    Viento(const QString& marca, float precio, const QString& metal_usado)
        : metal_usado(metal_usado) {
        this->marca = marca;
        this->precio = precio;
    }

    void afinar() const override {
        std::cout << "Afinando instrumento de viento: Marca = " << marca.toStdString()
                  << ", Precio = " << precio
                  << ", Metal Usado = " << metal_usado.toStdString() << std::endl;
    }

    QString getMetalUsado() const { return metal_usado; }

private:
    QString metal_usado;
};

#endif // VIENTO_H
