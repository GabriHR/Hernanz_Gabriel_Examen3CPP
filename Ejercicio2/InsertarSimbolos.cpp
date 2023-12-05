#include <iostream>
#include <map>
#include <string>
using namespace std;
class Environment {
private:
    map<string, int> symbolTable;

public:

    Environment() {

    }

    bool insert(const string& name, int value) {
        auto result = symbolTable.insert(make_pair(name, value));
        return result.second;
    }

    int getSymbolValue(const string& name) {
        if (symbolTable.find(name) != symbolTable.end()) {
            return symbolTable[name];
        } else {
            cerr << "Error: El valor " << name << " no esta definido." <<endl;
            return 0;
        }
    }

};

int main() {
    Environment env;

    if (env.insert("a", 4)) {
        cout << "Simbolo 'a' insertado con exito." << endl;
    } else {
        cerr << "Error: Simbolo 'a' ya existe en la tabla." << endl;
    }

    if (env.insert("a", 16)) {
        cout << "Simbolo 'a' insertado con exito." << endl;
    } else {
        cerr << "Error: Simbolo 'a' ya existe en la tabla." << endl;
    }

    if (env.insert("b", 22)) {
        cout << "Simbolo 'b' insertado con exito." << endl;
    } else {
        cerr << "Error: Simbolo 'b' ya existe en la tabla." << endl;
    }

    cout << "El valor de a es: " << env.getSymbolValue("a") << endl;
    cout << "El valor de b es: " << env.getSymbolValue("b") << endl;

    return 0;
}
