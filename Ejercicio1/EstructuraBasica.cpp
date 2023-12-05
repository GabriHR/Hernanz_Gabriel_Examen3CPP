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

