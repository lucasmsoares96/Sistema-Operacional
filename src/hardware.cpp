#include "../inc/hardware.hpp"

Hardware::Hardware(string file_name) {
  ifstream i(file_name);
  json     j;
  i >> j;
  this->cores     = j["cores"];
  this->segmentos = j["segmentos"];
  this->blocos    = j["blocos"];
  this->politica  = j["politica"];
  i.close();
}