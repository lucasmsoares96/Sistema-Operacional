#include "../inc/escalonador.hpp"

#include <cstdlib>
#include <iterator>

#include "../inc/processo.hpp"

Escalonador::Escalonador(Kernel* kernel, string nome_arquivo) {
  tipos[0]           = "cpu-bound";
  tipos[1]           = "memory-bound";
  tipos[2]           = "io-bound";
  this->nome_arquivo = nome_arquivo;
  this->kernel       = kernel;
  this->politica     = kernel->politica;
  ler_processos();
}

void Escalonador::executar_politica() {
  if (this->politica == "round-robin") {
    // this->processos_novos.sort([](Processo p1, Processo p2) {
    //   return p1.prioridade > p2.prioridade;
    // });
    processos_prontos = processos_novos;
  }
  // for (Processo processo : processos_novos) {
  //   processos_prontos.push_back(processo);
  // }
}

void Escalonador::executar_mecanismo() {
  // logica verificar processo concluid
  processos_finalizados.clear();
  auto it_rem = processos_prontos.begin();
  while (it_rem != processos_prontos.end()) {
    it_rem->cnt_quantum = it_rem->max_quantum;
    if (it_rem->cnt_ciclos == 0) {
      processos_concluidos.push_back(*it_rem);
      it_rem = processos_prontos.erase(it_rem);
    } else {
      ++it_rem;
    }
  }
  if (processos_prontos.size() == 0) {
    return;
  }

  while (processos_bloqueados.size() != 0 ||
         processos_prontos.size() != 0) {
    // sortear quantum atual
    if (processos_prontos.size() != 0) {
      processo_executando = processos_prontos.front();
      processos_prontos.pop_front();
      int quantum = 1 + rand() % processo_executando.cnt_quantum;
      // Lógica de bloqueio
      if (processo_executando.tipo.back() == "memory-bound" ||
          processo_executando.tipo.back() == "io-bound") {
        if (processo_executando.punido == false &&
            processo_executando.punicao == 0) {
          processo_executando.punicao = 1 + rand() % 4;
          processos_bloqueados.push_back(processo_executando);
          continue;
        } else {
          processo_executando.punido = false;
        }
      }

      // Lógica de execução do processo
      kernel->processador->nucleos[0] = processo_executando;
      kernel->memoria->segmento[0]    = processo_executando;
      kernel->disco->gravar_em(0, processo_executando);
      for (int i = 0; i < quantum; i++) {
        usleep(1);
        // aumentar o timestap em todos os processos
        processo_executando.timestamp++;
        processo_executando.cnt_quantum--;

        for (auto& processo : processos_prontos) {
          processo.timestamp++;
        }
      }
    } else {
      // retornar bloqueados para final de prontos
      auto it = processos_bloqueados.begin();
      while (it != processos_bloqueados.end()) {
        it->timestamp++;
        // cout << "teste" << endl;
        it->punicao--;
        if (it->punicao == 0) {
          it->punido = true;
          processos_prontos.push_back(*it);
          it = processos_bloqueados.erase(it);
        } else {
          ++it;
        }
      }
      continue;
    }
    // sortear próximo típo

    //  adicionar prontos em finalizados
    // TODO: logica finalizados
    if (processo_executando.cnt_quantum == 0) {
      processo_executando.tipo.push_back(tipos[rand() % 3]);
      processo_executando.cnt_ciclos--;
      processos_finalizados.push_back(processo_executando);
      processos_finalizados.back().imprimir();
    } else {
      processos_prontos.push_back(processo_executando);
    }
  }
  processos_novos = processos_finalizados;
}

void Escalonador::ler_processos() {
  ifstream i(nome_arquivo);
  json     j;
  i >> j;
  string            nome_proc = "processo";
  long unsigned int adicional = 0;
  while (adicional < j["processos"].size()) {
    Processo novo_processo    = Processo();
    novo_processo.processo    = j["processos"][adicional]["processo"];
    novo_processo.ciclos      = j["processos"][adicional]["ciclos"];
    novo_processo.cnt_ciclos  = novo_processo.ciclos;
    novo_processo.max_quantum = j["processos"][adicional]["max_quantum"];
    novo_processo.tipo.push_back(j["processos"][adicional]["init_type"]);
    novo_processo.timestamp   = j["processos"][adicional]["timestamp"];
    novo_processo.prioridade  = j["processos"][adicional]["prioridade"];
    novo_processo.cnt_quantum = novo_processo.max_quantum;
    processos_novos.push_back(novo_processo);
    adicional += 1;
  }
  i.close();
}

void Escalonador::gerar_resultado() {
  ofstream f;
  f.open("resultado.json",ios_base::trunc |ios_base::out);
  for (auto& processo : processos_concluidos) {
    json j = {
        {"timestamp_total", processo.timestamp},{"ciclos_de_cpu",processo.ciclos},{"sequencia_das_acoes"}};
    f << j << endl;
  }
  f.close();
}

void Escalonador::executar_escalonador() {
  long unsigned int i = processos_novos.size();
  while (processos_concluidos.size() <= i) {
    cout << "exec" << endl;
    executar_politica();
    executar_mecanismo();
  }
  gerar_resultado();
}
