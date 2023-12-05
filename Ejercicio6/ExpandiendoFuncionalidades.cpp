#include <iostream>
#include <map>
#include <string>
#include <variant>
using namespace std;
class Environment {
private:
    map<string, variant<int, float, string>> symbolTable;

public:
    Environment() {

    }

    void insert(const string& name, const variant<int, float, string>& value) {
        auto result = symbolTable.insert(std::make_pair(name, value));
        if (!result.second) {
            cerr << "Error: El valor " << name << " ya existe en la tabla." << endl;
        }
    }

    variant<int, float, string> lookup(const string& name) const {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            std::cerr << "Error: El valor " << name << " no esta definido." << endl;
            return variant<int, float, string>();
        }
    }


    void removeSymbol(const std::string& name) {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            symbolTable.erase(it);
        } else {
            cerr << "Error: No se puede eliminar el valor " << name << " porque no existe." << endl;
        }
    }

    bool symbolExists(const string& name) const {
        return symbolTable.find(name) != symbolTable.end();
    }

};


