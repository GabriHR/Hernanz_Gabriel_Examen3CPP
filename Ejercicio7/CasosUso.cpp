#include <iostream>
#include <map>
#include <string>
#include <variant>
using namespace std;
class Environment {
private:
    map<string, variant<int, float, string, bool>> gameData;

public:
    Environment() {

    }

    void insertData(const string& key, const variant<int, float, string, bool>& value) {
        auto result = gameData.insert(make_pair(key, value));
        if (!result.second) {
            cerr << "Error: La clave " << key << " ya existe en la tabla." << endl;
        }
    }

    template <typename T>
    T getData(const string& key) const {
        auto it = gameData.find(key);
        if (it != gameData.end()) {
            try {
                return std::get<T>(it->second); // Corregido a std::get
            } catch (const bad_variant_access&) {
                cerr << "Error: Tipo incorrecto al acceder a la clave " << key << "." << endl;
            }
        } else {
            cerr << "Error: La clave '" << key << "' no esta definida." << std::endl;
        }
        return T();
    }

};

