#include "../inc/escalonador.hpp"
#include <time.h>

Escalonador::Escalonador(Kernel* kernel, string nome_arquivo) {
  tipos[0]           = "cpu-bound";
  tipos[1]           = "memory-bound";
  tipos[2]           = "io-bound";
  this->nome_arquivo = nome_arquivo;
  this->kernel       = kernel;
  this->politica     = kernel->politica;
}

void Escalonador::executar_politica() {
  if (KILL_9 == true) return;
  if (this->politica == "round-robin") {
    processos_prontos = processos_novos;
  }else if(this->politica == "lru"){
    processos_prontos = processos_novos;
    this->processos_prontos.sort([](Processo p1, Processo p2) {
      return p1.rst_ciclos < p2.rst_ciclos;
    });
  }else if(this->politica == "mfp"){
    int contador=0;
    int cont_prioridade = 4;

    while(contador==0 && cont_prioridade!=0){
      contador = prioridadeMFP(contador,cont_prioridade);
      cont_prioridade-=1;
    }
    Processo processo_bilhete = Processo();
    if(cont_prioridade==1 && contador !=0){
      processos_prontos.clear();
      if(bilhetes.size()==0){
        processo_bilhete = processos_novos.front();
      }else{
        while(processo_bilhete.processo==0){
          processo_bilhete = bilhetes[rand() %bilhetes.size()];
        }
      }
      processos_prontos.push_back(processo_bilhete);
    }
    // cout << "TESTE ASDASDA: ";
    // cout << to_string(cont_prioridade) << endl;
  }
}

void Escalonador::executar_mecanismo() {
  // logica verificar processo concluido
  processos_finalizados.clear();
  auto it_rem2 = processos_novos.begin();
  while (it_rem2 != processos_novos.end()) {
    if (it_rem2->rst_ciclos <= 0.5) {
      it_rem2 = processos_novos.erase(it_rem2);
    } else {
      ++it_rem2;
    }
  }
  auto it_rem = processos_prontos.begin();
  while (it_rem != processos_prontos.end()) {
    if (KILL_9 == true) return;
    if (it_rem->rst_ciclos <= 0.5) {
      processos_concluidos.push_back(*it_rem);
      it_rem = processos_prontos.erase(it_rem);
    } else {
      ++it_rem;
    }
  }
  if (processos_prontos.size() == 0) {
    if(processos_bloqueados.size()==0){
      return;
    }else{
      reduzir_punicao();
      processos_novos = processos_prontos;
    }
  }
  while (processos_prontos.size() != 0) {
    if (KILL_9 == true) return;
    if (processos_prontos.size() != 0) {
      processo_executando = processos_prontos.front();
      processos_prontos.pop_front();
      float quantum = 1 + rand() % processo_executando.max_quantum;
            
      //bilhetes
      sortiar_limpar_bilhete();
      
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
      kernel->memoria->segmentos[0]   = processo_executando;
      kernel->disco->gravar_em(0, processo_executando);
      for (int i = 0; i < quantum; i++) {
        if (KILL_9 == true) return;
        //usleep(50000);
        reduzir_punicao();
        // aumentar o timestamp em todos os processos
        processo_executando.timestamp++;
        for (auto& processo : processos_prontos) {
          processo.timestamp++;
        }
        for (auto& novos : processos_novos) {
          novos.timestamp++;
        }
      }

      processo_executando.tipo.push_back(tipos[rand() % 3]);
      processo_executando.rst_ciclos -=
          quantum / processo_executando.max_quantum;
      if(processo_executando.prioridade > 1){
        processo_executando.prioridade-=1;
      }
      processo_executando.cnt_ciclos++;
      processos_finalizados.push_back(processo_executando);
     }
  }
  processo_executando = Processo();
  auto novos = processos_novos.begin();
  while (novos != processos_novos.end()) {
    auto finalizados = processos_finalizados.begin();
    while(finalizados != processos_finalizados.end()){
      if (novos->processo == finalizados->processo){
        *novos = *finalizados;
        finalizados = processos_finalizados.erase(finalizados);
      }
      ++finalizados;
    }
    auto bloqueados = processos_bloqueados.begin();    
    while(bloqueados != processos_bloqueados.end()){
      if (novos->processo == bloqueados->processo){
        novos = processos_novos.erase(novos);
      }
      ++bloqueados;
    }
    ++novos;
  }
  auto finalizados2 = processos_finalizados.begin();
  while(finalizados2 != processos_finalizados.end()){
    processos_novos.push_back(*finalizados2);
    ++finalizados2;
  }
}

