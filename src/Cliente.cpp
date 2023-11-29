#include "Cliente.hpp"
#include <iostream>

Cliente::Cliente(const std::string& nome, const std::string& dadosPagamento, Carrinho& carrinho, Vitrine& vitrine, Estoque& estoque)
    : nome(nome), dadosPagamento(dadosPagamento), carrinho(carrinho), vitrine(vitrine), estoque(estoque) {}

void Cliente::adicionarCarrinho(const Produto& produto) {
  vitrine.removerProduto(produto);
  carrinho.adicionarProduto(produto);
}

void Cliente::removerCarrinho(const Produto& produto) {
  carrinho.removerProduto(produto);
  vitrine.adicionarProduto(produto);
}

void Cliente::visualizarCarrinho() const {
  carrinho.visualizarCarrinho();
}

void Cliente::finalizarCompra() {
  carrinho.fecharCompra();
  for (const Produto* produto : carrinho.produtos) {
    estoque.removerProduto(*produto, 1); // Desconta do estoque permanentemente
  }
}
