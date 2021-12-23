#ifndef __READJSON_HPP
#define __READJSON_HPP

#include <fstream>
#include <iostream>
#include <string>

#include "../lib/json.hpp"
using json = nlohmann::json;

using namespace std;

class Processo {
 private:
 public:
  int   QtdProcessos;
  int   IntervaloMediaCriacao;
  float cpu_bound;
  float memoria_bound;
  float IO_boun;
  int   cpu_media;
  int   memoria_media;
  int   IO_media;
  Processo();
};
#endif
