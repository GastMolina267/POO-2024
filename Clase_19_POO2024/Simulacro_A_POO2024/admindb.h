#ifndef ADMINDB_H
#define ADMINDB_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "linea.h"

class AdminDB
{
public:
    AdminDB();
    ~AdminDB();

    QSqlDatabase& database();
    Linea* obtenerLinea();

private:
    QSqlDatabase db;
};

#endif // ADMINDB_H
