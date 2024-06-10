#ifndef GALERIAFOTOS_H
#define GALERIAFOTOS_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVector>

class GaleriaFotos : public QMainWindow {
    Q_OBJECT

public:
    GaleriaFotos(QWidget *parent = nullptr);

private slots:
    void avanzar();
    void retroceder();


private:
    QLabel *imagenLabel;
    QPushButton *avanzarButton;
    QPushButton *retrocederButton;
    QVector<QString> urls;
    QLineEdit *urlLineEdit;
    int indiceActual;
};

#endif // GALERIAFOTOS_H
