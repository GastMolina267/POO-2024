#include "admindb.h"

AdminDB::AdminDB()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/marin/OneDrive/Imágenes/Documentos/lineas.db");

    if (!db.open()) {
        qDebug() << "Error al abrir la base de datos: " << db.lastError().text();
    }
}

AdminDB::~AdminDB()
{
    db.close();
}

QSqlDatabase& AdminDB::database()
{
    return db;
}

Linea* AdminDB::obtenerLinea()
{
    QSqlQuery query(db);
    query.exec("SELECT x_inicial, y_inicial, x_final, y_final FROM lineas");

    if (query.next()) {
        int x_inicial = query.value(0).toInt();
        int y_inicial = query.value(1).toInt();
        int x_final = query.value(2).toInt();
        int y_final = query.value(3).toInt();

        return new Linea(x_inicial, y_inicial, x_final, y_final);
    } else {
        qDebug() << "Error al obtener los datos de la línea: " << query.lastError().text();
        return nullptr;
    }
}

