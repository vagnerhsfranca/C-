template <class T>
class Fila {
private:
// array de itens, capacidade, tamanho, posição inicial, etc.
T * itens;
int capacidade;
int tam; //qnt de itens na fila;
int posInicial;
int posFinal;

public:
Fila(int cap) {
// inicializar array de items, capacidade, tamanho, posição inicial
    this->capacidade = cap;
    itens = new T[capacidade];
    this->posInicial = 0;
    this->posFinal = 0;
    this->tam = 0;
}
~Fila() {
// destruir array de itens
    delete [] itens;
}
void enfileira(const T & item) {
// adiciona um item ao final da fila; lança “Fila cheia” caso cheia
    if(tam < capacidade){
        itens[posFinal] = item;
        tam++;

        if(posFinal+1 > capacidade-1){
            posFinal = 0;
        }else{
            posFinal++;
        }

    }else{
        throw "Fila cheia";
    }
}
T desenfileira() {
// remove um item do inicio da fila; lança “Fila vazia” caso vazia
    if(tam > 0){
        --tam;
        if(posInicial+1 <= capacidade-1){
            return itens[posInicial++];
        }else{
            return itens[posInicial];
            posInicial=0;
        }

    }else{
        throw "Fila vazia";
    }
}
int cheia() {
// retorna 1 se cheia, 0 caso contrário
    return (tam == capacidade) ? 1:0;
}
int vazia() {
// retorna 1 se vazia, 0 caso contrário
   return (tam == 0) ? 1:0;
}
int tamanho() {
// retorna a quantidade de itens atualmente na fila
    return this->tam;
}
};
