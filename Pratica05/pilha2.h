#include <iostream>

using namespace std;

template <class T>
class Pilha {

public:
    typedef struct No{
        T dado;
        No *prox;
    }itemPilha;

    int capacidade;
    int n_elementos;
    itemPilha *topo;

Pilha(int cap) {
// instancia array de items, inicializa capacidade e topo
    capacidade = cap;
    n_elementos = 0;
    topo = NULL;
}
~Pilha() {
// destroy array de items
}
void empilha(T item) {
// empilha um item no topo da pilha; lança “Estouro da pilha” se cheia
    if(n_elementos < capacidade){
        itemPilha *novo_no;

        if((novo_no=(itemPilha*)malloc(sizeof(itemPilha))) == NULL){
            throw "stack  overflow";
        }else{
            novo_no->dado = item;
            novo_no->prox = topo;
            topo = novo_no;
            ++n_elementos;
        }

    }else{
        throw "Pilha cheia";
    }
}
T desempilha() {
// remove um item do topo da pilha; lança “Pilha vazia” se vazia
    if(n_elementos > 0){

        itemPilha * temp;

        T valor = topo->dado;
        temp = topo;
        topo = topo->prox;

        temp->prox = NULL;
        free(temp);
        --n_elementos;
        return (valor);

    }else{
        throw "Pilha vazia";
    }
}
int tamanho() {
 // retorna o número de elementos na pilha.
 return n_elementos;
}
};
