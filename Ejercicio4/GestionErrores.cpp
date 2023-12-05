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

int main() {
    try {
        Environment env;

        env.insert("a", 4);
        env.insert("b", 16);

        std::cout << "El valor de a es: " << env.lookup("a") << std::endl;
        std::cout << "El valor de b es: " << env.lookup("b") << std::endl;

        env.insert("a", 4);

        cout << "El valor de c es: " << env.lookup("c") << endl;
    } catch (const exception& e) {
        cerr << "Excepcion capturada: " << e.what() << endl;
    }

    return 0;
}
