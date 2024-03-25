#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    LoginForm(QWidget *parent = nullptr);

signals:
    void loginSuccessful();
    void loginFailed();

private slots:
    void attemptLogin();

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
    QGridLayout *layout;
};

#endif // LOGINFORM_H
