# Clase N°13
## Proyecto Continuación Ejercicio 14 📚 MD5
> [!IMPORTANT]
> Este repositorio es una continuación del Ejercicio 14 y añade funcionalidad de conexión a una base de datos SQL y uso de MD5 para las claves de los usuarios.

## Características principales 🙋‍♂️🙋‍♀️

- **Conexión a Base de Datos**: El proyecto ahora puede conectarse a una base de datos SQL "db.sqlite" para gestionar la validación de usuarios.
- **Validación de Usuarios con MD5**: Implementación del uso de MD5 para encriptar las claves de los usuarios y verificar si ya están registrados en la base de datos.
- **Código Documentado**: Cada archivo de código incluye documentación detallada para facilitar la comprensión y el uso.
- **Actualizaciones Constantes**: El repositorio se mantendrá actualizado con nuevas características y mejoras.

## 🛠️ Stack

- [![C++][cplusplus-badge]][cplusplus-url] - Un lenguaje de programación de alto nivel.
- [![Qt][qt-badge]][qt-url] - Un marco de desarrollo de aplicaciones multiplataforma.
- [![SQLite][sqlite-badge]][sqlite-url] - Una biblioteca de software que proporciona un sistema de gestión de bases de datos SQL.

[qt-url]: https://www.qt.io/
[qt-badge]: https://img.shields.io/badge/Qt-41CD52?style=for-the-badge&logo=Qt&logoColor=white
[cplusplus-url]: https://es.wikipedia.org/wiki/C%2B%2B
[sqlite-url]: https://www.sqlite.org/index.html
[cplusplus-badge]: https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white
[sqlite-badge]: https://img.shields.io/badge/SQLite-003B57?style=for-the-badge&logo=SQLite&logoColor=white

## Cómo empezar 🚀

1. **Clonar el repositorio**:
   ```bash
   git clone https://github.com/GastMolina267/proyecto-continuacion-ej14.git
   
2. **Instalar dependencias**:

- Asegúrate de tener C++, Qt y SQLite instalados en tu sistema.
- Sigue las instrucciones de instalación en sus respectivas páginas oficiales.

3. **Ejecutar el proyecto**:

- Abre el proyecto en tu IDE de preferencia.
- Compila y ejecuta la aplicación.
- La aplicación se conectará automáticamente a db.sqlite y permitirá la validación de usuarios.

## Implementación de MD5
El método validarUsuario en la clase AdminDB ha sido acondicionado para usar MD5 en la validación de claves de usuarios:

	/**
	 * Si el usuario y clave son crrectas, este metodo devuelve el nombre y 
	 * apellido en un QStringList.	           
	 */
	QStringList AdminDB::validarUsuario( QString tabla,	QString usuario, QString clave )  {

	    QStringList datosPersonales;

	    if ( ! db.isOpen() ) 
	        return datosPersonales;

	    QSqlQuery * query = new QSqlQuery( db );
	    QString claveMd5 = QCryptographicHash::hash( clave.toUtf8(), 
	                                                 QCryptographicHash::Md5 ).toHex();

	    query->exec( "SELECT nombre, apellido FROM " +
	                 tabla + " WHERE usuario = '" + usuario +
	                 "' AND clave = '" + claveMd5 + "'" );
	
	    while( query->next() )  {
	        QSqlRecord registro = query->record();

	        datosPersonales << query->value( registro.indexOf( "nombre" ) ).toString();
	        datosPersonales << query->value( registro.indexOf( "apellido" ) ).toString();
	    }

	    return datosPersonales;
	} 

> [!NOTE]
> Este proyecto es parte del curso de Programación Orientada a Objetos y su objetivo es reforzar los conceptos aprendidos mediante la práctica y la implementación de ejemplos reales. 🤝
