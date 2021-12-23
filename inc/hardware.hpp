#ifndef __HARDWARE_HPP
#define __HARDWARE_HPP

#include <fstream>
#include <iostream>
#include <string>

#include "../lib/json.hpp"
using json = nlohmann::json;

using namespace std;

class Hardware {
 private:
 public:
  int cores;
  int segmentos;
  int blocos;
  Hardware(string file_name);
};
#endif
