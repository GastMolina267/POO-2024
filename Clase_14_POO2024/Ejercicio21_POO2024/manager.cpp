#include "manager.h"

Manager::Manager(QObject *parent)
    : QObject{parent}
{
    login = new Login();
    reg = new Registro();
    form = new Formulario();
    login->show();
    QObject::connect(login, SIGNAL(signal_go_to_registry()), this, SLOT(slot_go_to_registry()));
    QObject::connect(reg, SIGNAL(signal_go_to_login()), this, SLOT(slot_go_to_login()));
    QObject::connect(login, SIGNAL(signal_logging_in()), this, SLOT(slot_go_to_form()));
    QObject::connect(form, SIGNAL(signal_volver_login()), this, SLOT(slot_go_to_login()));
}

void Manager::slot_go_to_registry() {
    reg->show();
}

void Manager::slot_go_to_login() {
    login->show();
}

void Manager::slot_go_to_form() {
    form->show();
    form->modificarlaSaludo();
}
