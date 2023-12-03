#include "Produto.hpp"
#include "Carrinho.hpp"
#include "Estoque.hpp"
#include "Vitrine.hpp"
#include "Cliente.hpp"
#include <iostream>

int main() {
  // Criando alguns produtos
  Produto produto1("Produto 1", 10.0);
  Produto produto2("Produto 2", 20.0);
  Produto produto3("Produto 3", 15.0);

  // Criando um estoque
  Estoque estoque;
  estoque.adicionarProduto(produto1, 5);
  estoque.adicionarProduto(produto2, 10);
  estoque.adicionarProduto(produto3, 8);

  // Criando uma vitrine vinculada ao estoque
  Vitrine vitrine(estoque);

  // Adicionando produtos à vitrine
  vitrine.adicionarProduto(produto1);
  vitrine.adicionarProduto(produto2);
  vitrine.adicionarProduto(produto3);

  // Criando um carrinho
  Carrinho carrinho(estoque);

  // Criando um cliente
  Cliente cliente("Cliente1", "1234-5678", carrinho, vitrine, estoque);

  // Cliente adiciona produtos ao carrinho
  cliente.adicionarCarrinho(produto1);
  cliente.adicionarCarrinho(produto2);

  // Visualizando carrinho
  cliente.visualizarCarrinho();

  // Cliente remove produto do carrinho
  cliente.removerCarrinho(produto1);

  // Visualizando carrinho novamente
  cliente.visualizarCarrinho();

  // Cliente finaliza a compra
  cliente.finalizarCompra();

  // Visualizando estoque após a compra
  std::cout << "\nEstoque após a compra:\n";
  for (const auto& [produto, quantidade] : estoque.listaEstoque()) {
    std::cout << produto->recebeNome() << " - Quantidade: " << quantidade << "\n";
  }

  return 0;
}
