#include "formulario.h"
#include <QRandomGenerator>

Formulario::Formulario(QWidget *parent)
    : QWidget(parent)
{
    nombreLabel = new QLabel("Nombre:");
    apellidoLabel = new QLabel("Apellido:");
    cedulaLabel = new QLabel("Legajo:");
    nombreLineEdit = new QLineEdit;
    apellidoLineEdit = new QLineEdit;
    cedulaLineEdit = new QLineEdit;
    cedulaLineEdit->setReadOnly(true);
    // Autocompletar el Legajo con un número aleatorio entre 1 y 1000
    int cedulaAleatoria = QRandomGenerator::global()->bounded(1, 1001);
    cedulaLineEdit->setText(QString::number(cedulaAleatoria));

    guardarButton = new QPushButton("Guardar");

    layout = new QGridLayout(this);
    layout->addWidget(nombreLabel, 0, 0);
    layout->addWidget(nombreLineEdit, 0, 1);
    layout->addWidget(apellidoLabel, 1, 0);
    layout->addWidget(apellidoLineEdit, 1, 1);
    layout->addWidget(cedulaLabel, 2, 0);
    layout->addWidget(cedulaLineEdit, 2, 1);
    layout->addWidget(guardarButton, 4, 0, 1, 2);

    connect(guardarButton, &QPushButton::clicked, this, &Formulario::saveData);
}

void Formulario::saveData()
{
    QString nombre = nombreLineEdit->text();
    QString apellido = apellidoLineEdit->text();
    QString cedula = cedulaLineEdit->text();

    // Verificar si todos los campos están completos
    if (!nombre.isEmpty() && !apellido.isEmpty() && !cedula.isEmpty()) {
        QMessageBox::information(this, "Ingreso de datos correcto", "Ingreso de datos correctamente, cliente dado de alta.");
        close();
    } else {
        QMessageBox::warning(this, "Campos incompletos", "Por favor, complete todos los campos antes de guardar.");
    }
}
