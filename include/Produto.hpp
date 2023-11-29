#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <string>

class Produto {
public: 
  Produto(const std::string& nome, double preco);

  const std::string& recebeNome() const;
  double recebePreco() const;

private:
  std::string nome;
  double preco;
};

#endif