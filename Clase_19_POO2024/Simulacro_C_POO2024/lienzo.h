#ifndef LIENZO_H
#define LIENZO_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>

// Enumeración para el grosor del trazo
enum Grosor {
    TrazoFino,
    TrazoMediano,
    TrazoGrueso
};

class Lienzo : public QWidget {
    Q_OBJECT

public:
    explicit Lienzo(QWidget *parent = nullptr, Grosor grosor = TrazoFino);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    bool m_dibujando;
    QList<QPoint> m_points;
    Grosor m_grosor;
};

#endif // LIENZO_H

