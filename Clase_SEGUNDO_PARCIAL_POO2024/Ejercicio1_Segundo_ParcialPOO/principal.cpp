#include "principal.h"
#include "ui_principal.h"
#include <QPainter>

Principal::Principal(QWidget *parent)
    : QWidget(parent), ui(new Ui::Principal) {
    ui->setupUi(this);
    setFixedSize(300, 300);

    AdminDB& db = AdminDB::getInstance();
    if (db.conectar("C:/Users/marin/OneDrive/Imágenes/Documentos/rectangles.db")) {
        rectangulos = db.selectRectangulos();
        qDebug() << "Rectángulos cargados:" << rectangulos.size();
        for (const auto& rect : rectangulos) {
            qDebug() << "Rectángulo -" << "x:" << rect.getX() << "y:" << rect.getY() << "ancho:" << rect.getAncho() << "alto:" << rect.getAlto();
        }
    } else {
        qDebug() << "Error al conectar con la base de datos.";
    }
}

Principal::~Principal() {
    delete ui;
}

void Principal::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    qDebug() << "Paint event called"; // Mensaje de depuración
    for (const Rectangulo& rect : rectangulos) {
        qDebug() << "Dibujando rectángulo -" << "x:" << rect.getX() << "y:" << rect.getY() << "ancho:" << rect.getAncho() << "alto:" << rect.getAlto(); // Mensaje de depuración
        painter.drawRect(rect.getX(), rect.getY(), rect.getAncho(), rect.getAlto());
    }
}
