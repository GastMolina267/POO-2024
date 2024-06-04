// ui_form.cpp
#include "ui_form.h"
#include "form.h"

Form::Form(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form() {
    delete ui;
}

void Form::show() {
    QString texto = "Hola ";
    ui->label->setText(texto);
    this->setWindowTitle("Bienvenido");
}
