#include "ventana.h"
#include <QMessageBox>

Ventana::Ventana(QWidget *parent)
    : QWidget{parent}
{
    layout = new QGridLayout();

    lUsuario = new QLabel("Usuario:");
    lPassword = new QLabel("Password:");
    lNombre = new QLabel("Nombre:");
    lApellido = new QLabel("Apellido:");
    pbRegistrar = new QPushButton("Registrarse");

    QFont* font = new QFont();
    font->setBold(true);
    font->setCapitalization(font->AllUppercase);
    font->setPixelSize(12);

    lUsuario->setFont(*font);
    lPassword->setFont(*font);
    lNombre->setFont(*font);
    lApellido->setFont(*font);
    pbRegistrar->setFont(*font);

    leUsuario = new QLineEdit();
    leUsuario->setPlaceholderText("Su Nuevo Usuario");
    lePassword = new QLineEdit();
    lePassword->setPlaceholderText("Su Nueva Password");
    lePassword->setEchoMode(QLineEdit::Password);
    leNombre = new QLineEdit();
    leNombre->setPlaceholderText("Su Nombre");
    leApellido = new QLineEdit();
    leApellido->setPlaceholderText("Su Apellido");

    layout->addWidget(lUsuario, 0, 0, 1, 1);
    layout->addWidget(leUsuario, 0, 1, 1, 1);
    layout->addWidget(lPassword, 1, 0, 1, 1);
    layout->addWidget(lePassword, 1, 1, 1, 1);
    layout->addWidget(lNombre, 2, 0, 1, 1);
    layout->addWidget(leNombre, 2, 1, 1, 1);
    layout->addWidget(lApellido, 3, 0, 1, 1);
    layout->addWidget(leApellido, 3, 1, 1, 1);
    layout->addWidget(pbRegistrar, 4, 0, 1, 2);

    this->setLayout(layout);

    connect(pbRegistrar, SIGNAL(clicked(bool)), this, SLOT(slot_registrarse()));
}

void Ventana::slot_registrarse() {
    admindb = new AdminDB();
    if (admindb->conectar("C:/Users/marin/OneDrive/Imágenes/Documentos/db.sqlite") == true) {
        if (leUsuario->text() != "" && lePassword->text() != "" && leNombre->text() != "" && leApellido->text() != "") {
            if (admindb->existeUsuario("usuarios", leUsuario->text()) == true) {
                qDebug() << "Ya existe el Usuario. Intente con otro Usuario";
                QMessageBox::warning(this, "Ingreso Repetido", "El usuario ingresado YA existe!");
                leUsuario->setText("");
                lePassword->setText("");
            } else {
                qDebug() << "Exito en el Registro!";
                QMessageBox::information(this, "Ingreso Éxitos", "Ingreso de usuario correctamente!");
                admindb->ingresarUsuario("usuarios", leUsuario->text(), lePassword->text(), leNombre->text(), leApellido->text());
                this->close();
            }
        } else {
            qDebug() << "Alguno de los Datos requeridos esta Vacio";
            QMessageBox::warning(this, "Datos incompletos", "Complete TODOS los campos");
        }
    } else {
        qDebug() << "No se pudo conectar a la DB";
        QMessageBox::warning(this, "Erro DB", "No se pudo conectar a la DB!");
    }
}
