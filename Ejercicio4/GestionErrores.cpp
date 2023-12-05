#include <iostream>
#include <map>
#include <string>
#include <stdexcept> // Para std::runtime_error
using namespace std;
class Environment {
private:
    map<string, int> symbolTable;

public:

    Environment() {

    }


    void insert(const string& name, int value) {
        auto result = symbolTable.insert(std::make_pair(name, value));
        if (!result.second) {
            throw runtime_error("Error: El valor " + name + " ya existe en la tabla.");
        }
    }

    int lookup(const string& name) const {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            throw runtime_error("Error: El valor " + name + " no esta definido.");
        }
    }

};

