// admindb.h
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
    static AdminDB& getInstance(); // Método para obtener la instancia única

    bool conectar( QString archivoSqlite );
    QSqlDatabase getDB();

    bool validarUsuario( QString tabla, QString usuario, QString clave );
    void ingresarUsuario( QString tabla, QString usuario, QString clave, QString nombre, QString apellido);
    bool existeUsuario( QString tabla, QString usuario );

private:
    explicit AdminDB(QObject *parent = nullptr); // Constructor privado
    ~AdminDB(); // Destructor privado

    QSqlDatabase db;

    static AdminDB* instance; // Instancia única de AdminDB
};

#endif // ADMINDB_H
