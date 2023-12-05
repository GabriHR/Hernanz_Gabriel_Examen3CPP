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