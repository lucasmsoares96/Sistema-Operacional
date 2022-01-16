#include "../inc/shell.hpp"

Shell::Shell(Escalonador *escalonador) {
  this->escalonador = escalonador;
}

void Shell::imprimir() {
  string entryShell = "";
  while (entryShell != "exit") {
    cout << "$ > ";
    cin >> entryShell;
    fflush(stdin);
    if (entryShell == "help") {
      system("clear");
      cout << "Lista de possiveis comandos:\n\n";
      help();
    } else if (entryShell == "meminfo") {
      system("clear");
      cout << "Meminfo:\n";
      escalonador->kernel->memoria->imprimir();
    } else if (entryShell == "cpuinfo") {
      system("clear");
      cout << "Cpuinfo:\n";
      escalonador->kernel->processador->imprimir();
    } else if (entryShell == "queueschell") {
      system("clear");
      cout << "Queueschell:\n";
    } else if (entryShell == "diskinfo") {
      system("clear");
      cout << "Diskinfo:\n";
      escalonador->kernel->disco->imprimir();
    } else if (entryShell == "execute") {
      system("clear");
      cout << "Arquivos carregados:\n";
      escalonador->executar_escalonador();
    } else if (entryShell == "kill -9") {
      system("clear");
      cout << "Kill -9:\n";
    } else if (entryShell == "exit") {
      system("clear");
      cout << "Saindo...\n";
    } else {
      system("clear");
      cout << "Fail\n";
    }
  }
}

void Shell::bold(int status) {
  static const char *seq[] = {"\x1b[0m", "\x1b[1m"};
  cout << seq[!!status];
}

void Shell::italic(int status) {
  static const char *seq[] = {"\x1b[0m", "\x1b[3m"};
  cout << seq[!!status];
}

void Shell::help() {
  italic(1);
  bold(1);
  cout << "help:\n";
  italic(0);
  bold(0);
  cout << "Informa todos comandos possiveis de ser executados.\n\n";
  italic(1);
  bold(1);
  cout << "meminfo:\n";
  italic(0);
  bold(0);
  cout << "Detalha quantas unidades de memoria do sistema possui, "
          "\nquantas "
          "estao livres, quantas estao alocadas e para quais "
          "processos.\n\n";
  italic(1);
  bold(1);
  cout << "cpuinfo:\n";
  italic(0);
  bold(0);
  cout << "Detalha qual processo esta em execucao, qual o timestamp e "
          "quantum.\n\n";
  italic(1);
  bold(1);
  cout << "diskinfo:\n";
  italic(0);
  bold(0);
  cout << "Quais blocos do sistema está sendo utilizado e seus "
          "componentes\n\n";
  italic(1);
  bold(1);
  cout << "queueschell:\n";
  italic(0);
  bold(0);
  cout << "Detalha quais processos estao sendogerenciados pelo seu "
          "sistema, "
          "\nquais estao em estado de 'prontos', 'bloqueados', \n'em "
          "execucao', 'criados' e 'finalizados'.\n\n";
  italic(1);
  bold(1);
  cout << "load:\n";
  italic(0);
  bold(0);
  cout << "Executa a fila de processos definida conforme configuracao "
          "previa.\n\n";
  italic(1);
  bold(1);
  cout << "kill -9:\n";
  italic(0);
  bold(0);
  cout << "Finaliza a execucao do sistema operacional, \nvoltando o mesmo "
          "para o estado inicial, \nem que os processos estariam ainda em "
          "faze de criacao inicial.\n\n";
}