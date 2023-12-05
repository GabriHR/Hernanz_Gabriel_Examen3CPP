#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;
class Environment { // Tabla de simbolos
private:
    map<string, int> symbolTable; // Mapa de simbolos

public:
    Environment() { // Constructor

    }


    bool insert(const string& name, int value) { // Insertar un simbolo
        auto result = symbolTable.insert(make_pair(name, value)); // Insertar un par clave-valor
        return result.second;
    }


    pair<bool, int> lookup(const string& name) const { // Buscar un simbolo
        auto it = symbolTable.find(name); // Buscar un elemento en el mapa
        if (it != symbolTable.end()) { // Si el elemento se encuentra en el mapa
            return make_pair(true, it->second); // Devolver el valor del elemento
        } else { // Si el elemento no se encuentra en el mapa
            return make_pair(false, 0);
        }
    }
};

int main() { // Programa principal
    Environment env; // Tabla de simbolos

    env.insert("a", 4); // Insertar un simbolo
    env.insert("b", 16); // Insertar un simbolo

    auto resultX = env.lookup("a"); // Buscar un simbolo
    if (resultX.first) { // Si el simbolo se encuentra en la tabla
        cout << "El valor de a es: " << resultX.second << endl; // Mostrar el valor del simbolo
    } else { // Si el simbolo no se encuentra en la tabla
        cerr << "Error: El símbolo 'a' no está definido." << endl; // Mostrar un mensaje de error
    }

    auto resultY = env.lookup("y"); // Buscar un simbolo
    if (resultY.first) { // Si el simbolo se encuentra en la tabla
        cout << "El valor de b es: " << resultY.second << endl; // Mostrar el valor del simbolo
    } else { // Si el simbolo no se encuentra en la tabla
        cerr << "Error: El valor 'b' no esta definido." << endl; // Mostrar un mensaje de error
    }

    auto resultZ = env.lookup("c"); // Buscar un simbolo
    if (resultZ.first) { // Si el simbolo se encuentra en la tabla
        cout << "El valor de c es: " << resultZ.second << endl;
    } else { // Si el simbolo no se encuentra en la tabla
        cerr << "Error: El valor 'c' no esta definido." << endl;
    }

    return 0;
}
