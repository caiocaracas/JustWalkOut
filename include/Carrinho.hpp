#ifndef CARRINHO_HPP
#define CARRINHO_HPP

#include <vector>
#include "Produto.hpp"

class Carrinho {
public:
  void adicionarProduto(const Produto& produto);
  void removerProduto(const Produto& produto);
  void visualizarCarrinho() const;
  void fecharCompra();
  double calculaTotal();
  // mudar forma de pagamento salva
  //

private:
  std::vector<const Produto*> produtos;
};

#endif