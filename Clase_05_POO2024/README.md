# Clase N°05
## Ejercicios 📚

### Ejercicio 13
**Punto de partida:** Usar el código del ejemplo del control de volumen.

**Descripción:**
- Cuando el valor del `QSlider` se modifique, colocar como título de la ventana el mismo valor que tiene el `QSlider`.

### Ejercicio 14
**Descripción:**
- Diseñar un login con `QGridLayout`.
- Usar asteriscos para la clave.
- Detectar enter para simular la pulsación del botón.
- Definir la clase `Formulario` que será un `QWidget`.
- `Formulario` tendrá `QLabels` y `QLineEdits` para Legajo, Nombre y Apellido, y un `QPushButton`.
- Si la clave ingresada es `admin:1111`, se cierra Login y se muestra `Formulario`.
- Si se ingresa otra clave se borrará el texto del `QLineEdit` de la clave.

### Ejercicio 16
**Descripción:**
- Registrar en MongoDB algunos usuarios (nombre, apellido, usuario, clave).
- Tener disponible un endpoint con FastAPI para validar usuarios.

## Características principales 🙋‍♂️🙋‍♀️

- **Control de Volumen**: Ejemplo de control de volumen con `QSlider` que modifica el título de la ventana con su valor.
- **Login con QGridLayout**: Implementación de un sistema de login usando `QGridLayout`.
- **Clave Segura**: Entrada de clave con asteriscos para mayor seguridad.
- **Detección de Enter**: Funcionalidad para detectar la tecla Enter y simular la pulsación del botón de login.
- **Formulario Dinámico**: Un formulario que se muestra al ingresar las credenciales correctas.
- **Validación de Usuarios con MongoDB y FastAPI**: Registro y validación de usuarios utilizando una base de datos NoSQL y un framework web moderno.

## 🛠️ Stack

- [![C++][cplusplus-badge]][cplusplus-url] - Un lenguaje de programación de alto nivel.
- [![Qt][qt-badge]][qt-url] - Un marco de desarrollo de aplicaciones multiplataforma.
- [![SQLite][sqlite-badge]][sqlite-url] - Una biblioteca de software que proporciona un sistema de gestión de bases de datos SQL.
- [![MongoDB][mongodb-badge]][mongodb-url] - Un sistema de base de datos NoSQL.
- [![FastAPI][fastapi-badge]][fastapi-url] - Un framework web moderno y rápido para construir APIs con Python.

[qt-url]: https://www.qt.io/
[qt-badge]: https://img.shields.io/badge/Qt-41CD52?style=for-the-badge&logo=Qt&logoColor=white
[cplusplus-url]: https://es.wikipedia.org/wiki/C%2B%2B
[sqlite-url]: https://www.sqlite.org/index.html
[mongodb-url]: https://www.mongodb.com/
[fastapi-url]: https://fastapi.tiangolo.com/
[cplusplus-badge]: https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white
[sqlite-badge]: https://img.shields.io/badge/SQLite-003B57?style=for-the-badge&logo=SQLite&logoColor=white
[mongodb-badge]: https://img.shields.io/badge/MongoDB-47A248?style=for-the-badge&logo=MongoDB&logoColor=white
[fastapi-badge]: https://img.shields.io/badge/FastAPI-009688?style=for-the-badge&logo=FastAPI&logoColor=white

## Cómo empezar 🚀

1. **Clonar el repositorio**:
   ```bash
   git clone https://github.com/GastMolina267/Clase_05_POO2024.git
2. **Instalar dependencias**:

Asegúrate de tener C++ y Qt instalados en tu sistema.
Sigue las instrucciones de instalación en sus respectivas páginas oficiales.
3. **Ejecutar el proyecto**:

Abre el proyecto en tu IDE de preferencia.
Compila y ejecuta la aplicación.

## Fastapi MongoDB REST API 🚀

Iniciar env
```
virtualenv venv
```
Para Linux/Mac
```
source venv/bin/activate
```
Para Windows
```
source venv/Scripts/activate
```
Instalar dependencias
```
pip install fastapi pymongo uvicorn
```
Iniciar Server
```
uvicorn index:app --reload
```
![Fastapi-mongodb](https://user-images.githubusercontent.com/16520789/118378578-6ec43e80-b5f2-11eb-99bb-1a28abe9b5ed.png)
> [!WARNING]
> Tener iniciada la Base de Datos NoSQL (MongoDB).

> [!NOTE]
> Estos ejercicios son parte del curso de Programación Orientada a Objetos y su objetivo es reforzar los conceptos aprendidos mediante la práctica y la implementación de ejemplos reales. 🤝

