#include <QApplication>
#include <QMessageBox>
#include "loginform.h"
#include "formulario.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginForm login;
    Formulario formulario;

    //login.setBackgroundImage(backgroundImage); // Ruta de la imagen de fondo

    // Conectar los slots de éxito y falla del loginForm
    QObject::connect(&login, &LoginForm::loginSuccessful, [&]() {
        QMessageBox::information(nullptr, "Ingreso exitoso", "Ingreso exitoso como administrador.");
        formulario.show();
    });

    QObject::connect(&login, &LoginForm::loginFailed, [&]() {
        QMessageBox::warning(nullptr, "Error de inicio de sesión", "Usuario o clave incorrectos.");
    });

    login.show();

    return a.exec();
}
