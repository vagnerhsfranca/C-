template <class T>
class Pilha {
private:
// Atributos para array de items, capacidade e topo da pilha
    T * itens;
    int tam, topo, n_elementos;

public:
    Pilha(int capacidade) {
// instancia array de items, inicializa capacidade e topo
    tam = capacidade;
    itens = new T [capacidade];
    topo = 0;
    n_elementos=0;
}
~Pilha() {
// destroy array de items
    delete [] itens;
}
void empilha(T item) {
// empilha um item no topo da pilha; lança “Estouro da pilha” se cheia
    if(topo < tam){
        itens[topo] = item;
        ++topo;
        ++n_elementos;
    }else{
        throw "Estouro da pilha";
    }
}
T desempilha() {
// remove um item do topo da pilha; lança “Pilha vazia” se vazia
    if(topo > 0){
    --topo;
    --n_elementos;
    return itens[topo];
        }else{
            throw "Pilha vazia";
        }
}
int tamanho() {
 // retorna o número de elementos na pilha.
    return (n_elementos);
}
};
