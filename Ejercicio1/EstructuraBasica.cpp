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

    void addSymbol(const string& name, int value) {
        symbolTable[name] = value;
    }

    int getSymbolValue(const std::string& name) {
        if (symbolTable.find(name) != symbolTable.end()) {
            return symbolTable[name];
        } else {
            cerr << "Error: El valor " << name << " no esta definido." << endl;
            return 0;
        }
    }


};

int main() {

    Environment env;


    env.addSymbol("a", 4);
    env.addSymbol("b", 16);

    cout << "El valor de a es: " << env.getSymbolValue("a") << endl;
    cout << "El valor de b es: " << env.getSymbolValue("b") << endl;
    cout << "El valor de c es: " << env.getSymbolValue("c") << endl;

    return 0;
}
