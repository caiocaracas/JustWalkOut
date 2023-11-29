#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include "Carrinho.hpp"

class Cliente {
public:
  Cliente(const std::string& nome, const std::string& dadosPagamento);

  void adicionarCarrinho(const Produto& produto);
  void removerCarrinho(const Produto& produto);
  void visualizarCarrinho() const;
  void finalizarCompra();

private:
  std::string nome;
  std::string dadosPagamento;
  Carrinho carrinho;
};

#endif 