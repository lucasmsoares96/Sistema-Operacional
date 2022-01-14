#ifndef __ESCALONADOR_HPP
#define __ESCALONADOR_HPP

#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <unistd.h>


#include "../inc/kernel.hpp"
#include "../inc/processo.hpp"

using namespace std;

class Escalonador {
 private:
  string          nome_arquivo;
  string          politica;
  list<Processo>  processos_novos;
  list<Processo>  processos_bloqueados;
  queue<Processo> processos_prontos;
  queue<Processo> processos_finalizados;
  Processo        processo_executando;
  Kernel*         kernel;

  void            ler_processos();

 public:
  Escalonador(Kernel* kernel, string nome_arquivo);
  void executar_politica();
  void executar_mecanismo();
};

#endif