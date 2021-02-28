#include <iostream>

using namespace std;

template <class T>
class Fila {

public:
    typedef struct No{
    T dado;
    No *prox;
    }No;

    typedef struct{
        No *inicio;
        No *fim;
    }fila;

    fila *ordem;
    int capacidade;
    int n_elementos;


Fila(int cap) {
// inicializar array de items, capacidade, tamanho, posição inicial
    capacidade = cap;
    n_elementos = 0;
    ordem->fim = NULL;
    ordem->inicio = NULL;
}
~Fila() {}

void enfileira(const T & item) {
// adiciona um item ao final da fila; lança “Fila cheia” caso cheia
    if(n_elementos < capacidade){
        No *novo_no=(No*)malloc(sizeof(No));

        if(novo_no == NULL){
            throw "list overflow";
        }else{
            novo_no->dado = item;
            novo_no->prox = NULL;
            ++n_elementos;

            if(ordem->inicio == NULL){
                ordem->inicio = novo_no;
            }else{
                ordem->fim->prox = novo_no;
            }

            ordem->fim =novo_no;
        }

    }else{
        throw "Fila cheia";
    }
}
T desenfileira() {
// remove um item do inicio da fila; lança “Fila vazia” caso vazia
    if(n_elementos > 0){

        T valor;
        No *temp = ordem->inicio;

        if(temp != NULL){
            ordem->inicio = temp->prox;
            temp->prox = NULL;
            valor = temp->dado;
            free(temp);
                if(ordem->inicio == NULL){
                    ordem->fim = NULL;
                }
            --n_elementos;
            return valor;
        }else {
           throw "Fila vazia";
        }
    }else{
        throw "Fila vazia";
    }

}
int cheia() {
// retorna 1 se cheia, 0 caso contrário
    return (n_elementos == capacidade) ? 1:0;
}
int vazia() {
// retorna 1 se vazia, 0 caso contrário
   return (n_elementos == 0) ? 1:0;
}
int tamanho() {
// retorna a quantidade de itens atualmente na fila
    return n_elementos;
}
};
