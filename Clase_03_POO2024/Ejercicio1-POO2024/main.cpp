#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Semilla para la generación de números aleatorios
    srand(time(nullptr));

    // Mostrar 10 números aleatorios en el intervalo [2, 20]
    for (int i = 0; i < 10; ++i) {
        int numero = std::rand() % 19 + 2; // Genera un número aleatorio entre 2 y 20
        cout << numero << " ";
    }
    cout << endl;

    return 0;
}
