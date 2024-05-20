#include "login.h"
#include <QMessageBox>

Login::Login(QWidget *parent)
    : QWidget(parent)
{
    userLabel = new QLabel("Usuario:");
    passwordLabel = new QLabel("Contraseña:");
    userLineEdit = new QLineEdit;
    passwordLineEdit = new QLineEdit;
    passwordLineEdit->setEchoMode(QLineEdit::Password); // Oculta la contraseña
    loginButton = new QPushButton("Ingresar");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(userLabel);
    layout->addWidget(userLineEdit);
    layout->addWidget(passwordLabel);
    layout->addWidget(passwordLineEdit);
    layout->addWidget(loginButton);

    connect(loginButton, &QPushButton::clicked, this, &Login::attemptLogin);
}

void Login::attemptLogin()
{
    QString user = userLineEdit->text();
    QString password = passwordLineEdit->text();

    if (user == "admin" && password == "123") {
        QMessageBox::information(this, "Login exitoso", "¡Bienvenido!");
        // Aquí puedes abrir una nueva ventana o realizar cualquier otra acción
    } else {
        passwordLineEdit->clear(); // Limpiar la contraseña
        QMessageBox::warning(this, "Error de inicio de sesión", "Usuario o contraseña incorrectos.");
    }
}
