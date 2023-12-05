#include <iostream>
#include <map>
#include <string>
using namespace std; // Incluye las librerias
class Environment { // Clase Environment
private:
    map<string, int> symbolTable; // Tabla de simbolos

public:
    Environment() { // Constructor

    }

    void addSymbol(const string& name, int value) {
        symbolTable[name] = value; // Inserta el valor en la tabla
    }

    int getSymbolValue(const std::string& name) { // Devuelve el valor de la tabla
        if (symbolTable.find(name) != symbolTable.end()) { // Si el valor existe en la tabla
            return symbolTable[name]; // Devuelve el valor
        } else { // Si no existe
            cerr << "Error: El valor " << name << " no esta definido." << endl; // Muestra un error
            return 0;
        }
    }


};

int main() { // Funcion principal

    Environment env; // Crea un objeto de la clase Environment


    env.addSymbol("a", 4); // Inserta el valor 4 en la tabla con el nombre "a"
    env.addSymbol("b", 16); // Inserta el valor 16 en la tabla con el nombre "b"

    cout << "El valor de a es: " << env.getSymbolValue("a") << endl; // Muestra el valor de "a"
    cout << "El valor de b es: " << env.getSymbolValue("b") << endl; // Muestra el valor de "b"
    cout << "El valor de c es: " << env.getSymbolValue("c") << endl; // Muestra el valor de "c"

    return 0;
}
