#include <iostream>

using namespace std;

// Función genérica para imprimir valores ordenados
template <class T>
void imprimir(T* v, int cantidad, bool mayor_a_menor) {
    // Ordenar el array utilizando el método de ordenamiento por inserción
    for (int i = 1; i < cantidad; ++i) {
        T temp = v[i];
        int j = i - 1;
        if (mayor_a_menor) {
            while (j >= 0 && v[j] < temp) {
                v[j + 1] = v[j];
                j--;
            }
        } else {
            while (j >= 0 && v[j] > temp) {
                v[j + 1] = v[j];
                j--;
            }
        }
        v[j + 1] = temp;
    }

    // Imprimir los valores ordenados
    if (mayor_a_menor) {
        cout << "Valores ordenados de mayor a menor: ";
        for (int i = 0; i < cantidad; ++i) {
            cout << v[i] << " ";
        }
    } else {
        cout << "Valores ordenados de menor a mayor: ";
        for (int i = cantidad - 1; i >= 0; --i) {
            cout << v[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    // Array de enteros
    int arr_int[] = {5, 2, 9, 1, 7};
    int cantidad_int = sizeof(arr_int) / sizeof(arr_int[0]);

    // Array de flotantes
    float arr_float[] = {3.5, 1.2, 7.8, 2.3, 5.6};
    int cantidad_float = sizeof(arr_float) / sizeof(arr_float[0]);

    // Ordenar y imprimir los valores de mayor a menor
    imprimir(arr_int, cantidad_int, true);
    imprimir(arr_float, cantidad_float, true);

    // Ordenar y imprimir los valores de menor a mayor
    imprimir(arr_int, cantidad_int, false);
    imprimir(arr_float, cantidad_float, false);

    return 0;
}

