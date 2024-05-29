#include <mapa.h>

Mapa::Mapa(QImage* im) {
    img = im;
}

void Mapa::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    QImage image(*img);
    painter.drawImage(0, 0, image);
}
