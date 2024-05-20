#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> datos;

    // Cargar 30 valores pseudoaleatorios entre 1 y 15
    srand(time(nullptr)); // Inicializar la semilla del generador de números pseudoaleatorios
    for (int i = 0; i < 30; ++i) {
        datos.push_back(rand() % 15 + 1);
    }

    // Ordenar el vector para que los valores iguales estén juntos
    sort(datos.begin(), datos.end());

    // Encontrar la moda
    int moda = datos[0];
    int modaFrecuencia = 1;
    int frecuenciaActual = 1;

    for (size_t i = 1; i < datos.size(); ++i) {
        if (datos[i] == datos[i - 1]) {
            ++frecuenciaActual;
        } else {
            if (frecuenciaActual > modaFrecuencia) {
                moda = datos[i - 1];
                modaFrecuencia = frecuenciaActual;
            }
            frecuenciaActual = 1;
        }
    }

    // Comprobar la última secuencia
    if (frecuenciaActual > modaFrecuencia) {
        moda = datos.back();
        modaFrecuencia = frecuenciaActual;
    }

    // Mostrar la moda
    cout << "La moda es: " << moda << " y aparece " << modaFrecuencia << " veces." << endl;

    return 0;
}
