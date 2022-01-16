#include "../inc/hardware.hpp"

Hardware::Hardware(string file_name) {
  // read a JSON file
  ifstream i(file_name);
  json     j;
  i >> j;
  this->cores     = j["cores"];
  this->segmentos = j["segmentos"];
  this->blocos    = j["blocos"];
  this->politica  = j["politica"];
  i.close();

  // write prettified JSON to another file ofstream o("pretty.json");
  // o << std::setw(4) << j << std::endl;
}