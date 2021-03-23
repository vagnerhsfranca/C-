template <class T>

class PilhaInterface{

protected:

    int n_elementos;//tambem indica o topo da pilha
    int capacidade;//capacidade de elementos suportados na pilha

public:

    PilhaInterface(){}

    PilhaInterface(int cap){
        this->capacidade = cap;
        this->n_elementos = 0;
    }

    virtual ~PilhaInterface(){}

    virtual void empilha(T item)=0;

    virtual T desempilha(){}

    int tamanho(){
        return n_elementos;
    }

};

template <class T>

class PilhaArray : public virtual PilhaInterface{

private:
// Atributos para array de items, capacidade e n_elementos da pilha
    T * itens;

public:

    PilhaArray () : PilhaInterface {}

    PilhaArray(int cap) : PilhaInterface(cap){
    // instancia array de items, inicializa capacidade e n_elementos
        itens = new T[capacidade];
    }

    virtual ~PilhaArray() {
    // destroy array de items
        delete [] itens;
    }

    virtual void empilha(T item) {
    // empilha um item no n_elementos da pilha; lança “Estouro da pilha” se cheia
        if(n_elementos < capacidade){
            itens[n_elementos] = item;
            ++n_elementos;
        }else{
            throw "Estouro da pilha";
        }
    }

    virtual T desempilha() {
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
        return this->n_elementos;
    }
};
