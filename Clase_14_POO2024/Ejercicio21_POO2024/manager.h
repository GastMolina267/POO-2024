#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>

#include <login.h>
#include <registro.h>
#include <formulario.h>

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);

private:
    Login* login;
    Registro* reg;
    Formulario* form;

private slots:
    void slot_go_to_login();
    void slot_go_to_registry();
    void slot_go_to_form();
};

#endif // MANAGER_H
