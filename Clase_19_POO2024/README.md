# Clase N°19
## Ejercicios 📚

### Simulacro de Examen Parcial

#### Ejercicio A
**Descripción:**
1. Definir una ventana vacía en la clase `Principal`, que herede de `QWidget` y diseñada con QtDesigner.
2. Agregar a este proyecto la clase `AdminDB` para permitir el uso de una base de datos.
3. Instanciar un único objeto de `AdminDB` en la aplicación.
4. Definir una clase `Linea` con las siguientes características:
   - Archivos: `linea.h` y `linea.cpp`.
   - Atributos privados: `int x_inicial`, `int y_inicial`, `int x_final`, `int y_final`.
   - Getters y setters.
   - Uso de `const` donde sea recomendable.
5. Definir una tabla `lineas` en la base de datos con los siguientes campos: `id`, `x_inicial`, `y_inicial`, `x_final`, `y_final`.
6. Cargar en la base de datos un único registro con los datos de una línea.
7. Desde la clase `Principal`, leer este único registro y crear un objeto `Linea` con esos datos.
8. Dibujar con `paintEvent` esta línea dentro de la ventana con las coordenadas leídas de la base.

#### Ejercicio B
**Descripción:**
1. Definir un formulario en la clase `Formulario` usando QtDesigner.
2. En `Formulario` se darán de alta instrumentos en un negocio de instrumentos musicales: guitarras, vientos y teclados.
3. Definir las clases `Instrumento`, `Guitarra`, `Viento` y `Teclado` en sus correspondientes archivos `.h` y `.cpp`.
4. `Instrumento` será una clase abstracta con la función virtual pura `void afinar()`, que publicará un texto por consola, por ejemplo "Afinando guitarra".
5. El formulario tendrá un botón para agregar un instrumento nuevo a un `QVector<Instrumento *>`.
6. El formulario tendrá un `QComboBox` con el siguiente listado: Guitarra, Viento y Teclado.
7. El formulario tendrá un botón "Ver stock" que publicará por consola todos los instrumentos cargados.
8. Los Instrumentos tendrán los siguientes atributos: `marca`, `precio`, `cantidad_de_cuerdas`, `cantidad_de_teclas`, `metal_usado`.
9. Cuando en el `QComboBox` se seleccione Guitarra, se deberá permitir ingresar sólo la marca, el precio y la cantidad de cuerdas.

#### Ejercicio C
**Descripción:**
1. Crear una clase `Lienzo` que herede de `QWidget`, creada con QtDesigner y que permita dibujar con `paintEvent`.
2. Cuando se presiona la tecla `A` (Activar), se comenzará a dibujar cada posición en donde se encuentra el mouse, sin depender de que se presione algún botón del mouse.
3. Cuando se presiona la tecla `D` (Desactivar), se dejará de dibujar.
4. La clase `Lienzo` recibe una enumeración que puede ser: `TrazoFino`, `TrazoMediano`, `TrazoGrueso` que determinará el grosor de lo que se dibuja.
5. Dentro de `Lienzo` y ubicado abajo a la derecha, se ubicará un objeto de `MiLabel`, que hereda de `QLabel`, con una señal propia para detectar el click del mouse.
6. Cuando se presione este `MiLabel`, se borrará todo lo dibujado.

#### Ejercicio D
**Descripción:**
1. Usar la clase `Manager` para gestionar todas las ventanas de una nueva aplicación.
2. Usar un login (`clase Login`) que valide usuarios contra la tabla `usuarios` usando `AdminDB`.
   - Para el campo `clave` usar MD5.
3. La base de datos debe estar en el archivo `base.sqlite`.
4. `Login` y `AdminDB` deben ser singleton.
5. Cada clase en sus correspondientes archivos `.h` y `.cpp`.
6. Cuando un usuario ingrese correctamente, mostrar una ventana vacía.

## Características principales 🙋‍♂️🙋‍♀️

- **Base de Datos**: Uso de SQLite para almacenar y gestionar datos.
- **Dibujo en Pantalla**: Implementación de `paintEvent` para dibujar en un lienzo.
- **Formularios y Validación**: Creación de formularios para la gestión de datos y validación de usuarios.
- **Herencia y Polimorfismo**: Uso de clases abstractas y funciones virtuales puras.

## 🛠️ Stack

- [![C++][cplusplus-badge]][cplusplus-url] - Un lenguaje de programación de alto nivel.
- [![Qt][qt-badge]][qt-url] - Un marco de desarrollo de aplicaciones multiplataforma.
- [![SQLite][sqlite-badge]][sqlite-url] - Un sistema de gestión de bases de datos relacional.

[qt-url]: https://www.qt.io/
[qt-badge]: https://img.shields.io/badge/Qt-41CD52?style=for-the-badge&logo=Qt&logoColor=white
[cplusplus-url]: https://es.wikipedia.org/wiki/C%2B%2B
[cplusplus-badge]: https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white
[sqlite-url]: https://www.sqlite.org/index.html
[sqlite-badge]: https://img.shields.io/badge/SQLite-07405E?style=for-the-badge&logo=sqlite&logoColor=white

## Cómo empezar 🚀

1. **Clonar el repositorio**:
   ```bash
   git clone https://github.com/GastMolina267/Clase_19_POO2024.git
2. **Instalar dependencias**:
  Asegúrate de tener C++, Qt y SQLite instalados en tu sistema.
  Sigue las instrucciones de instalación en sus respectivas páginas oficiales.
3. **Ejecutar los ejercicios**:
  Abre cada proyecto en tu IDE de preferencia.
  Compila y ejecuta los programas según las instrucciones de cada ejercicio.
>[!NOTE]
>Este conjunto de ejercicios es parte del curso de Programación Orientada a Objetos y su objetivo es reforzar los conceptos aprendidos mediante la práctica y la implementación de ejemplos reales. 🤝
