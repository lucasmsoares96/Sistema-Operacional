#include "../inc/processo.hpp"

Processo::Processo() {
  // read a JSON file
  ifstream i("process.json");
  json     j;
  i >> j;
  this->QtdProcessos          = j["QtdProcessos"];
  this->IntervaloMediaCriacao = j["IntervaloMediaCriacao"];
  this->cpu_bound             = j["cpu_bound"];
  this->memoria_bound         = j["memoria_bound"];
  this->IO_boun               = j["IO_bound"];
  this->cpu_media             = j["cpu_media"];
  this->memoria_media         = j["memoria_media"];
  this->IO_media              = j["IO_media"];
  i.close();

  // write prettified JSON to another file ofstream o("pretty.json");
  // o << std::setw(4) << j << std::endl;
}