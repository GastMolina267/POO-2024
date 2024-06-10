// ventana.h

#ifndef VENTANA_H
#define VENTANA_H

#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

#include <QGroupBox>
#include <QVBoxLayout>

#include <QPainter>
#include <QImage>
#include <QPaintEvent>

#include <QPixmap>
#include <QScreen>

#include <QTimer>

#include <QDebug>

class Ventana : public QWidget {
    Q_OBJECT
private:
    QGroupBox* gbCaja;
    QVBoxLayout* boxLayout;

    QLabel* lImage, *lDiametro, *lVelocidad;
    QGridLayout* layout;
    QLineEdit* leDiametro, *leVelocidad;
    QPushButton* pbActualizar;

    QTimer* timer;

    int diametro = 100;
    int velocidad = 3000;
    int pos = 0; // -1 = alignleft | 0 = aligncenter | 1 = alignright

public:
    Ventana();

private slots:
    void slot_actualizar_bola();
    void slot_mover_bola();
};

#endif // VENTANA_H
