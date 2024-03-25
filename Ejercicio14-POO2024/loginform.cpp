#include "loginform.h"

LoginForm::LoginForm(QWidget *parent)
    : QWidget(parent)
{
    nombreLabel = new QLabel("Usuario:");
    claveLabel = new QLabel("Clave:");
    legajoLineEdit = new QLineEdit;
    usuarioLineEdit = new QLineEdit;
    apellidoLineEdit = new QLineEdit;
    claveLineEdit = new QLineEdit;
    loginButton = new QPushButton("Login");

    layout = new QGridLayout(this);
    layout->addWidget(nombreLabel, 0, 0);
    layout->addWidget(usuarioLineEdit, 0, 1);
    layout->addWidget(claveLabel, 2, 0);
    layout->addWidget(claveLineEdit, 2, 1);
    layout->addWidget(loginButton, 4, 0, 1, 2);

    connect(loginButton, &QPushButton::clicked, this, &LoginForm::attemptLogin);
    connect(claveLineEdit, &QLineEdit::returnPressed, this, &LoginForm::attemptLogin);
    connect(usuarioLineEdit, &QLineEdit::returnPressed, this, &LoginForm::attemptLogin);
}

void LoginForm::attemptLogin()
{
    QString usuario = usuarioLineEdit->text();
    QString clave = claveLineEdit->text();
    if (usuario == "admin" && clave == "1111") {
        emit loginSuccessful();
        close();
    } else {
        claveLineEdit->clear();
        emit loginFailed();
    }
}
