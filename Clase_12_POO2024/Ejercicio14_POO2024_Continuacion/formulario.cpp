#include "formulario.h"
#include "ui_formulario.h"

Formulario::Formulario(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Formulario)
{
    ui->setupUi(this);
}

Formulario::~Formulario()
{
    delete ui;
}

void Formulario::modificarlaSaludo(QString tipo)
{
    QString texto = "Hola ";
    texto.append(tipo);
    ui->label->setText(texto);
    this->setWindowTitle("Saludando a " + tipo);
}
