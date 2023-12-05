#include <iostream>
#include <map>
#include <string>
using namespace std; // std::map, std::string, std::cerr, std::endl
class Environment { // Environment class
private:
    map<string, int> symbolTable; // symbolTable map

public:  // public methods

    Environment() { // Constructor

    }

    bool insert(const string& name, int value) { // insert method
        auto result = symbolTable.insert(make_pair(name, value)); // insert the pair
        return result.second; // return the result
    }

    int getSymbolValue(const string& name) {
        if (symbolTable.find(name) != symbolTable.end()) { // if the symbol is in the table
            return symbolTable[name];
        } else { // if the symbol is not in the table
            cerr << "Error: El valor " << name << " no esta definido." <<endl; // print the error
            return 0;
        }
    }

};

int main() {
    Environment env; // create an environment

    if (env.insert("a", 4)) { // insert the symbol
        cout << "Simbolo 'a' insertado con exito." << endl; // print the success message
    } else { // if the symbol is already in the table
        cerr << "Error: Simbolo 'a' ya existe en la tabla." << endl; // print the error
    }

    if (env.insert("a", 16)) { // insert the symbol
        cout << "Simbolo 'a' insertado con exito." << endl; // print the success message
    } else { // if the symbol is already in the table
        cerr << "Error: Simbolo 'a' ya existe en la tabla." << endl; // print the error
    }

    if (env.insert("b", 22)) { // insert the symbol
        cout << "Simbolo 'b' insertado con exito." << endl; // print the success message
    } else { // if the symbol is already in the table
        cerr << "Error: Simbolo 'b' ya existe en la tabla." << endl; // print the error
    }

    cout << "El valor de a es: " << env.getSymbolValue("a") << endl; // print the value of the symbol
    cout << "El valor de b es: " << env.getSymbolValue("b") << endl; // print the value of the symbol

    return 0;
}
