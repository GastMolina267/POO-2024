# Clase N°18
## Proyecto Continuación Ejercicio 16 📚
> [!IMPORTANT]
> Este repositorio es una continuación del Ejercicio 16 y añade funcionalidad de conexión a una base de datos NoSQL

**Descripción:**
- Este ejercicio continúa el trabajo realizado en las clases 5 y 7.
- Luego de tener registrados los usuarios en MongoDB y funcionando el endpoint.
- Acondicionar la clase `Login` para validar los usuarios contra el endpoint de FastAPI.

## Características principales 🙋‍♂️🙋‍♀️

- **Validación de Usuarios**: La clase `Login` se acondiciona para validar usuarios contra un endpoint de FastAPI.
- **Integración con MongoDB**: Los usuarios están registrados en una base de datos MongoDB.
- **FastAPI Endpoint**: Un endpoint de FastAPI que permite la validación de usuarios.

## 🛠️ Stack

- [![C++][cplusplus-badge]][cplusplus-url] - Un lenguaje de programación de alto nivel.
- [![Qt][qt-badge]][qt-url] - Un marco de desarrollo de aplicaciones multiplataforma.
- [![MongoDB][mongodb-badge]][mongodb-url] - Una base de datos NoSQL orientada a documentos.
- [![FastAPI][fastapi-badge]][fastapi-url] - Un moderno framework web para construir APIs con Python 3.7+ basado en estándares de tipo.

[qt-url]: https://www.qt.io/
[qt-badge]: https://img.shields.io/badge/Qt-41CD52?style=for-the-badge&logo=Qt&logoColor=white
[cplusplus-url]: https://es.wikipedia.org/wiki/C%2B%2B
[cplusplus-badge]: https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white
[mongodb-url]: https://www.mongodb.com/
[mongodb-badge]: https://img.shields.io/badge/MongoDB-47A248?style=for-the-badge&logo=MongoDB&logoColor=white
[fastapi-url]: https://fastapi.tiangolo.com/
[fastapi-badge]: https://img.shields.io/badge/FastAPI-009688?style=for-the-badge&logo=FastAPI&logoColor=white

## Cómo empezar 🚀

1. **Clonar el repositorio**:
   ```bash
   git clone https://github.com/GastMolina267/Clase_18_POO2024.git
2. **Instalar dependencias**:
- Asegúrate de tener C++, Qt, MongoDB y FastAPI instalados en tu sistema.
- Sigue las instrucciones de instalación en sus respectivas páginas oficiales.
3. **Configurar y ejecutar el servidor FastAPI**:
- Navega al directorio del servidor FastAPI
   ```bash
   cd server
- Instala las dependencias de Python:
   ```bash
   pip install -r requirements.txt
- Inicia el servidor FastAPI:
   ```bash
   uvicorn main:app --reload
4. **Ejecutar el proyecto Qt**:
  Abre el proyecto en tu IDE de preferencia.
  Compila y ejecuta la aplicación.
  Utiliza la ventana de login para ingresar como usuario registrado. La validación se realizará contra el endpoint de FastAPI.

>[!NOTE]
>Este proyecto es parte del curso de Programación Orientada a Objetos y su objetivo es reforzar los conceptos aprendidos mediante la práctica y la implementación de ejemplos reales. 🤝
