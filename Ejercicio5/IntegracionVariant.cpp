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

int main() {

    Environment env;


    env.insert("a", 4);
    env.insert("b", 22.6f);
    env.insert("Nombre", std::string("Gabriel"));

    auto resultX = env.lookup("a");
    if (holds_alternative<int>(resultX)) {
        cout << "El valor de a es: " << get<int>(resultX) << endl;
    }

    auto resultY = env.lookup("b");
    if (holds_alternative<float>(resultY)) {
        cout << "El valor de b es: " << get<float>(resultY) << endl;
    }

    auto resultName = env.lookup("Nombre");
    if (holds_alternative<string>(resultName)) {
        cout << "El valor de Nombre es: " << get<string>(resultName) << endl;
    }

    auto resultZ = env.lookup("c");
    if (holds_alternative<int>(resultZ)) {
        cout << "El valor de c es: " << get<int>(resultZ) << endl;
    }

    return 0;
}