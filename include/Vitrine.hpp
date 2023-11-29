#ifndef VITRINE_HPP
#define VITRINE_HPP

#include <list>
#include "Produto.hpp"

class Vitrine {
public:
  void adicionarProduto(const Produto& produto);
  void removerProduto(const Produto& produto);
  const std::list<Produto*>& obterProdutos() const;

private:
  std::list<const Produto*> produtosNaVitrine;
};

#endif
