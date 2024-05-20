# Clase N°14
## Ejercicios 📚

### Ejercicio 20
**Descripción:**
- Crear un proyecto Qt Widget Application con un `QWidget` que sea la clase `Ventana`.
- Crear una clase `Boton` que hereda de `QWidget`.
- Redefinir `paintEvent` en `Boton` y usar `fillRect` para dibujarlo de algún color.
- Definir el siguiente método en `Boton`:
  ```cpp
  Boton * boton = new Boton;
  boton->colorear(Boton::Azul);
  // Este método recibe como parámetro una enumeración que puede ser:
  // Boton::Azul  Boton::Verde  Boton::Magenta
- Usar QtDesigner para Ventana y Boton. Es decir, Designer Form Class.
- Definir la enumeración en Boton.
- Abrir el designer de Ventana y agregar 5 botones (objetos de la clase Boton). Promocionarlos.
- Que esta Ventana con botones quede lo más parecido a la siguiente imagen:
- Usar para Ventana grid layout, usar espaciadores y usar todos los recursos posibles del QtDesigner.
- Dibujar un fondo agradable con paintEvent y drawImage.
- Que Boton tenga la señal signal_clic().

### Ejercicio 21
**Descripción:**

- Definir dos QWidgets (una clase Login y una clase Ventana).
- El Login validará al usuario contra una base SQLite.
- La Ventana sólo mostrará un QPushButton para "Volver" al login.
- Crear solamente un objeto de Ventana y uno solo de Login.
- Si sucede un problema en la compilación, analizar los motivos (respetar el enunciado).
- Solucionar ese problema y ver la alternativa de hacerlo con Manager.

## Características principales 🙋‍♂️🙋‍♀️
- **Interfaz Gráfica Avanzada**: Uso de QtDesigner para crear interfaces gráficas de usuario intuitivas y atractivas.
- **Personalización de Widgets**: Redefinición de paintEvent y uso de fillRect para personalizar la apariencia de los botones.
- **Gestión de Eventos**: Implementación de señales personalizadas (signal_clic()) para mejorar la interactividad.
- **Validación de Usuario**: Integración con una base de datos SQLite para validar usuarios en la pantalla de Login.

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
   git clone https://github.com/GastMolina267/Clase_14_POO2024.git
2. **Instalar dependencias**:

- Asegúrate de tener C++, Qt y SQLite instalados en tu sistema.
- Sigue las instrucciones de instalación en sus respectivas páginas oficiales.

3. **Ejecutar el proyecto**:

- Abre el proyecto en tu IDE de preferencia.
- Compila y ejecuta la aplicación.
- La aplicación se conectará automáticamente a db.sqlite y permitirá la validación de usuarios. Recordar cambiar la dirección en la que se encuentre la base de datos.

> [!NOTE]
> Este proyecto es parte del curso de Programación Orientada a Objetos y su objetivo es reforzar los conceptos aprendidos mediante la práctica y la implementación de ejemplos reales. 🤝
