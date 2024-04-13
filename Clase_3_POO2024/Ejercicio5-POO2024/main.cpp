#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Crear un vector para almacenar las expresiones idiomáticas
    vector<string> expresiones_idiomaticas;

    // Cargar 5 expresiones idiomáticas en el vector
    expresiones_idiomaticas.push_back("pan comido");
    expresiones_idiomaticas.push_back("meter la pata");
    expresiones_idiomaticas.push_back("coger el toro por los cuernos");
    expresiones_idiomaticas.push_back("más vale tarde que nunca");
    expresiones_idiomaticas.push_back("quemarse las pestañas");

    // Ordenar el vector alfabéticamente
    sort(expresiones_idiomaticas.begin(), expresiones_idiomaticas.end());

    // Publicar por consola las expresiones idiomáticas ordenadas
    cout << "Expresiones idiomáticas ordenadas alfabéticamente:" << endl;
    for (const string& expresion : expresiones_idiomaticas) {
        cout << expresion << endl;
    }

    return 0;
}
