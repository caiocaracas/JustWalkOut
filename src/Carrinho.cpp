#include "Carrinho.hpp"
#include <iostream>

Carrinho::Carrinho(Estoque& estoque) : estoque(estoque) {}

void Carrinho::adicionarProduto(const Produto& produto) {
  produtos.push_back(&produto);
  estoque.removerProduto(produto, 1); // Atualiza o estoque ao adicionar ao carrinho
}

void Carrinho::removerProduto(const Produto& produto) {
  // Encontrar a posição do produto no carrinho
  auto it = std::remove(produtos.begin(), produtos.end(), &produto);

  // Remover o produto se encontrado
  if (it != produtos.end()) {
    produtos.erase(it);
    estoque.adicionarProduto(produto, 1); // Atualiza o estoque ao remover do carrinho
  }
}

void Carrinho::visualizarCarrinho() const {
  std::cout << "Produtos no carrinho:\n";
  for (const Produto* produto : produtos) {
    std::cout << produto->recebeNome() << " - R$" << produto->recebePreco() << "\n";
  }
  std::cout << "Total: R$" << calculaTotal() << "\n";
}

void Carrinho::finalizarCompra() {
  std::cout << "Compra finalizada!\n";
  produtos.clear(); // Limpa o carrinho
}

double Carrinho::calculaTotal() const {
  double total = 0;
  for (const Produto* produto : produtos) {
    total += produto->recebePreco();
  }
  return total;
}
