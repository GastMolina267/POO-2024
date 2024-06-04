#include "formulario.h"
#include "ui_formulario.h"

Formulario::Formulario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Formulario) {
    ui->setupUi(this);

    ui->cbInstrumento->addItem("Guitarra");
    ui->cbInstrumento->addItem("Viento");
    ui->cbInstrumento->addItem("Teclado");

    connect(ui->btnAgregar, &QPushButton::clicked, this, &Formulario::on_btnAgregar_clicked);
    connect(ui->btnVerStock, &QPushButton::clicked, this, &Formulario::on_btnVerStock_clicked);
    connect(ui->cbInstrumento, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Formulario::on_cbInstrumento_currentIndexChanged);
}

Formulario::~Formulario() {
    delete ui;
    qDeleteAll(instrumentos);  // Liberar memoria de instrumentos
}

void Formulario::on_btnAgregar_clicked() {
    QString marca = ui->leMarca->text();
    float precio = ui->lePrecio->text().toFloat();

    int index = ui->cbInstrumento->currentIndex();
    switch (index) {
    case 0: { // Guitarra
        int cantidad_de_cuerdas = ui->leCantidadDeCuerdas->text().toInt();
        instrumentos.push_back(new Guitarra(marca, precio, cantidad_de_cuerdas));
        break;
    }
    case 1: { // Viento
        QString metal_usado = ui->leMetalUsado->text();
        instrumentos.push_back(new Viento(marca, precio, metal_usado));
        break;
    }
    case 2: { // Teclado
        int cantidad_de_teclas = ui->leCantidadDeTeclas->text().toInt();
        instrumentos.push_back(new Teclado(marca, precio, cantidad_de_teclas));
        break;
    }
    }

    // Limpiar campos después de agregar
    ui->leMarca->clear();
    ui->lePrecio->clear();
    ui->leCantidadDeCuerdas->clear();
    ui->leMetalUsado->clear();
    ui->leCantidadDeTeclas->clear();
}

void Formulario::on_btnVerStock_clicked() {
    for (const auto& instrumento : instrumentos) {
        instrumento->afinar();
    }
}

void Formulario::on_cbInstrumento_currentIndexChanged(int index) {
    // Ocultar todos los campos inicialmente
    ui->leCantidadDeCuerdas->setVisible(false);
    ui->leMetalUsado->setVisible(false);
    ui->leCantidadDeTeclas->setVisible(false);

    switch (index) {
    case 0: // Guitarra
        ui->leCantidadDeCuerdas->setVisible(true);
        break;
    case 1: // Viento
        ui->leMetalUsado->setVisible(true);
        break;
    case 2: // Teclado
        ui->leCantidadDeTeclas->setVisible(true);
        break;
    }
}
