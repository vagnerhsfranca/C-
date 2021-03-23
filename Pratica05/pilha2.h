#include <iostream>

using namespace std;

template <class T>
class Pilha
{

private:

    typedef struct No{
        T dado;
        No *prox;
    };

    int capacidade;
    int n_elementos;
    No *topo;

public:

    Pilha(int cap)
    {
        // instancia array de items, inicializa capacidade e topo
        capacidade = cap;
        n_elementos = 0;
        topo = NULL;
    }

    ~Pilha()
    {
        // destroy array de items
        // implementar o desempilha até ficar fazia
        while(n_elementos > 0){
            desempilha();
            --n_elementos;
        }

    }

    void empilha(T item)
    {
// empilha um item no topo da pilha; lança “Estouro da pilha” se cheia
        if(n_elementos < capacidade)
        {
            No *novo_no;

            if((novo_no = new No) == NULL){//caso o programa não consiga alocar memória para o objeto
                throw "stack overflow";
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

    T desempilha()
    {
// remove um item do topo da pilha; lança “Pilha vazia” se vazia
        if(n_elementos > 0){

            No *temp;

            T valor = topo->dado;
            temp = topo;
            topo = topo->prox;

            --n_elementos;
            delete temp;
            return (valor);

        }else{
            throw "Pilha vazia";
        }
    }

    int tamanho()
    {
// retorna o número de elementos na pilha.
        return n_elementos;
    }
};
