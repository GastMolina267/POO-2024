#include "login.h"
#include <QMessageBox>

Login::Login(QWidget *parent)
    : QWidget(parent)
{
    layout = new QGridLayout();

    lUsuario = new QLabel ("Usuario:");
    lPassword = new QLabel("Password:");
    pbIngresar = new QPushButton("Ingresar");
    pbRegistrar = new QPushButton("Registrar");

    QFont* font = new QFont();
    font->setBold(true);
    font->setCapitalization(font->AllUppercase);
    font->setPixelSize(12);

    lUsuario->setFont(*font);
    lPassword->setFont(*font);
    pbIngresar->setFont(*font);
    pbRegistrar->setFont(*font);

    leUsuario = new QLineEdit();
    lePassword = new QLineEdit();
    lePassword->setEchoMode(QLineEdit::Password);

    leUsuario->setPlaceholderText("Ingresar Usuario");
    lePassword->setPlaceholderText("Ingresar Password");

    layout->addWidget(lUsuario, 0, 0, 1, 1);
    layout->addWidget(leUsuario, 0, 1, 1, 1);
    layout->addWidget(lPassword, 1, 0, 1, 1);
    layout->addWidget(lePassword, 1, 1, 1, 1);
    layout->addWidget(pbIngresar, 2, 1, 1, 1);
    layout->addWidget(pbRegistrar, 3, 1, 1, 1);

    this->setLayout(layout);

    connect(pbIngresar, SIGNAL(clicked(bool)), this, SLOT(slot_ingresar()));
    connect(pbRegistrar, SIGNAL(clicked(bool)), this, SLOT(slot_registrar()));
    connect(this, SIGNAL(signal_go_to_tree()), this, SLOT(slot_tree()));
}

Login::~Login() {}

void Login::slot_ingresar() {
    admindb = new AdminDB( this );
    if (admindb->conectar("C:/Users/marin/OneDrive/Imágenes/Documentos/db.sqlite") == true) {
        if (admindb->validarUsuario( "usuarios", leUsuario->text(), lePassword->text()))  {
            qDebug() << "Exito Ingresando con el Usuario!";
            QMessageBox::information(this, "Ingreso Éxitos", "Ingreso de usuario correctamente!");
            emit signal_go_to_tree();
        }
        else  {
            qDebug() << "Algo ha ido mal en el Ingreso.";
            QMessageBox::information(this, "Error al ingresar", "Ocurrió un error al intentar ingresar");
            lePassword->setText("");
        }
    } else {
        qDebug() << "No se pudo conectar a la DB";
    }
}

void Login::slot_registrar() {
    ventana = new Ventana();
    this->close();
    ventana->show();
}

void Login::slot_tree() {
    crud = new Admin();
    this->hide();
}
