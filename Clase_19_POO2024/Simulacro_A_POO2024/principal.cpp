#include "principal.h"
#include "ui_principal.h"
#include <QPainter>

Principal::Principal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Principal)
    , db(new AdminDB)
    , linea(nullptr)
{
    ui->setupUi(this);
    cargarDatos();
}

Principal::~Principal()
{
    delete ui;
    delete db;
    delete linea;
}

void Principal::cargarDatos()
{
    linea = db->obtenerLinea();
    if (!linea) {
        qDebug() << "No se pudo cargar la línea desde la base de datos.";
    }
}

void Principal::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    if (linea) {
        QPainter painter(this);
        painter.drawLine(linea->getXInicial(), linea->getYInicial(), linea->getXFinal(), linea->getYFinal());
    }
}
