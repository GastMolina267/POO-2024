# Clase N°15
## Ejercicios 📚

### Ejercicio 22
**Descripción:**
- Crear una clase base llamada `Instrumento` y las clases derivadas `Guitarra`, `Bateria` y `Teclado`.
- La clase base tiene una función virtual pura llamada `sonar()`.
- Definir una función virtual `verlo()` que publique la marca del instrumento. Por defecto todos los instrumentos son de la marca Yamaha.
- Utilizar en la función `main()` un `std::vector` para almacenar punteros a objetos del tipo `Instrumento`. Instanciar 5 objetos y agregarlos al `std::vector`.
- Publicar la marca de cada instrumento recorriendo el vector.
- En las clases derivadas agregar los datos miembro `int cuerdas`, `int teclas` e `int tambores` según corresponda. Por defecto, guitarra con 6 cuerdas, teclado con 61 teclas y batería con 5 tambores.
- Hacer que la clase `Teclado` tenga herencia múltiple, heredando además de una nueva clase `Electrico`. Todos los equipos del tipo "Electrico" tienen por defecto un voltaje de 220 volts. Esta clase deberá tener un destructor que al destruirse publique la leyenda "Desenchufado".
- Al llamar a la función `sonar()`, se deberá publicar "Guitarra suena...", "Teclado suena..." o "Batería suena..." según corresponda.
- Incluir los métodos `get` y `set` que crea convenientes.

### Ejercicio 23
**Descripción:**
- Reutilizar el código fuente de cualquier otro ejercicio y utilizar herencia múltiple, inline y friend.
- Implementar herencia múltiple, inline y friend cuando sea beneficioso hacerlo.

## Características principales 🙋‍♂️🙋‍♀️

- **Programación Orientada a Objetos**: Implementación de jerarquías de clases utilizando herencia y polimorfismo.
- **Uso de Punteros y Vectores**: Manejo de punteros y vectores para almacenar y gestionar objetos polimórficos.
- **Polimorfismo y Funciones Virtuales**: Definición de funciones virtuales y uso de polimorfismo para permitir comportamientos diferentes en objetos de la misma jerarquía.
- **Herencia Múltiple y Construcción de Clases**: Aplicación de herencia múltiple para extender las funcionalidades de las clases.
- **Inline y Friend**: Utilización de inline y friend cuando es beneficioso para mejorar la legibilidad y la eficiencia del código.

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
   git clone https://github.com/GastMolina267/Clase_15_POO2024.git
2. **Instalar dependencias**:
  Asegúrate de tener C++ y Qt instalados en tu sistema.
  Sigue las instrucciones de instalación en sus respectivas páginas oficiales.
3. **Ejecutar los ejercicios**:
  Abre cada proyecto en tu IDE de preferencia.
  Compila y ejecuta los programas según las instrucciones de cada ejercicio.

> [!NOTE]
> Este conjunto de ejercicios es parte del curso de Programación Orientada a Objetos y su objetivo es reforzar los conceptos aprendidos mediante la práctica y la implementación de ejemplos reales. 🤝
