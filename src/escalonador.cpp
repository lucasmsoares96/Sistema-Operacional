#include "../inc/escalonador.hpp"

#include "../inc/processo.hpp"

Escalonador::Escalonador(Kernel* kernel, string nome_arquivo) {
  this->nome_arquivo = nome_arquivo;
  this->politica     = nome_arquivo;
  this->kernel       = kernel;
  ler_processos();
  executar_politica();
  executar_politica();
}

void Escalonador::executar_politica() {
  if (this->politica == "round-robin") {
    // this->processos_novos.sort([](Processo p1, Processo p2) {
    //   return p1.prioridade > p2.prioridade;
    // });
  }
  for (Processo processo : processos_novos) {
    processos_prontos.push(processo);
  }
}

void Escalonador::ler_processos() {
  ifstream i(nome_arquivo);
  json     j;
  i >> j;

  string            nome_proc = "processo";
  long unsigned int adicional = 1;

  while (adicional <= j["processos"].size()) {
    Processo novo_processo    = Processo();
    novo_processo.processo    = j["processos"][adicional]["processo"];
    novo_processo.ciclos      = j["processos"][adicional]["ciclos"];
    novo_processo.max_quantum = j["processos"][adicional]["max_quantum"];
    novo_processo.type        = j["processos"][adicional]["init_type"];
    novo_processo.timestamp   = j["processos"][adicional]["timestamp"];
    novo_processo.prioridade  = j["processos"][adicional]["prioridade"];
    processos_novos.push_front(novo_processo);

    // cout << "Processo:" << novo_processo.processo
    //      << " \tCiclos:" << novo_processo.ciclos
    //      << " \tmax_quantum:" << novo_processo.max_quantum
    //      << " \tinit_type:" << novo_processo.init_type
    //      << " \ttimestamp:" << novo_processo.timestamp
    //      << " \tprioridade:" << novo_processo.prioridade << endl;
    adicional += 1;
  }
  i.close();
}

void Escalonador::executar_mecanismo() {
  srand(time(NULL));

  while (processos_bloqueados.size() != 0 &&
         processos_prontos.size() != 0) {
    processo_executando = processos_prontos.front();
    processos_prontos.pop();

    if (processo_executando.type == "memory-bound" ||
        processo_executando.type == "io-bound") {
      processo_executando.punicao = 1 + rand() % 4;
      processos_bloqueados.push_back(processo_executando);
      continue;
    }

    kernel->processador->nucleos[1].processo = processo_executando;
    kernel->processador->nucleos[1].estado   = Ocupado;
    usleep(1);
  }
}
