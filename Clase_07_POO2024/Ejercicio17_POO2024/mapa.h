#ifndef MAPA_H
#define MAPA_H

#include <QWidget>
#include <QPainter>
#include <QImage>

class Mapa : public QWidget {
    Q_OBJECT
private:
    QImage* img;
public:
    Mapa(QImage* im);
protected:
    void paintEvent(QPaintEvent*);
};

#endif // MAPA_H
