#include <iostream>

using namespace std;

template <class T>
class Lista {

public:

    typedef struct No{
        T dado;
        No *prox;
    }No;

    typedef struct lista{
        No *inicio;
        No *fim;
    }lista;

    lista *controlador;
    int capacidade;
    int n_elementos;

Lista(int cap) {
// inicilização do array, capacidade e tamanho
    capacidade = cap;
    n_elementos = 0;
    controlador=(lista*)malloc(sizeof(lista));
        if(controlador != NULL){
            controlador->inicio = NULL;
            controlador->fim = NULL;
        }else{
            throw "list overflow";
        }
}
~Lista() {}

void adiciona (const T & item) {
// adiciona um item ao final da lista; lança “Lista cheia” caso cheia
    if(n_elementos < capacidade){
        No *novo_no=(No*)malloc(sizeof(No));

            if(novo_no == NULL){
                throw "list overflow";
            }else{
                novo_no->dado = item;
                novo_no->prox = NULL;

                if(controlador->inicio == NULL){
                    controlador->inicio = novo_no;
                }else{
                    controlador->fim->prox = novo_no;
                }
                controlador->fim = novo_no;
            }
        ++n_elementos;
    }else{
        throw "list overflow";
    }
}
T pega(int idx) {
// pega um item pelo indice (começa em 1);
// lança “Item inválido” se posição inválida
    if(n_elementos > 0){
        if(idx >= 1 || idx <= capacidade){

            No *temp=(No*)malloc(sizeof(No));
            if(temp == NULL)
                throw "list overflow";

            temp = controlador->inicio;
            --idx;
            while(idx != 0){
                temp = temp->prox;
                --idx;
                }
             return temp->dado;
        }else
            throw "indice invalido";
    }else{
        throw "lista vazia";
    }
}

void insere (int idx, const T & item) {
// insere um item na posição indicada (a partir de 1).
// lança “Lista cheia” caso cheia
// lança “Item inválido” se posição inválida
// desloca itens existentes para a direita

	if(n_elementos < capacidade){
		if(idx >= 1 || idx <= capacidade){
			No *novo_no, *temp;

			if((novo_no=(No*)malloc(sizeof(No))) == NULL)
				throw "list overflow";
			if((temp=(No*)malloc(sizeof(No))) == NULL)
                throw "list overflow";

            novo_no->dado = item;
            if(idx == 1){//adicionar na posicao 1
                novo_no->prox = controlador->inicio;
                controlador->inicio = novo_no;
            }else{
                temp = controlador->inicio;
                int i=1;
                while(i < idx-1){
                    temp = temp->prox;
                    ++i;
                }
                novo_no->prox = temp->prox;
                temp->prox = novo_no;
                temp = NULL;
                free(temp);
            }
        ++n_elementos;
		}
    }
}
T remove(int idx) {
// remove item de uma posição indicada
// lança “Item inválido” se posição inválida
// desloca itens para a esquerda sobre o item removido
	if(n_elementos > 0){
		if(idx >= 1 || idx <= capacidade){
                No *temp, *aux;
			if((temp=(No*)malloc(sizeof(No))) == NULL)
				throw "list overflow";
            if((aux=(No*)malloc(sizeof(No))) == NULL)
                throw "list overflow";

            if(idx == 1){//remove do inicio
                temp = controlador->inicio;
                controlador->inicio = controlador->inicio->prox;

                if(controlador->fim == temp)//se temp 1º e unico elemento
                    controlador->fim = NULL;
            }else{//remover do meio
                aux = controlador->inicio;
                int i = 1;
                while(i < idx-1){
                    aux = aux->prox;
                    ++i;
                }
                temp = aux->prox;

                if(controlador->fim == temp)
                    controlador->fim = aux;

                aux->prox = aux->prox->prox;
            }
            T valor = temp->dado;
            temp = NULL;
            free(temp);
            --n_elementos;
            return valor;
        }else{
            throw "indice invalido";
        }
    }else
        throw "lista vazia";
}
void exibe() {
     if(controlador->inicio == NULL){
        throw "lista vazia";
     }else{
         No *temp;
         if((temp=(No*)malloc(sizeof(No))) == NULL){
            throw "list overflow";
         }else{
             for(int i=1; i < n_elementos; i++) {
                cout << temp->dado << " ";
                temp = temp->prox;
            }
            cout << endl;
            temp = NULL;
            free(temp);
        }
    }
}
int tamanho() {
// retorna a quantidade de itens atualmente na lista
    return n_elementos;
}
};
