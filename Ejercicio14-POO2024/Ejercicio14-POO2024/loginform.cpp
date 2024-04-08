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
    claveLineEdit->setEchoMode(QLineEdit::Password);

    //QString backgroundImage = "url('https://previews.123rf.com/images/jovanas/jovanas1602/jovanas160202216/52371701-s%C3%ADmbolo-de-clima-caliente-y-la-lluvia.jpg')";
    //setStyleSheet("QWidget { background-image: " + backgroundImage + "; background-repeat: no-repeat; background-position: center; }");

    loginButton = new QPushButton("Login");

    QLabel *labelClima = new QLabel("Temperatura:");
    QPushButton *weatherButton = new QPushButton("Mostrar Clima");

    labelTemperatura = new QLabel("N/A");

    layout = new QGridLayout(this);
    layout->addWidget(nombreLabel, 0, 0);
    layout->addWidget(usuarioLineEdit, 0, 1);
    layout->addWidget(claveLabel, 2, 0);
    layout->addWidget(claveLineEdit, 2, 1);
    layout->addWidget(loginButton, 4, 0, 1, 2);
    layout->addWidget(labelClima, 3, 0);
    layout->addWidget(labelTemperatura, 3, 1);
    layout->addWidget(weatherButton, 5, 0, 1, 2); // Agregar el botón de clima al diseño

    setLayout(layout);

    connect(loginButton, &QPushButton::clicked, this, &LoginForm::attemptLogin);
    connect(claveLineEdit, &QLineEdit::returnPressed, this, &LoginForm::attemptLogin);
    connect(usuarioLineEdit, &QLineEdit::returnPressed, this, &LoginForm::attemptLogin);
    connect(weatherButton, SIGNAL(clicked(bool)), this, SLOT(mostrarClima()));
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

