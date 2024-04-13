#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QGridLayout>
#include <QMessageBox>
#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTimer>
#include "weather.h"

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    LoginForm(QWidget *parent = nullptr);
    void actualizarTemperatura(const QString &temperatura);

signals:
    void loginSuccessful();
    void loginFailed();
    void climaRequested(const QString &ciudad); // Nueva señal para solicitar el clima

private slots:
    void attemptLogin();
    void mostrarClima();
    void setBackgroundImage(const QString &imageUrl); // Nuevo método para establecer la imagen de fondo
    void unblockUser();
    void updateBlockTimer(); // Nuevo slot para actualizar el temporizador de bloqueo

private:
    QLabel *legajoLabel;
    QLabel *nombreLabel;
    QLabel *apellidoLabel;
    QLabel *claveLabel;
    QLineEdit *legajoLineEdit;
    QLineEdit *usuarioLineEdit;
    QLineEdit *apellidoLineEdit;
    QLineEdit *claveLineEdit;
    QPushButton *loginButton;
    QPushButton *weatherButton; // Nuevo botón para solicitar el clima
    QGridLayout *layout;
    QLabel *labelTemperatura;
    QLabel *blockTimerLabel; // Etiqueta para mostrar el tiempo restante de bloqueo
    QString backgroundImage;
    Weather weather;
    QTimer *blockTimer; // Temporizador para desbloquear al usuario después de 5 minutos
    int loginAttempts;
    bool isBlocked;
};

#endif // LOGINFORM_H

