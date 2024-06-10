#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ventana)
{
    ui->setupUi(this);
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::set_user(QString nom) {
    if (nom == "admin") {
        ui->lSaludo->setText("Hola ADMIN");
    } else {
        ui->lSaludo->setText("Hola USER");
    }
}
