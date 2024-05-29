#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QFont>
#include <QPushButton>
#include <QDebug>

#include <admindb.h>

class Ventana : public QWidget
{
    Q_OBJECT
public:
    explicit Ventana(QWidget *parent = nullptr);

private:
    QGridLayout* layout;
    QLabel* lUsuario, *lPassword, *lNombre, *lApellido, *lEmail;
    QLineEdit* leUsuario, *lePassword, *leNombre, *leApellido, *leEmail;
    QPushButton* pbRegistrar;
    AdminDB* admindb;

private slots:
    void slot_registrarse();
};

#endif // VENTANA_H
