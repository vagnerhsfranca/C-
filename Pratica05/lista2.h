
using namespace std;

template <class T>
class Lista {
private:
// itens da lista, capacidade e tamanho atual
    int capacidade;
    int n_elementos;

    typedef struct{
        int idx;
        T dado;
        No *prox;
    }No;

    typedef struct{
        No *inicio;

    }lista;

public:
Lista(int cap) {
// inicilização do array, capacidade e tamanho
    capacidade = cap;
    n_elementos = 0;
}
~Lista() {}
void adiciona (const T & item) {
// adiciona um item ao final da lista; lança “Lista cheia” caso cheia

}
T pega(int idx) {
// pega um item pelo indice (começa em 1);
// lança “Item inválido” se posição inválida
}

void insere (int idx, const T & item) {
// insere um item na posição indicada (a partir de 1).
// lança “Lista cheia” caso cheia
// lança “Item inválido” se posição inválida
// desloca itens existentes para a direita
}
void remove(int idx) {
// remove item de uma posição indicada
// lança “Item inválido” se posição inválida
// desloca itens para a esquerda sobre o item removido
}
void exibe() {
}
int tamanho() {
// retorna a quantidade de itens atualmente na lista
    return n_elementos;
}
};
