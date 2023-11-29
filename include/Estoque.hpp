#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include <list>
#include "Produto.hpp"

class Estoque {
public:
  void adicionarProduto(const Produto& produto, int quantidade);
  void removerProduto(const Produto& produto, int quantidade);
  int qtdEstoque(const Produto& produto) const;
  const std::list<std::pair<const Produto*, int>>& listaEstoque() const;

private:
  std::list<std::pair<const Produto*, int>> produtosEstoque;
};

#endif