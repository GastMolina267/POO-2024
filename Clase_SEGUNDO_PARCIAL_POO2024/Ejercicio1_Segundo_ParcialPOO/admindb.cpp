#include "admindb.h"
#include <QSqlError>
#include <QVariant>
#include <QDebug>

AdminDB::AdminDB(QObject* parent) : QObject(parent) {
    db = QSqlDatabase::addDatabase("QSQLITE");
}

AdminDB::~AdminDB() {
    if (db.isOpen()) {
        db.close();
    }
}

AdminDB& AdminDB::getInstance() {
    static AdminDB instance;
    return instance;
}

bool AdminDB::conectar(const QString& archivoSqlite) {
    db.setDatabaseName(archivoSqlite);
    return db.open();
}

QVector<Rectangulo> AdminDB::selectRectangulos() {
    QVector<Rectangulo> rectangulos;
    if (db.isOpen()) {
        QSqlQuery query("SELECT x, y, ancho, alto FROM rectangulos", db);
        while (query.next()) {
            Rectangulo rect(query.value(0).toInt(), query.value(1).toInt(),
                            query.value(2).toInt(), query.value(3).toInt());
            rectangulos.append(rect);
        }
    } else {
        qDebug() << "Database is not open!";
    }
    return rectangulos;
}
