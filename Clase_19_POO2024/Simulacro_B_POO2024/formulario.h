#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QVector>
#include "instrumento.h"
#include "guitarra.h"
#include "viento.h"
#include "teclado.h"

namespace Ui {
class Formulario;
}

class Formulario : public QWidget {
    Q_OBJECT

public:
    explicit Formulario(QWidget *parent = nullptr);
    ~Formulario();

private slots:
    void on_btnAgregar_clicked();
    void on_btnVerStock_clicked();
    void on_cbInstrumento_currentIndexChanged(int index);

private:
    Ui::Formulario *ui;
    QVector<Instrumento*> instrumentos;
};

#endif // FORMULARIO_H
