#ifndef INSTRUMENTOS_H
#define INSTRUMENTOS_H

#include <iostream>
#include <QString>

// Clase base Instrumento
class Instrumento {
public:
    Instrumento(const QString& marca = "Yamaha") : marca(marca) {}
    virtual ~Instrumento() = default;

    virtual void sonar() const = 0;
    virtual void verlo() const {
        std::cout << "Marca: " << marca.toStdString() << std::endl;
    }

protected:
    QString marca;
};

// Clase base para instrumentos de cuerda
class Cuerda {
public:
    Cuerda(int cuerdas = 6) : cuerdas(cuerdas) {}

    // Función inline
    inline int getCuerdas() const { return cuerdas; }
    inline void setCuerdas(int c) { cuerdas = c; }

protected:
    int cuerdas;
};

// Clase derivada Guitarra con herencia múltiple
class Guitarra : public Instrumento, public Cuerda {
public:
    Guitarra(int cuerdas = 6) : Instrumento(), Cuerda(cuerdas) {}

    void sonar() const override {
        std::cout << "Guitarra suena..." << std::endl;
    }

    void mostrarCuerdas() const {
        std::cout << "Número de cuerdas: " << getCuerdas() << std::endl;
    }
};

// Clase base para instrumentos de percusión
class Percusion {
public:
    Percusion(int tambores = 5) : tambores(tambores) {}

    // Función inline
    inline int getTambores() const { return tambores; }
    inline void setTambores(int t) { tambores = t; }

protected:
    int tambores;
};

// Clase derivada Bateria con herencia múltiple
class Bateria : public Instrumento, public Percusion {
public:
    Bateria(int tambores = 5) : Instrumento(), Percusion(tambores) {}

    void sonar() const override {
        std::cout << "Bateria suena..." << std::endl;
    }

    void mostrarTambores() const {
        std::cout << "Número de tambores: " << getTambores() << std::endl;
    }
};

// Clase Electrico
class Electrico {
public:
    Electrico(int voltaje = 220) : voltaje(voltaje) {}
    virtual ~Electrico() {
        std::cout << "Desenchufado" << std::endl;
    }

    // Función inline
    inline int getVoltaje() const { return voltaje; }
    inline void setVoltaje(int v) { voltaje = v; }

protected:
    int voltaje;
};

// Forward declaration
class AmigoClase;

// Clase derivada Teclado con herencia múltiple
class Teclado : public Instrumento, public Electrico {
public:
    Teclado(int teclas = 61, int voltaje = 220)
        : Instrumento(), Electrico(voltaje), teclas(teclas) {}

    void sonar() const override {
        std::cout << "Teclado suena..." << std::endl;
    }

    // Función inline
    inline int getTeclas() const { return teclas; }
    inline void setTeclas(int t) { teclas = t; }

    // Clase friend
    friend class AmigoClase;

private:
    int teclas;
};

// Clase AmigoClase que tiene acceso a los miembros privados y protegidos de Teclado
class AmigoClase {
public:
    void mostrarVoltaje(const Teclado& teclado) {
        std::cout << "Voltaje del teclado: " << teclado.voltaje << std::endl;
    }
};

#endif // INSTRUMENTOS_H
