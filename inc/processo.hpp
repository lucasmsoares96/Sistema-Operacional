#ifndef __READJSON_HPP
#define __READJSON_HPP

#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "../lib/json.hpp"

using json = nlohmann::json;

using namespace std;

class Processo {
 private:
 public:
  int    processo;
  int    ciclos;
  int    max_quantum;
  int    timestamp;
  int    prioridade;
  int    punicao;
  string type;

  Processo();
};
#endif