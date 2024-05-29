# Clase N°17
## Ejercicio 📚

### Ejercicio 25
**Descripción:**
- Construir un nuevo proyecto que tenga un Login independiente, es decir, que no dependa de otra clase GUI.
- El Login tendrá un `QLabel` que funcionará como botón para registrar un nuevo usuario.
- Al presionar el `QLabel` que funciona como botón, se abrirá una ventana para dar de alta un usuario.
- Usar SQLite con `AdminDB` como singleton.
- Cuando un usuario válido ingresa correctamente, se mostrará otra ventana que visualizará todos los usuarios cargados en la base.
- Para la visualización de los usuarios se puede usar `QTreeWidget`. 
- Agregar la funcionalidad para que en esta misma ventana se puedan editar los campos como si fuera una planilla tipo Excel.

## Características principales 🙋‍♂️🙋‍♀️

- **Login Independiente**: Una ventana de login que no depende de otras clases GUI.
- **Registro de Usuarios**: `QLabel` interactivo que permite abrir una ventana para registrar nuevos usuarios.
- **SQLite con Singleton**: Gestión de base de datos SQLite usando `AdminDB` como singleton.
- **Visualización de Usuarios**: Una ventana que muestra todos los usuarios cargados en la base de datos utilizando `QTreeWidget`.
- **Edición en la Misma Ventana**: Capacidad de editar los campos de usuario directamente en la interfaz, similar a una planilla de Excel.

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
   git clone https://github.com/GastMolina267/Clase_17_POO2024.git
2. **Instalar dependencias**:
  Asegúrate de tener C++, Qt y SQLite instalados en tu sistema.
  Sigue las instrucciones de instalación en sus respectivas páginas oficiales.
3. **Ejecutar el proyecto**:
  Abre el proyecto en tu IDE de preferencia.
  Compila y ejecuta la aplicación.
  Utiliza la ventana de login para ingresar como usuario registrado o registrar un nuevo usuario.
  Una vez ingresado, podrás visualizar los usuarios en la ventana principal.
>[!NOTE]
>Este proyecto es parte del curso de Programación Orientada a Objetos y su objetivo es reforzar los conceptos aprendidos mediante la práctica y la implementación de ejemplos reales. 🤝
