# Clase N°09
## Ejercicios 📚

### Ejercicio B
**Descripción:**
- Crear una aplicación que inicie con un login validando el usuario `admin:123`.
- Luego de ingresar el usuario válido, mostrar un nuevo `QWidget` con las siguientes características:
  - Definida en la clase `Editor`.
  - Contendrá un `QTextEdit` vacío, un `QLineEdit`, un `QPushButton` "Buscar" y un `QLabel`.
  - El usuario podrá escribir cualquier texto en el `QTextEdit`.
  - El usuario podrá escribir en el `QLineEdit` un caracter, una cadena o una frase.
  - Al presionar "Buscar", se detectará automáticamente la cantidad de ocurrencias encontradas de lo escrito en el `QLineEdit`.
  - El resultado se mostrará en el `QLabel`, indicando, por ejemplo, "14 ocurrencias."

**Extensión del ejercicio:**
- Agregar un `QLineEdit` y un `QPushButton` "Guardar".
  - En este `QLineEdit` el usuario puede colocar el nombre de un archivo `.txt`.
  - Al presionar "Guardar", se almacenará todo el texto del `QTextEdit` en este archivo `.txt`.

### Ejercicio C
**Descripción:**
- Crear una clase `Barra` para dar funcionalidad a una barra de progreso.
  - La barra debe tener un aspecto visual claro que indique el progreso en porcentaje.
  - Debe tener métodos para setear su valor en porcentaje.
- Usar la señal de `downloadProgress` de `QNetworkReply` para controlar el porcentaje de descarga.
- Crear una interfaz que tenga un `QLineEdit` para una URL y un objeto `Barra`.
- Probarlo con alguna URL que pertenezca a un archivo de tamaño superior a 50MB para que se note la demora en la descarga.

## Características principales 🙋‍♂️🙋‍♀️

### Ejercicio B
- **Validación de Usuario**: Login simple que valida credenciales `admin:123`.
- **Búsqueda de Texto**: Herramienta para buscar y contar ocurrencias de un texto en un documento.
- **Guardado de Archivos**: Funcionalidad para guardar el contenido del `QTextEdit` en un archivo `.txt`.

### Ejercicio C
- **Barra de Progreso**: Implementación de una barra de progreso personalizada.
- **Control de Descargas**: Uso de `QNetworkReply` para mostrar el progreso de la descarga de archivos grandes.
- **Interfaz de Usuario**: Proporciona un `QLineEdit` para ingresar URLs y visualizar el progreso de descarga.

## 🛠️ Stack

- [![C++][cplusplus-badge]][cplusplus-url] - Un lenguaje de programación de alto nivel.
- [![Qt][qt-badge]][qt-url] - Un marco de desarrollo de aplicaciones multiplataforma.

[qt-url]: https://www.qt.io/
[qt-badge]: https://img.shields.io/badge/Qt-41CD52?style=for-the-badge&logo=Qt&logoColor=white
[cplusplus-url]: https://es.wikipedia.org/wiki/C%2B%2B
[cplusplus-badge]: https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white

## Cómo empezar 🚀

1. **Clonar el repositorio**:
   ```bash
   git clone https://github.com/tu_usuario/Clase_09_POO2024.git
2. **Instalar dependencias**:
  Asegúrate de tener C++ y Qt instalados en tu sistema.
  Sigue las instrucciones de instalación en las respectivas páginas oficiales.
3. **Ejecutar el ejercicio B**:
  Abre el proyecto en tu IDE de preferencia.
  Compila y ejecuta la aplicación.
  Inicia sesión con las credenciales admin:123.
  Utiliza el QTextEdit, QLineEdit, QPushButton y QLabel para buscar texto y guardar archivos.
4. **Ejecutar el ejercicio C**:
  Abre el proyecto en tu IDE de preferencia.
  Compila y ejecuta la aplicación.
  Ingresa una URL en el QLineEdit y observa la barra de progreso mientras se descarga el archivo.
>[!NOTE]
>Estos proyectos son parte del curso de Programación Orientada a Objetos y su objetivo es reforzar los conceptos aprendidos mediante la práctica y la implementación de ejemplos reales. 🤝
