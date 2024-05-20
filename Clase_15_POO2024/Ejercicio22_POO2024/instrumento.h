#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <QString>
#include <QDebug>

class Instrumento {
public:
    Instrumento(const QString& marca = "Yamaha") : marca(marca) {}
    virtual ~Instrumento() = default;
    virtual void sonar() const = 0;
    virtual void verlo() const {
        qDebug() << "Marca:" << marca;
    }
protected:
    QString marca;
};

#endif // INSTRUMENTO_H
