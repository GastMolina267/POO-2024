#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>

namespace Ui {
class Formulario;
}

class Formulario : public QWidget
{
    Q_OBJECT

public:
    explicit Formulario(QWidget *parent = nullptr);
    void modificarlaSaludo();
    ~Formulario();

private:
    Ui::Formulario *ui;

private slots:
    void slot_emit_return();

signals:
    void signal_volver_login();
};

#endif // FORMULARIO_H
