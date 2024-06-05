# Segundo Parcial de Programación Orientada a Objetos

## Ejercicios 📚

### Ejercicio 1
**Descripción:**
1. **Ventana Principal:**
   - Definir en la clase `Principal` un `QWidget` con un diseño específico usando QtDesigner.
   - Archivos: `principal.h`, `principal.cpp` y `principal.ui`.
   - Tamaño de la ventana: 300 x 300 píxeles, seteado por código dentro del constructor de `Principal`.

2. **Base de Datos:**
   - Agregar la clase `AdminDB` para permitir el uso de una base de datos.
   - Trabajar `AdminDB` como singleton.
   - Realizar todas las consultas de datos a la base de datos mediante el método `select` solicitado en la Clase 13 de GitHub.

3. **Clase Rectangulo:**
   - Archivos: `rectangulo.h` y `rectangulo.cpp`.
   - Constructor:
     ```cpp
     Rectangulo(int x = 0, int y = 0, int ancho = 100, int alto = 100);
     ```
   - Atributos privados: `int x, y, ancho, alto`.
   - Definir getters, setters y métodos necesarios, usando `const` adecuadamente.

4. **Base de Datos SQLite:**
   - Crear la base de datos `rectangles.sqlite`.
   - Crear la tabla `rectangulos` con los campos: `id`, `x`, `y`, `ancho`, `alto`.
   - Cargar varios registros con datos de rectángulos distintos.

5. **Integración:**
   - Desde la clase `Principal`, leer los registros de la tabla `rectangulos` y almacenar los datos en un `QVector` de objetos `Rectangulo`.
   - Usar `paintEvent` para dibujar todos los rectángulos en la ventana.

### Ejercicio 2
**Descripción:**
1. **Clase Admin:**
   - Gestionar todas las ventanas de una nueva aplicación.
   - `Admin` debe heredar de `QObject`.
   - Archivos: `admin.h` y `admin.cpp`.

2. **Login:**
   - Usar el login solicitado en la Clase 13 de GitHub con la señal `signal_usuarioValidado`.
   - Diseñado con QtDesigner.
   - Archivos: `login.h`, `login.cpp` y `login.ui`.
   - Validar usuarios consultando la tabla `usuarios` en el archivo de base de datos `base_poo.sqlite`.
   - Realizar consultas a la base de datos mediante un objeto de la clase `AdminDB`, definida en `admindb.h` y `admindb.cpp`.

3. **Ventana:**
   - Mostrar una ventana vacía cuando un usuario ingrese correctamente.
   - Definir la ventana en la clase `Ventana`.
   - Archivos: `ventana.h`, `ventana.cpp` y `ventana.ui`.

## Características principales 🙋‍♂️🙋‍♀️

- **Gestión de Base de Datos**: Uso de SQLite para almacenar y gestionar datos.
- **Interfaz Gráfica**: Implementación de ventanas y formularios con QtDesigner.
- **Singleton Pattern**: Uso de patrón singleton para la clase `AdminDB`.
- **Dibujo en Pantalla**: Implementación de `paintEvent` para dibujar rectángulos en la ventana.

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
   git clone https://github.com/GastMolina267/Clase_SEGUNDO_PARCIAL_POO2024.git
2. **Instalar dependencias**:
  Asegúrate de tener C++, Qt y SQLite instalados en tu sistema.
  Sigue las instrucciones de instalación en sus respectivas páginas oficiales.
3. **Ejecutar los ejercicios**:
  Abre cada proyecto en tu IDE de preferencia.
  Compila y ejecuta los programas según las instrucciones de cada ejercicio.
>[!NOTE]
>Estos ejercicios son parte del segundo parcial del curso de Programación Orientada a Objetos y su objetivo es evaluar la comprensión y la capacidad de implementar conceptos clave mediante la práctica y la creación de aplicaciones reales. 🤝
