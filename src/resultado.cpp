#include "../inc/resultado.hpp"

#include <fstream>
#include <ios>

Resultado::Resultado() {
  ofstream f;
  f.open("resultado.json", ios_base::trunc | ios_base::out);

  json j = {
      {    "timestamp_total",           1},
      { "ciclos_de_cpu",           2                    },
      { "sequencia_das_acoes", "cpu_bound",                  "memory_bound"}
  };
  f << j;
  f.close();
}