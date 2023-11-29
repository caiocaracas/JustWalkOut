#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include <list>
#include "Produto.hpp"

class Estoque {
public:
  void adicionarProduto(const Produto& produto, int quantidade);
  void removerProduto(const Produto& produto, int quantidade);
  int qtdEstoque(const Produto& produto) const;
  const std::list<Produto>& listaEstoque() const;

private:
  std::list<std::pair<Produto, int>> produtosNoEstoque;
};

#endif