void Escalonador::executar_escalonador() {
  ler_processos();
  processos_concluidos.clear();
  long unsigned int i = processos_novos.size();
  // clock_t begin = clock();
  while (processos_concluidos.size() < i) {
    if (KILL_9 == true) {
      limpar();
      return;
    }
    executar_politica();
    executar_mecanismo();
  }
  // clock_t end = clock();
  // double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
  // // cout << to_string(time_spent) << endl;
  gerar_resultado();
  limpar();
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
    novo_processo.rst_ciclos  = novo_processo.ciclos;
    novo_processo.max_quantum = j["processos"][adicional]["max_quantum"];
    novo_processo.tipo.push_back(j["processos"][adicional]["init_type"]);
    novo_processo.timestamp  = j["processos"][adicional]["timestamp"];
    novo_processo.prioridade = j["processos"][adicional]["prioridade"];
    processos_novos.push_back(novo_processo);
    adicional += 1;
  }
  i.close();
}

void Escalonador::gerar_resultado() {
  ofstream f;
  f.open("resultado.json");
  int  count = 0;
  json j;
  for (list<Processo>::iterator it = processos_concluidos.begin();
       it != processos_concluidos.end();
       ++it) {
    j["processos"][count]["processo"]    = it->processo;
    j["processos"][count]["timestamp"]   = it->timestamp;
    j["processos"][count]["ciclos"]      = it->ciclos;
    j["processos"][count]["cnt_ciclos"]  = it->cnt_ciclos;
    j["processos"][count]["max_quantum"] = it->max_quantum;
    j["processos"][count]["prioridade"]  = it->prioridade;
    j["processos"][count]["punicao"]     = it->punicao;
    j["processos"][count]["punido"]      = it->punido;
    j["processos"][count]["tipo"]        = it->tipo;
    count += 1;
  }
  f << j << endl;
  f.close();
}

void Escalonador::queueschell() {
  cout << "Processos Novos:\t";
  for (auto processo : processos_novos) {
    cout << processo.processo << "\t";
  }
  cout << endl;
  cout << "Processos Bloqueados:\t";
  for (auto processo : processos_bloqueados) {
    cout << processo.processo << "\t";
  }
  cout << endl;
  cout << "Processos Prontos:\t";
  for (auto processo : processos_prontos) {
    cout << processo.processo << "\t";
  }
  cout << endl;
  cout << "Processo em Execução:\t";
  cout << processo_executando.processo << endl;
  cout << "Processos Finalizados:\t";
  for (auto processo : processos_finalizados) {
    cout << processo.processo << "\t";
  }
  cout << endl;
  cout << "Processos Concluidos:\t";
  for (auto processo : processos_concluidos) {
    cout << processo.processo << "\t";
  }
  cout << endl;
  cout << endl;
}

void Escalonador::reduzir_punicao() {
  auto it = processos_bloqueados.begin();
  while (it != processos_bloqueados.end()) {
    if (KILL_9 == true) return;
    it->timestamp++;
    it->punicao--;
    if (it->punicao == 0) {
      it->punido = true;
      processos_prontos.push_back(*it);
      it = processos_bloqueados.erase(it);
    } else {
      ++it;
    }
  }
}

void Escalonador::sortiar_limpar_bilhete(){
  if(processo_executando.prioridade==1 && this->politica == "mfp"){
    for (auto& processo : processos_novos) {
      int teste=0;
      for (auto& bilhete : bilhetes){
        if(bilhete.processo==0){
          teste+=1;
          bilhete = processo;
        }
      }
      if(teste==0){
        bilhetes.push_back(processo);
      }
    }
    for (auto& processo : bilhetes){
      if(processo_executando.processo == processo.processo){
        processo = Processo();
      }
    }
  }
}

void Escalonador::limpar() {
  processos_bloqueados.clear();
  processos_finalizados.clear();
  processos_prontos.clear();
  processos_novos.clear();
  processo_executando = Processo();
  kernel->limpar();
}

int Escalonador::prioridadeMFP(int contador, int cont_prioridade){    
  auto it = processos_novos.begin();
  while (it != processos_novos.end()) {
    if(it->prioridade == cont_prioridade){
      Processo novo_processo = Processo();
      novo_processo = *it;
      processos_prontos.push_back(novo_processo);
      contador+=1;
    }
     ++it;
  }
  return contador; 
}