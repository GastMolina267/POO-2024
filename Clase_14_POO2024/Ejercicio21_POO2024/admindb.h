#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QString>
#include <QByteArray>
#include <QCryptographicHash>

class AdminDB : public QObject
{
    Q_OBJECT
public:
    explicit AdminDB(QObject *parent = nullptr);

    bool conectar( QString archivoSqlite );
    QSqlDatabase getDB();

    bool validarUsuario( QString tabla, QString usuario, QString clave );
    void ingresarUsuario( QString tabla, QString usuario, QString clave, QString nombre, QString apellido);
    bool existeUsuario( QString tabla, QString usuario );

private:
    QSqlDatabase db;
};

#endif // ADMINDB_H
