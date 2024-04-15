#include "loginform.h"

LoginForm::LoginForm(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    usernameLineEdit = new QLineEdit(this);
    usernameLineEdit->setPlaceholderText("Usuario");

    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setPlaceholderText("Contraseña");
    passwordLineEdit->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("Ingresar", this);

    layout->addWidget(usernameLineEdit);
    layout->addWidget(passwordLineEdit);
    layout->addWidget(loginButton);

    connect(loginButton, &QPushButton::clicked, this, &LoginForm::attemptLogin);
}

void LoginForm::attemptLogin()
{
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();

    if (username == "admin" && password == "123")
    {
        Editor *editor = new Editor;
        editor->show();
        close();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Usuario o contraseña incorrectos.");
    }
}
