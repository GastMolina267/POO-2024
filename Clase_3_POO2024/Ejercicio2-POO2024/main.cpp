#include <iostream>
#include <cstdlib> // Para system()
#include "library.h"

int main() {
    system("echo %PATH%"); // Mostrar el contenido de la variable de entorno PATH
    sayHello(); // Llamar a la función de la librería
    return 0;
}

