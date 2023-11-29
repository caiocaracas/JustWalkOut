#include "Produto.hpp"

Produto::Produto(const std::string& nome, double preco) : nome(nome), preco(preco) {}

const std::string& Produto::recebeNome() const {
  return nome;
}

double Produto::recebePreco() const {
  return preco;
}
