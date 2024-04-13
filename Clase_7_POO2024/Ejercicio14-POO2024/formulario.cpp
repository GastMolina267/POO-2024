#include "formulario.h"
#include <QRandomGenerator>

Formulario::Formulario(QWidget *parent)
    : QWidget(parent)
{
    nombreLabel = new QLabel("Nombre:");
    apellidoLabel = new QLabel("Apellido:");
    claveLabel = new QLabel("Clave:");
    cedulaLabel = new QLabel("Cédula:");
    nombreLineEdit = new QLineEdit;
    apellidoLineEdit = new QLineEdit;
    claveLineEdit = new QLineEdit;
    cedulaLineEdit = new QLineEdit;
    cedulaLineEdit->setReadOnly(true); // Hacer el campo de cédula de solo lectura

    // Autocompletar la cédula con un número aleatorio entre 1 y 1000
    int cedulaAleatoria = QRandomGenerator::global()->bounded(1, 1001);
    cedulaLineEdit->setText(QString::number(cedulaAleatoria));

    guardarButton = new QPushButton("Guardar");

    layout = new QGridLayout(this);
    layout->addWidget(nombreLabel, 0, 0);
    layout->addWidget(nombreLineEdit, 0, 1);
    layout->addWidget(apellidoLabel, 1, 0);
    layout->addWidget(apellidoLineEdit, 1, 1);
    layout->addWidget(claveLabel, 2, 0);
    layout->addWidget(claveLineEdit, 2, 1);
    layout->addWidget(cedulaLabel, 3, 0);
    layout->addWidget(cedulaLineEdit, 3, 1);
    layout->addWidget(guardarButton, 4, 0, 1, 2);

    connect(guardarButton, &QPushButton::clicked, this, &Formulario::saveData);
}

void Formulario::saveData()
{
    QString nombre = nombreLineEdit->text();
    QString apellido = apellidoLineEdit->text();
    QString clave = claveLineEdit->text();
    QString cedula = cedulaLineEdit->text();

    // Verificar si todos los campos están completos
    if (!nombre.isEmpty() && !apellido.isEmpty() && !clave.isEmpty() && !cedula.isEmpty()) {
        QMessageBox::information(this, "Ingreso de datos correcto", "Ingreso de datos correctamente, cliente dado de alta.");
        close();
    } else {
        QMessageBox::warning(this, "Campos incompletos", "Por favor, complete todos los campos antes de guardar.");
    }
}
