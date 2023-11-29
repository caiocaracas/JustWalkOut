include "Vitrine.hpp"

void Vitrine::adicionarProduto(const Produto& produto) {
  // Verifica se o produto já está na vitrine
  bool produtoExistente = false;
  for (const Produto* p : produtosNaVitrine) {
    if (p == &produto) {
      produtoExistente = true;
      break;
    }
  }

  // Adiciona o produto à vitrine se não existir
  if (!produtoExistente) {
    produtosNaVitrine.push_back(&produto);
    estoque.adicionarProduto(produto, 1); 
    // Atualiza o estoque ao adicionar à vitrine
  }}

void Vitrine::removerProduto(const Produto& produto) {
  // Encontra a posição do produto na vitrine
  size_t pos = 0;
  for (const Produto* p : produtosNaVitrine) {
    if (p == &produto) {
      break;
    }
    ++pos;
  }

  // Remove o produto se encontrado
  if (pos < produtosNaVitrine.size()) {
    produtosNaVitrine.erase(produtosNaVitrine.begin() + pos);
    estoque.removerProduto(produto, 1); // Atualiza o estoque ao remover da vitrine
  }}

const std::list<const Produto*>& Vitrine::obterProdutos() const {
  return produtosNaVitrine;
}
