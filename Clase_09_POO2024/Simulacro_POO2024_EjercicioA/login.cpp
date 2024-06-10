// login.cpp

#include <login.h>

Login::Login() {
    QWidget::setWindowTitle("Login");
    QWidget::setFixedWidth(250);
    QWidget::setFixedHeight(120);

    lUsuario = new QLabel("Usuario:");
    lClave = new QLabel("Clave:");
    leUsuario = new QLineEdit;
    leClave = new QLineEdit;
    pbIngresar = new QPushButton("Ingresar");
    layout = new QGridLayout;

    leClave->setEchoMode(QLineEdit::Password);
    pbIngresar->setDefault(true);

    layout->addWidget(lUsuario, 0, 0, 1, 1);
    layout->addWidget(leUsuario, 0, 1, 1, 1);
    layout->addWidget(lClave, 1, 0, 1, 1);
    layout->addWidget(leClave, 1, 1, 1, 1);
    layout->addWidget(pbIngresar, 2, 2, 1, 1);

    this->setLayout(layout);

    connect(pbIngresar, SIGNAL(clicked(bool)), this, SLOT(slot_verificar_usuario()));
    connect(leUsuario, &QLineEdit::returnPressed, pbIngresar, &QPushButton::click);
    connect(leClave, &QLineEdit::returnPressed, pbIngresar, &QPushButton::click);
}

void Login::slot_verificar_usuario() {
    if (leUsuario->text() == "45.094.160" && leClave->text() == "160") {
        image = new Image();
        image->show();
        this->hide();
    } else {
        counter++;
        leClave->setText(NULL);
        if (counter == 3) {
            QApplication::quit();
        }
    }
}
