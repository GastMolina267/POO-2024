#include "admindb.h"

#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

AdminDB * AdminDB::instancia = nullptr;

AdminDB * AdminDB::getInstancia()  {
    if( instancia == nullptr )  {
        instancia = new AdminDB;
    }
    return instancia;
}

AdminDB::AdminDB(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase( "QSQLITE" );
}


bool AdminDB::conectar( QString archivoSqlite )  {
    db.setDatabaseName( archivoSqlite );

    if( db.open() )
        qDebug() << "Base de Datos abierta!";
    return true;

    return false;
}

QSqlDatabase AdminDB::getDB()  {
    return db;
}

bool AdminDB::validarUsuario(QString tabla, QString usuario, QString clave)
{
    qDebug() << "Usuario: " << usuario;
    qDebug() << "Clave: " << clave;
    if ( db.open() )  {
        qDebug() << "Estamos buscando..." << clave;
        QByteArray hash = QCryptographicHash::hash(clave.toUtf8(), QCryptographicHash::Md5).toHex();
        QSqlQuery query = db.exec( "SELECT nombre, apellido FROM " + tabla + " WHERE usuario = '" +
                                  usuario + "' AND clave = '" + hash + "'" );

        while( query.next() )  {
            qDebug() << query.value( 0 ).toString() << " " << query.value( 1 ).toString();
            qDebug() << "Se encontro el Usuario....";
            return true;
        }
    }
    qDebug() << "No se encontro el Usuario....";
    return false;
}

void AdminDB::ingresarUsuario(QString tabla, QString usuario, QString clave, QString nombre, QString apellido) {
    qDebug() << "Intentando Ingresar..." << usuario;
    if ( db.open() ) {
        qDebug() << "Ingresando Usuario....";
        QByteArray hash = QCryptographicHash::hash(clave.toUtf8(), QCryptographicHash::Md5).toHex();
        QSqlQuery query = db.exec( "INSERT INTO " + tabla + " (usuario, clave, nombre, apellido) values " + "('" + usuario + "','" + hash + "','" + nombre + "','" + apellido + "')'");

        QSqlQuery querytwo = db.exec( "SELECT nombre, apellido FROM " + tabla + " WHERE usuario = '" +
                                     usuario + "' AND clave = '" + hash + "'" );

        while( querytwo.next() )  {
            qDebug() << "Se ingreso con exito a la Base de Datos!";
            return;
        }
    }
    qDebug() << "No se pudo Ingresar..." << clave;
}

bool AdminDB::existeUsuario(QString tabla, QString usuario) {
    if ( db.open() ) {
        qDebug() << "Checkeando si Usuario ya existe....";
        QSqlQuery query = db.exec( "SELECT usuario FROM " + tabla + " WHERE usuario = '" +
                                  usuario + "'" );

        while( query.next() )  {
            qDebug() << query.value( 0 ).toString() << " " << query.value( 1 ).toString();
            return true;
        }
    }

    return false;
}

QSqlQuery AdminDB::getUsuarios(QString tabla)
{
    if ( db.open() )  {
        qDebug() << "Consiguiendo todos los Usuarios...";
        QSqlQuery query = db.exec( "SELECT * FROM " + tabla);

        return query;
    } else {
        QSqlQuery emptyQuery;
        emptyQuery.clear();
        return emptyQuery;
    }
}
