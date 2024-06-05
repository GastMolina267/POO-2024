#ifndef RECTANGULO_H
#define RECTANGULO_H

class Rectangulo {
public:
    Rectangulo(int x = 0, int y = 0, int ancho = 100, int alto = 100);

    int getX() const;
    int getY() const;
    int getAncho() const;
    int getAlto() const;

    void setX(int x);
    void setY(int y);
    void setAncho(int ancho);
    void setAlto(int alto);

private:
    int x;
    int y;
    int ancho;
    int alto;
};

#endif // RECTANGULO_H
