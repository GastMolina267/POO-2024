// login.h

#ifndef LOGIN_H
#define LOGIN_H

#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

#include <image.h>

class Login : public QWidget {
    Q_OBJECT
private:
    QLabel* lUsuario, *lClave;
    QLineEdit* leUsuario, *leClave;
    QPushButton* pbIngresar;
    QGridLayout* layout;
    Image* image;
    int counter = 0;

public:
    Login();

private slots:
    void slot_verificar_usuario();
};

#endif // LOGIN_H
