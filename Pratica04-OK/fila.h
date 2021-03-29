template <class T>

class Fila {

private:
// array de itens, capacidade, tamanho, posição inicial, etc.
    T * itens;
    int capacidade;
    int inicio;
    int n_elementos; //indica tambem o fim da fila

public:

    Fila(int cap) {
    // inicializar array de items, capacidade, tamanho, posição inicial
        capacidade = cap;
        itens = new T[capacidade];
        inicio = 0;
        n_elementos = 0;
    }

    ~Fila() {
    // destruir array de itens
        delete [] itens;
    }

    void enfileira(const T & item) {
    // adiciona um item ao final da fila; lança “Fila cheia” caso cheia
        if(n_elementos < capacidade){

            itens[n_elementos] = item;
            ++n_elementos;

        }else{
            throw "Fila cheia";
        }
    }

    T desenfileira() {
    // remove um item do inicio da fila; lança “Fila vazia” caso vazia
        if(n_elementos > 0){

            int inicioTemp = inicio;
            inicio = ++inicio % capacidade;
            --n_elementos;
            return itens[inicioTemp];

        }else{
            throw "Fila vazia";
        }
    }

    int cheia() {
    // retorna 1 se cheia, 0 caso contrário
        return (n_elementos == capacidade);//* remover ? ->
    }

    int vazia() {
    // retorna 1 se vazia, 0 caso contrário
       return (n_elementos == 0);
    }

    int tamanho() {
    // retorna a quantidade de itens atualmente na fila
        return n_elementos;
    }
};
