# Primer Parcial de Programación Orientada a Objetos

## Ejercicios 📚

### Ejercicio 1
**Descripción:**
1. **Clase Acceso:**
   - Crear una clase llamada `Acceso` que herede de `QWidget`.
   - Definir la clase en los archivos `acceso.h` y `acceso.cpp`.
   - Diseñar la clase con QtDesigner.
   - La ventana deberá tener una imagen de fondo descargada desde internet, la cual se redimensionará para ajustarse al tamaño de la ventana sin pixelarse.
   - La ventana de `Acceso` no deberá aparecer hasta que la imagen se haya descargado.
   - El usuario no podrá ampliar el login a más de 400x200 píxeles.
   - Usuarios válidos:
     - `admin` con clave `1234`
     - `user` con clave `4321`
   - Si se ingresa un usuario y clave no válidos, borrar el campo clave.
   - Tras 3 intentos fallidos, cerrar la aplicación.
   - Si el usuario es válido, ocultar la ventana de `Acceso` con el método `hide()` y mostrar una nueva ventana definida en la clase `Ventana`.

2. **Clase Ventana:**
   - Definir la clase `Ventana` en los archivos `ventana.h` y `ventana.cpp`.
   - La ventana solo contendrá un `QLabel` centrado en el medio de la ventana con un texto que diga "Hola admin" u "Hola user" según corresponda.

### Ejercicio 2
**Descripción:**
1. **Clase Descargador:**
   - Crear una clase llamada `Descargador` que herede de `QWidget`.
   - Definir la clase en los archivos `descargador.h` y `descargador.cpp`.
   - No utilizar QtDesigner, sino utilizar `QGridLayout` en el constructor.
   - La ventana tendrá el siguiente aspecto:
     - Un `QLineEdit` seteado como solo lectura con la URL `http://cesarosimani.com.ar/cosillas/1.bmp` por defecto.
     - Un botón para iniciar la descarga de la imagen.
     - Utilizar `QImage` para la imagen, ajustándola al tamaño de la ventana.
     - En la parte inferior, una barra de progreso (`QProgressBar`) para indicar el progreso de la descarga de la imagen.

## Características principales 🙋‍♂️🙋‍♀️

- **Gestión de Usuarios**: Implementación de un login con validación de usuarios.
- **Descarga y Visualización de Imágenes**: Descarga de imágenes desde internet y visualización ajustada en la ventana.
- **Layouts Dinámicos**: Uso de `QGridLayout` para la disposición de elementos en la ventana.
- **Barra de Progreso**: Indicador visual del progreso de descarga.

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
   git clone https://github.com/GastMolina267/Primer_Parcial_POO2024.git
2. **Instalar dependencias**:
  Asegúrate de tener C++ y Qt instalados en tu sistema.
  Sigue las instrucciones de instalación en sus respectivas páginas oficiales.
3. **Ejecutar los ejercicios**:
  Abre cada proyecto en tu IDE de preferencia.
  Compila y ejecuta los programas según las instrucciones de cada ejercicio.
>[!NOTE]
>Estos ejercicios son parte del primer parcial del curso de Programación Orientada a Objetos y su objetivo es evaluar la comprensión y la capacidad de implementar conceptos clave mediante la práctica y la creación de aplicaciones reales. 🤝
