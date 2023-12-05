#include <iostream>
#include <map>
#include <string>
#include <utility>
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


    pair<bool, int> lookup(const string& name) const {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            return make_pair(true, it->second);
        } else {
            return make_pair(false, 0);
        }
    }
};


