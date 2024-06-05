#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVector>
#include "rectangulo.h"

class AdminDB : public QObject {
    Q_OBJECT

public:
    static AdminDB& getInstance();
    bool conectar(const QString& archivoSqlite);
    QVector<Rectangulo> selectRectangulos();

private:
    AdminDB(QObject* parent = nullptr);
    ~AdminDB();
    AdminDB(const AdminDB&) = delete;
    AdminDB& operator=(const AdminDB&) = delete;

    QSqlDatabase db;
};

#endif // ADMINDB_H
