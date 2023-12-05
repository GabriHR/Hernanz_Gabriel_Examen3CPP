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

int main() {
    Environment env;

    env.insert("a", 4);
    env.insert("b", 16);

    auto resultX = env.lookup("a");
    if (resultX.first) {
        cout << "El valor de a es: " << resultX.second << endl;
    } else {
        cerr << "Error: El símbolo 'a' no está definido." << endl;
    }

    auto resultY = env.lookup("y");
    if (resultY.first) {
        cout << "El valor de b es: " << resultY.second << endl;
    } else {
        cerr << "Error: El valor 'b' no esta definido." << endl;
    }

    auto resultZ = env.lookup("z");
    if (resultZ.first) {
        cout << "El valor de c es: " << resultZ.second << endl;
    } else {
        cerr << "Error: El valor 'c' no esta definido." << endl;
    }

    return 0;
}
