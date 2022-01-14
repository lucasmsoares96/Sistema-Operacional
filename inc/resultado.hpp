#ifndef __READJSON_HPP
#define __READJSON_HPP

#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "../lib/json.hpp"

using json = nlohmann::json;

using namespace std;

class Resultado {
    private:
    public:
    int timestamp_total;
    int ciclos_de_cpu;
    list<string> sequencia_das_acoes;
    Resultado();
};
#endif