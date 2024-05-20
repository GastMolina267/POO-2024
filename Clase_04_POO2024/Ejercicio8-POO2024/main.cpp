#include <iostream>
#include <string>

using namespace std;

// Clase Persona
class Persona {
public:
    Persona(const string& nombre) : m_nombre(nombre) {}
    string getNombre() const { return m_nombre; }

private:
    string m_nombre;
};

// Clase Poste
class Poste {
public:
    Poste(double altura, double diametro) : m_altura(altura), m_diametro(diametro) {}
    double getAltura() const { return m_altura; }
    double getDiametro() const { return m_diametro; }

private:
    double m_altura;
    double m_diametro;
};

// Sobrecarga del operador de inserción para la clase Persona
ostream& operator<<(ostream& os, const Persona& persona) {
    os << persona.getNombre();
    return os;
}

// Sobrecarga del operador de inserción para la clase Poste
ostream& operator<<(ostream& os, const Poste& poste) {
    os << "altura: " << poste.getAltura() << " metros, diámetro: " << poste.getDiametro() << " cm";
    return os;
}

// Función genérica para imprimir descripción de cualquier objeto
template<typename T>
void imprimirDescripcion(const T& objeto, const string& mensaje) {
    cout << mensaje << ": " << objeto << endl;
}

int main() {
    // Crear objetos Persona
    Persona persona1("Lucrecia");
    Persona persona2("Juan");

    // Crear objetos Poste
    Poste poste1(8.0, 15.0);
    Poste poste2(10.5, 20.0);

    // Imprimir descripción de los objetos
    imprimirDescripcion(persona1, "Persona con nombre");
    imprimirDescripcion(persona2, "Persona con nombre");
    imprimirDescripcion(poste1, "Poste con ");
    imprimirDescripcion(poste2, "Poste con ");

    return 0;
}


