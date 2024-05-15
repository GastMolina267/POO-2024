#include "pintura.h"

Pintura::Pintura(QWidget *parent)
    : QWidget(parent), m_pincelColor(Qt::black), m_pincelSize(5)
{
    setMouseTracking(true);
    setFocusPolicy(Qt::StrongFocus);

    // Crear controles de la interfaz
    m_sliderSize = new QSlider(Qt::Horizontal, this);
    m_sliderSize->setRange(1, 100); // Rango del tamaño del pincel
    m_sliderSize->setValue(m_pincelSize); // Valor inicial
    connect(m_sliderSize, SIGNAL(valueChanged(int)), this, SLOT(on_sliderSize_valueChanged(int)));

    m_btnClear = new QPushButton("Borrar", this);
    connect(m_btnClear, SIGNAL(clicked()), this, SLOT(on_btnClear_clicked()));

    // Posicionamiento de los controles
    m_sliderSize->move(10, 10);
    m_btnClear->move(10, 50);
}

void Pintura::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(rect(), Qt::white);

    for (const auto &stroke : m_strokes) {
        // Utilizar m_pincelSize en lugar de strokeSize
        painter.setPen(QPen(stroke.color, m_pincelSize, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter.drawLine(stroke.prevPos, stroke.currentPos);
    }
    QWidget::paintEvent(event);
}

void Pintura::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_currentStroke.prevPos = event->pos();
        m_currentStroke.currentPos = event->pos();
        m_currentStroke.color = m_pincelColor; // Almacenar el color actual del pincel
        m_strokes.append(m_currentStroke); // Agregar el trazo a la lista de trazos
        update();
    }
    QWidget::mousePressEvent(event);
}

void Pintura::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        m_currentStroke.prevPos = m_currentStroke.currentPos;
        m_currentStroke.currentPos = event->pos();
        m_strokes.append(m_currentStroke);
        update();
    }
    QWidget::mouseMoveEvent(event);
}

void Pintura::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_G) {
        // Cambiar el color del pincel al verde
        m_pincelColor = Qt::green;
        emit colorChanged(Qt::green);
    }
    if (event->key() == Qt::Key_R) {
        // Cambiar el color del pincel al rojo
        m_pincelColor = Qt::red;
        emit colorChanged(Qt::red);
    }
    if (event->key() == Qt::Key_B) {
        // Cambiar el color del pincel al azul
        m_pincelColor = Qt::blue;
        emit colorChanged(Qt::blue);
    }
    if (event->key() == Qt::Key_N) {
        // Cambiar el color del pincel al azul
        m_pincelColor = Qt::black;
        emit colorChanged(Qt::black);
    }
    if (event->key() == Qt::Key_Escape) {
        m_strokes.clear();
        update();
    }
    QWidget::keyPressEvent(event);
}

void Pintura::wheelEvent(QWheelEvent *event) {
    int delta = event->angleDelta().y();
    int newSize = m_pincelSize + (delta / 120); // 120 is the default step of the wheel
    if (newSize > 0 && newSize < 100) {
        m_pincelSize = newSize;
        emit sizeChanged(newSize);
    }
    QWidget::wheelEvent(event);
}

void Pintura::on_sliderSize_valueChanged(int value) {
    m_pincelSize = value;
    emit sizeChanged(value);
}

void Pintura::on_btnClear_clicked() {
    m_strokes.clear();
    update();
}

void Pintura::drawStroke(const QPointF &prevPos, const QPointF &currentPos) {
    QPainter painter(this);
    painter.setPen(QPen(m_pincelColor, m_pincelSize, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawLine(prevPos, currentPos);
}
