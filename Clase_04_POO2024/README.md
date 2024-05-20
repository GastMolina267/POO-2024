# Clase N°04
## Ejercicios 📚

### Ejercicio 8
**Descripción:**
- En un proyecto Empty qmake, crear una función genérica que imprima por consola una descripción de cualquier objeto.
- El mensaje puede ser algo así: "Persona con nombre Lucrecia", "Poste con altura de 8 metros y 15 cm de diámetro".
- Probar esta función en `main` utilizando dos objetos de la clase `Persona` y dos objetos de la clase `Poste`.
- Incluir todo el código fuente en el archivo `main.cpp`.

### Ejercicio 9
**Descripción:**
- En un proyecto Empty qmake, crear una función genérica que imprima por consola sus valores ordenados.
- Se le pasa un array con sus valores en cualquier orden, y la función genérica los imprime ordenados.
- El prototipo de la función es: `template <class T> void imprimir(T * v, int cantidad, bool mayor_a_menor);`
- Utilizar el método de ordenamiento por inserción.
- Probar esta función en `main` utilizando dos arrays (int y float) y ordenar uno de mayor a menor y el otro al revés.

### Ejercicio 10
**Descripción:**
- En un proyecto Empty qmake, crear una clase `Jugador` con atributos `int velocidad`, `int fuerza` y `std::string nombre`.
- Usar constructor inicializando de la manera recomendada la velocidad en 0, fuerza en 0 y nombre "sin nombre".
- Crear los métodos setter y getter para setear y obtener los valores de los atributos.
- Incluir el destructor.
- En la función `main` crear un `std::vector<Jugador>` e insertar 10 jugadores distintos.
- Publicar los datos de cada uno de los jugadores con `std::cout`.

### Ejercicio 11
**Descripción:**
- En un proyecto Empty qmake, en la función `main` crear un objeto de la clase `QLabel`, uno de `QWidget`, uno de `QPushButton` y uno de `QLineEdit`.
- Invocar al método `show()` de cada uno de estos 4 objetos.
- Notar que cada objeto se muestra independiente.

### Ejercicio 12
**Descripción:**
- En un proyecto Empty qmake, en la función `main` crear un objeto de la clase `QLabel` y pegarle en el mismo objeto `QLabel` una imagen de alta resolución.
- La imagen se obtiene desde un archivo JPG del disco duro.
- Mostrar el `QLabel` de forma maximizada y que la imagen no se deforme.
- Al cabo de 3 segundos, el `QLabel` y la aplicación se deberá cerrar.

## Características principales 🙋‍♂️🙋‍♀️

- **Función Genérica**: Implementación de una función genérica para imprimir descripciones de objetos.
- **Ordenamiento Genérico**: Función genérica para ordenar arrays utilizando el método de inserción.
- **Gestión de Jugadores**: Creación y gestión de objetos de la clase `Jugador`.
- **Componentes Independientes**: Uso de componentes de `Qt` como `QLabel`, `QWidget`, `QPushButton` y `QLineEdit`.
- **Visualización de Imágenes**: Cargar y mostrar imágenes de alta resolución en un `QLabel`.

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
   git clone https://github.com/tu_usuario/Clase_04_POO2024.git
2. **Instalar dependencias**:
  Asegúrate de tener C++ y Qt instalados en tu sistema.
  Sigue las instrucciones de instalación en sus respectivas páginas oficiales.
3. **Ejecutar los ejercicios**:
  Abre cada proyecto en tu IDE de preferencia.
  Compila y ejecuta los programas según las instrucciones de cada ejercicio.

> [!NOTE]
> Este conjunto de ejercicios es parte del curso de Programación Orientada a Objetos y su objetivo es reforzar los conceptos aprendidos mediante la práctica y la implementación de ejemplos reales. 🤝
