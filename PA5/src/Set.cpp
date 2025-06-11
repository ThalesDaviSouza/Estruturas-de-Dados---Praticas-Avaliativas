#include "Set.hpp"

int StringSet::Hash(string s) {
  int hash = 0;
  for (char c : s) {
    hash = (hash * 31 + c) % this->tamanhoTabela;
  }
  return hash;
}

StringSet::StringSet(int tamanho) {
  this->tamanhoOriginal = tamanho;
  this->tamanhoTabela = tamanho;
  this->tamanhoConjunto = 0;
  this->tabela = new ElementoTabela[this->tamanhoTabela];

  for (int i = 0; i < this->tamanhoTabela; i++) {
    this->tabela[i].vazio = true;
    this->tabela[i].retirada = false;
  }
}

StringSet::~StringSet() {
  delete[] this->tabela;  
}

void StringSet::Resize(size_t novoTamanho) {

  ElementoTabela* antigaTabela = this->tabela;
  int antigoTamanho = this->tamanhoTabela;

  this->tabela = new ElementoTabela[novoTamanho];
  this->tamanhoTabela = novoTamanho;
  this->tamanhoConjunto = 0;

  for (int i = 0; i < this->tamanhoTabela; i++) {
    this->tabela[i].vazio = true;
    this->tabela[i].retirada = false;
  }

  for (int i = 0; i < antigoTamanho; i++){
    if (!antigaTabela[i].vazio && !antigaTabela[i].retirada){
      this->Inserir(antigaTabela[i].dado);
    } 
  }

  delete[] antigaTabela;
}

void StringSet::Inserir(string s) {
  if (this->tamanhoConjunto >= this->tamanhoTabela / 2){
    this->Resize(this->tamanhoTabela * 2);
  } 

  int pos = this->Hash(s);
  int inicial = pos;

  do {
    if (this->tabela[pos].vazio) {
      this->tabela[pos].dado = s;
      this->tabela[pos].vazio = false;
      this->tabela[pos].retirada = false;
      this->tamanhoConjunto++;

      return;
    }
    else if (!this->tabela[pos].retirada && this->tabela[pos].dado == s) {
      return;
    }

    pos = (pos + 1) % this->tamanhoTabela;

  } while (pos != inicial);
}

void StringSet::Remover(string s) {
  int pos = this->Hash(s);
  int inicial = pos;

  do {
    if (this->tabela[pos].vazio) {
      return;
    }
    if (!this->tabela[pos].retirada && this->tabela[pos].dado == s) {
      this->tabela[pos].retirada = true;
      this->tamanhoConjunto--;
      return;
    }

    pos = (pos + 1) % this->tamanhoTabela;

  } while (pos != inicial);
}

bool StringSet::Pertence(string s) {
  int pos = this->Hash(s);
  int inicial = pos;

  do {
    if (this->tabela[pos].vazio) {
      return false;
    }
    if (!this->tabela[pos].retirada && this->tabela[pos].dado == s) {
      return true;
    }

    pos = (pos + 1) % this->tamanhoTabela;

  } while (pos != inicial);

  return false;
}

StringSet* StringSet::Intersecao(StringSet* S) {
  StringSet* resultado = new StringSet(this->tamanhoOriginal);

  for (int i = 0; i < this->tamanhoTabela; i++){
    if (!this->tabela[i].vazio && !this->tabela[i].retirada && S->Pertence(this->tabela[i].dado)){
      resultado->Inserir(this->tabela[i].dado);
    }
  }

  return resultado;
}

StringSet* StringSet::Uniao(StringSet* S) {
  StringSet* resultado = new StringSet(this->tamanhoOriginal + S->tamanhoTabela);

  for (int i = 0; i < this->tamanhoTabela; i++){
    if (!this->tabela[i].vazio && !this->tabela[i].retirada){
      resultado->Inserir(this->tabela[i].dado);
    }
  }

  for (int i = 0; i < S->tamanhoTabela; i++){
    if (!S->tabela[i].vazio && !S->tabela[i].retirada){
      resultado->Inserir(S->tabela[i].dado);
    }
  }

  return resultado;
}

StringSet* StringSet::DiferencaSimetrica(StringSet* S) {
  StringSet* resultado = new StringSet(this->tamanhoOriginal + S->tamanhoTabela);

  for (int i = 0; i < this->tamanhoTabela; i++){
    if (!this->tabela[i].vazio && !tabela[i].retirada && !S->Pertence(this->tabela[i].dado)){
      resultado->Inserir(this->tabela[i].dado);
    }
  }

  for (int i = 0; i < S->tamanhoTabela; i++){
    if (!S->tabela[i].vazio && !S->tabela[i].retirada && !this->Pertence(S->tabela[i].dado)){
      resultado->Inserir(S->tabela[i].dado);
    }
  }

  return resultado;
}

void StringSet::OrdenarSaida(string* array, int tamanho) {
  for (int i = 0; i < tamanho - 1; i++) {
    int menor = i;
    for (int j = i + 1; j < tamanho; j++) {
      if (array[j] < array[menor]) {
        menor = j;
      }
    }
    if (menor != i) {
      string temp = array[i];
      array[i] = array[menor];
      array[menor] = temp;
    }
  }
}

void StringSet::Imprimir() {
  string* saida = new string[this->tamanhoTabela];
  int tamSaida = 0;

  for (int i = 0; i < this->tamanhoTabela; i++){
    if (!this->tabela[i].vazio && !this->tabela[i].retirada) {
      saida[tamSaida] = this->tabela[i].dado;
      tamSaida++;
    }
  }

  OrdenarSaida(saida, tamSaida);

  for (int i = 0; i < tamSaida; i++) {
    cout << saida[i] << " ";
  }

  cout << endl;
}
