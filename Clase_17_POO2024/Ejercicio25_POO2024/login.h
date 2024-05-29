#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QFont>
#include <QPushButton>

#include <label.h>
#include <ventana.h>
#include <admindb.h>
#include <admin.h>

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private:
    QGridLayout* layout;
    QLabel* lUsuario, *lPassword;
    QLineEdit* leUsuario, *lePassword;
    QPushButton* pbIngresar, *pbRegistrar;
    Ventana* ventana;
    AdminDB* admindb;

    Admin* crud;

private slots:
    void slot_registrar();
    void slot_ingresar();
    void slot_tree();

signals:
    void signal_go_to_tree();
};
#endif // LOGIN_H
