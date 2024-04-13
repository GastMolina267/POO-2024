#include <QApplication>
#include <QMessageBox>
#include "loginform.h"
#include "formulario.h"
#include "weather.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginForm login;
    Formulario formulario;

    Weather weather;

    //login.setBackgroundImage(backgroundImage); // Ruta de la imagen de fondo

    // Conectar el botón de clima de LoginForm con el método mostrarClima
    QObject::connect(&login, &LoginForm::climaRequested, &weather, &Weather::obtenerTemperatura);

    QObject::connect(&weather, &Weather::climaObtenido, &login, &LoginForm::actualizarTemperatura);

    // Conectar los slots de éxito y falla del loginForm
    QObject::connect(&login, &LoginForm::loginSuccessful, [&]() {
        QMessageBox::information(nullptr, "Ingreso exitoso", "Ingreso exitoso como administrador.");
        formulario.show();
    });

    QObject::connect(&login, &LoginForm::loginFailed, [&]() {
        QMessageBox::warning(nullptr, "Error de inicio de sesión", "Usuario o clave incorrectos.");
    });

    login.show();

    qInfo() << QSslSocket::sslLibraryVersionString();
    qInfo() << QSslSocket::sslLibraryBuildVersionNumber();
    qInfo() << QSslSocket::sslLibraryBuildVersionString();
    qInfo() << QSslSocket::sslLibraryVersionNumber();

    return a.exec();
}
