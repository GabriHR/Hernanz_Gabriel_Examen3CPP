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
        auto result = symbolTable.insert(make_pair(name, value));
        if (!result.second) {
            cerr << "Error: El valor " << name << " ya existe en la tabla." << endl;
        }
    }

    variant<int, float, string> lookup(const string& name) const {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            cerr << "Error: El valor '" << name << " no esta definido." << endl;
            return variant<int, float, string>();
        }
    }

};
