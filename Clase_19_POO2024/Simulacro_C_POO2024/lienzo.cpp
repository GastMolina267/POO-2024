#include "lienzo.h"
#include <QMouseEvent>

Lienzo::Lienzo(QWidget *parent, Grosor grosor)
    : QWidget(parent), m_dibujando(false), m_grosor(grosor) {
    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);
}

void Lienzo::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int grosor = 1;
    switch (m_grosor) {
    case TrazoMediano:
        grosor = 3;
        break;
    case TrazoGrueso:
        grosor = 5;
        break;
    }

    painter.setPen(QPen(Qt::black, grosor, Qt::SolidLine, Qt::RoundCap));

    // Dibujar líneas entre los puntos almacenados en m_points
    for (int i = 1; i < m_points.size(); ++i) {
        painter.drawLine(m_points[i - 1], m_points[i]);
    }

    QWidget::paintEvent(event);
}

void Lienzo::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_A) {
        m_dibujando = true;
    } else if (event->key() == Qt::Key_D) {
        m_dibujando = false;
        m_points.clear();
        update(); // Actualizar para borrar el dibujo
    }

    QWidget::keyPressEvent(event);
}

void Lienzo::mouseMoveEvent(QMouseEvent *event) {
    if (m_dibujando) {
        m_points.append(event->pos());
        update(); // Actualizar para dibujar la nueva línea
    }

    QWidget::mouseMoveEvent(event);
}

