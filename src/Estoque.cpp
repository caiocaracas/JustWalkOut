#include "Estoque.hpp"
#include "Produto.hpp"

void Estoque::adicionarProduto(const Produto& produto, int quantidade) {
  for (auto& p : produtosEstoque) {
    if (p.first == &produto) {
      p.second += quantidade; // Produto já existe, apenas incrementa a quantidade
      return;
    }
  }
  produtosEstoque.push_back(std::make_pair(&produto, quantidade));
}

void Estoque::removerProduto(const Produto& produto, int quantidade) {
  auto it = produtosEstoque.begin();
  while (it != produtosEstoque.end()) {
    if (it->first == &produto) {
      it->second -= quantidade;
      if (it->second <= 0) {
        it = produtosEstoque.erase(it); // Remove se a quantidade se tornar zero ou negativa
      } else {
        ++it;
      }
    } else {
      ++it;
    }
  }
}

int Estoque::qtdEstoque(const Produto& produto) const {
  for (const auto& p : produtosEstoque) {
    if (p.first == &produto) {
      return p.second;
    }
  }
  return 0;
}

const std::list<std::pair<const Produto*, int>>& Estoque::listaEstoque() const {
  return produtosEstoque;
}
