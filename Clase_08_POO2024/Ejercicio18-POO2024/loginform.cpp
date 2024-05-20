#include "loginform.h"
#include "HTMLWindow.h"

LoginForm::LoginForm(QWidget *parent)
    : QWidget(parent),
    loginAttempts(0),
    isBlocked(false)
{
    nombreLabel = new QLabel("Usuario:");
    claveLabel = new QLabel("Clave:");
    legajoLineEdit = new QLineEdit;
    usuarioLineEdit = new QLineEdit;
    apellidoLineEdit = new QLineEdit;
    claveLineEdit = new QLineEdit;
    claveLineEdit->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("Login");

    QLabel *labelClima = new QLabel("Temperatura:");
    QPushButton *weatherButton = new QPushButton("Mostrar Clima");

    labelTemperatura = new QLabel("N/A");
    blockTimerLabel = new QLabel("Tiempo restante de bloqueo: 00:00");

    blockTimer = new QTimer(this);
    connect(blockTimer, &QTimer::timeout, this, &LoginForm::updateBlockTimer);
    blockTimer->start(1000); // Iniciar el temporizador con un intervalo de 1 segundo

    layout = new QGridLayout(this);
    layout->addWidget(nombreLabel, 0, 0);
    layout->addWidget(usuarioLineEdit, 0, 1);
    layout->addWidget(claveLabel, 2, 0);
    layout->addWidget(claveLineEdit, 2, 1);
    layout->addWidget(loginButton, 4, 0, 1, 2);
    layout->addWidget(labelClima, 3, 0);
    layout->addWidget(labelTemperatura, 3, 1);
    layout->addWidget(weatherButton, 5, 0, 1, 2); // Agregar el botón de clima al diseño
    layout->addWidget(blockTimerLabel, 6, 0, 1, 2); // Agregar la etiqueta del temporizador de bloqueo

    setLayout(layout);

    connect(loginButton, &QPushButton::clicked, this, &LoginForm::attemptLogin);
    connect(claveLineEdit, &QLineEdit::returnPressed, this, &LoginForm::attemptLogin);
    connect(usuarioLineEdit, &QLineEdit::returnPressed, this, &LoginForm::attemptLogin);
    connect(weatherButton, SIGNAL(clicked(bool)), this, SLOT(mostrarClima()));
    blockTimer = new QTimer(this);
    connect(blockTimer, &QTimer::timeout, this, &LoginForm::unblockUser);
    connect(blockTimer, &QTimer::timeout, this, &LoginForm::updateBlockTimer); // Conectar el temporizador de bloqueo con el slot de actualización
}

void LoginForm::attemptLogin()
{
    if (isBlocked) {
        QMessageBox::warning(this, "Error de inicio de sesión", "El usuario está bloqueado. Inténtelo de nuevo más tarde.");
        return;
    }

    QString usuario = usuarioLineEdit->text();
    QString clave = claveLineEdit->text();

    if (usuario == "admin" && clave == "1234") {
        HTMLWindow *htmlWindow = new HTMLWindow;
        htmlWindow->show();
        emit loginSuccessful();
        close();
    } else {
        loginAttempts++;
        if (loginAttempts >= 3) {
            isBlocked = true;
            blockTimer->start(300000); // Bloquear al usuario durante 5 minutos (300,000 ms)
            QMessageBox::warning(this, "Error de inicio de sesión", "Usuario o clave incorrectos. El usuario ha sido bloqueado durante 5 minutos.");
            updateBlockTimer(); // Actualizar la etiqueta del temporizador de bloqueo
        } else {
            QMessageBox::warning(this, "Error de inicio de sesión", "Usuario o clave incorrectos. Intento fallido número " + QString::number(loginAttempts));
        }
    }
}

void LoginForm::mostrarClima() {
    labelTemperatura->setVisible(!labelTemperatura->isVisible());
    if (labelTemperatura->isVisible()) {
        emit climaRequested("Cordoba"); // Cambia "Cordoba" por la ciudad de tu elección
    }
}

void LoginForm::setBackgroundImage(const QString &imageUrl)
{
    QPixmap background(imageUrl);
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(palette);
    this->setAutoFillBackground(true);
}

void LoginForm::actualizarTemperatura(const QString &temperatura) {
    labelTemperatura->setText(temperatura);
}

void LoginForm::unblockUser()
{
    isBlocked = false;
    blockTimer->stop();
    blockTimerLabel->setText("El usuario ha sido desbloqueado.");
    QMessageBox::information(this, "Usuario desbloqueado", "El usuario ha sido desbloqueado después de 5 minutos.");
    loginAttempts = 0;
}

void LoginForm::updateBlockTimer()
{
    int remainingTime = blockTimer->remainingTime(); // Obtener el tiempo restante en milisegundos
    if (remainingTime > 0) {
        int seconds = remainingTime / 1000; // Convertir a segundos
        int minutes = seconds / 60; // Calcular los minutos
        seconds %= 60; // Obtener los segundos restantes

        QString timeString = QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
        blockTimerLabel->setText("Tiempo restante de bloqueo: " + timeString);
    } else {
        blockTimerLabel->setText("Usuario desbloqueado.");
    }
}
