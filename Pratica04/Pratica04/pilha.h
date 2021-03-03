template <class T>

class Pilha {

private:
// Atributos para array de items, capacidade e n_elementos da pilha
    T * itens;
    int capacidade;
    int n_elementos; // = n_elementos da pilha

public:

    Pilha(int cap) {
    // instancia array de items, inicializa capacidade e n_elementos
        capacidade = cap;
        itens = new T [capacidade];
        n_elementos = 0;
    }

    ~Pilha() {
    // destroy array de items
        delete [] itens;
    }

    void empilha(T item) {
    // empilha um item no n_elementos da pilha; lança “Estouro da pilha” se cheia
        if(n_elementos < capacidade){
            itens[n_elementos] = item;
            ++n_elementos;
        }else{
            throw "Estouro da pilha";
        }
    }

    T desempilha() {
    // remove um item do n_elementos da pilha; lança “Pilha vazia” se vazia
        if(n_elementos > 0){
        --n_elementos;
        return itens[n_elementos];
        }else{
            throw "Pilha vazia";
        }
    }

    int tamanho() {
     // retorna o número de elementos na pilha.
        return n_elementos;
    }
};
