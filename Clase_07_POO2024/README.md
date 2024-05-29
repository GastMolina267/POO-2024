# Clase N°07
## Ejercicios 📚

> [!IMPORTANT]
> Este repositorio es una continuación del Ejercicio 14 y del Ejercicio 16, y añade funcionalidad de conexión a una base de datos NoSQL

### Ejercicio 14 (continuación)
**Descripción:**
- Publicar en la ventana de Login la temperatura actual en la Ciudad de Córdoba utilizando alguna API disponible.
- Agregar un método en `Login` que permita mostrar u ocultar la información de la temperatura.
- La ventana de Login debe tener como background una imagen descargada de internet, centrada y adaptada en tamaño sin deformar su aspecto, permitiendo al usuario modificar el tamaño del Login y manteniendo la imagen correctamente.
- Agregar un método en `Login` que permita indicar la URL de la imagen que se mostrará en el background. En caso de que nunca se invoque este método, no se mostrará ninguna imagen.

### Ejercicio 16 (continuación)
**Descripción:**
- Crear un endpoint para validar a los usuarios sea con un POST y que devuelva "denegado" o que devuelva el nombre y el apellido del usuario en el siguiente formato: "Juan Carlos::Ponce"

### Ejercicio 17
**Descripción:**
- Diseñar un login que cargue como fondo, una imagen descargada de internet. Una vez se realice el login, abrir una pantalla full screen con otra imágen descargada de internet.
- La ventana no se debe abrir hasta que la descarga de la imágen haya terminado.

## Características principales 🙋‍♂️🙋‍♀️

- **Información del Clima**: Visualización de la temperatura actual en la Ciudad de Córdoba utilizando una API de clima.
- **Interfaz Personalizable**: Métodos para mostrar/ocultar la información del clima y establecer la URL de la imagen de fondo.
- **Imagen de Fondo Adaptable**: La imagen de fondo se ajusta automáticamente al tamaño de la ventana sin deformarse, ofreciendo una experiencia visual agradable.

## 🛠️ Stack

- [![C++][cplusplus-badge]][cplusplus-url] - Un lenguaje de programación de alto nivel.
- [![Qt][qt-badge]][qt-url] - Un marco de desarrollo de aplicaciones multiplataforma.
- [![API Clima][api-clima-badge]][api-clima-url] - API para obtener información meteorológica.
- [![MongoDB][mongodb-badge]][mongodb-url] - Una base de datos NoSQL orientada a documentos.
- [![FastAPI][fastapi-badge]][fastapi-url] - Un moderno framework web para construir APIs con Python 3.7+ basado en estándares de tipo.

[qt-url]: https://www.qt.io/
[qt-badge]: https://img.shields.io/badge/Qt-41CD52?style=for-the-badge&logo=Qt&logoColor=white
[cplusplus-url]: https://es.wikipedia.org/wiki/C%2B%2B
[cplusplus-badge]: https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white
[api-clima-url]: https://openweathermap.org/api
[api-clima-badge]: https://img.shields.io/badge/Weather%20API-0078D4?style=for-the-badge&logo=weather&logoColor=white
[mongodb-url]: https://www.mongodb.com/
[mongodb-badge]: https://img.shields.io/badge/MongoDB-47A248?style=for-the-badge&logo=MongoDB&logoColor=white
[fastapi-url]: https://fastapi.tiangolo.com/
[fastapi-badge]: https://img.shields.io/badge/FastAPI-009688?style=for-the-badge&logo=FastAPI&logoColor=white

## Cómo empezar 🚀

1. **Clonar el repositorio**:
   ```bash
   git clone https://github.com/GastMolina267/Clase_07_POO2024.git
2. **Instalar dependencias**:
  Asegúrate de tener C++ y Qt instalados en tu sistema.
  Regístrate y obtén una clave API en OpenWeatherMap (u otra API de clima de tu preferencia).
  Sigue las instrucciones de instalación en sus respectivas páginas oficiales.
3. **Ejecutar el ejercicio**:
  Abre el proyecto en tu IDE de preferencia.
  Compila y ejecuta la aplicación.
  La aplicación mostrará la temperatura actual de Córdoba y la imagen de fondo según lo configurado.
>[!NOTE]
>Este proyecto es parte del curso de Programación Orientada a Objetos y su objetivo es reforzar los conceptos aprendidos mediante la práctica y la implementación de ejemplos reales. 🤝
