#include "admin.h"
#include "ui_admin.h"
#include <QMessageBox>

Admin::Admin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Admin)
{
    ui->setupUi(this);
    this->setWindowTitle("Base_de_Datos");
    admindb = new AdminDB();
    query = get_data();
    display_tree();

    this->show();
    qDebug() << this->width() << this->height();
}

Admin::~Admin()
{
    delete ui;
}

void Admin::display_tree() {
    ui->tree->setColumnCount(5);

    QStringList headers;
    headers << "ID" << "Usuario" << "Clave" << "Nombre" << "Apellido";
    ui->tree->setHeaderLabels(headers);

    while (query.next()) {
        QTreeWidgetItem* item = new QTreeWidgetItem();
        qDebug() << query.value(0).toString() << query.value(1).toString() << query.value(2).toString() << query.value(3).toString() << query.value(4).toString();
        item->setText(0, query.value(0).toString());
        item->setText(1, query.value(1).toString());
        item->setText(2, query.value(2).toString());
        item->setText(3, query.value(3).toString());
        item->setText(4, query.value(4).toString());
        qDebug() << "Procesando...";
        item->setFlags(item->flags() | Qt::ItemIsEditable);
        ui->tree->addTopLevelItem(item);
    }
    QMessageBox::information(this, "Procesando datos", "Procesando...");
}

QSqlQuery Admin::get_data() {
    if (admindb->conectar("C:/Users/marin/OneDrive/Imágenes/Documentos/db.sqlite") == true) {
        qDebug() << "Consiguiendo los Datos";
        return (admindb->getUsuarios("usuarios"));
    } else {
        qDebug() << "No se pudo conectar a la Base de Datos";
    }
}
