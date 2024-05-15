#ifndef PINTURA_H
#define PINTURA_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWheelEvent>
#include <QSlider>
#include <QPushButton>

class Pintura : public QWidget {
    Q_OBJECT

public:
    Pintura(QWidget *parent = nullptr);

signals:
    void colorChanged(const QColor &color);
    void sizeChanged(int size);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private slots:
    void on_sliderSize_valueChanged(int value);
    void on_btnClear_clicked();

private:
    struct Stroke {
        QPointF prevPos;
        QPointF currentPos;
        QColor color;
        int size;
    };

    QList<Stroke> m_strokes;
    Stroke m_currentStroke;
    QColor m_pincelColor;
    int m_pincelSize;

    QSlider *m_sliderSize;
    QPushButton *m_btnClear;

    void drawStroke(const QPointF &prevPos, const QPointF &currentPos);
};

#endif // PINTURA_H

