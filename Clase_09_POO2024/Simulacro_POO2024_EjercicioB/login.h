#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);

private slots:
    void attemptLogin();

private:
    QLabel *userLabel;
    QLabel *passwordLabel;
    QLineEdit *userLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;
};

#endif // LOGIN_H

