#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Clase Jugador
class Jugador {
public:
    // Constructor
    Jugador() : velocidad(0), fuerza(0), nombre("sin nombre") {}

    // Constructor con parámetros
    Jugador(int vel, int fuer, const string& nom) : velocidad(vel), fuerza(fuer), nombre(nom) {}

    // Destructor
    ~Jugador() {}

    // Métodos setter y getter
    void setVelocidad(int vel) { velocidad = vel; }
    void setFuerza(int fuer) { fuerza = fuer; }
    void setNombre(const string& nom) { nombre = nom; }

    int getVelocidad() const { return velocidad; }
    int getFuerza() const { return fuerza; }
    string getNombre() const { return nombre; }

private:
    int velocidad;
    int fuerza;
    string nombre;
};

int main() {
    // Crear un vector de Jugador
    vector<Jugador> jugadores;

    // Insertar 10 jugadores distintos
    for (int i = 0; i < 10; ++i) {
        Jugador jugador(i * 10, i * 5, "Jugador" + to_string(i + 1));
        jugadores.push_back(jugador);
    }

    // Mostrar los datos de cada jugador
    for (const auto& jugador : jugadores) {
        cout << "Nombre: " << jugador.getNombre() << ", Velocidad: " << jugador.getVelocidad()
             << ", Fuerza: " << jugador.getFuerza() << endl;
    }

    return 0;
}
