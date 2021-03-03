template <class T>
class Fila {

public:
    typedef struct No{
        T dado;
        No *prox;
    }No;

    typedef struct fila{
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
    ordem=(fila*)malloc(sizeof(fila));
        if(ordem == NULL)
            throw "list overflow";
        else{
            ordem->fim = NULL;
            ordem->inicio = NULL;
        }
}
~Fila() {}

void enfileira(const T & item) {
// adiciona um item ao final da fila; lança “Fila cheia” caso cheia
    if(n_elementos < capacidade){
        No *novo_no=(No*)malloc(sizeof(No));

        if(novo_no == NULL)
            throw "list overflow";
        else{
            novo_no->dado = item;
            novo_no->prox = NULL;

            if(ordem->inicio == NULL)
                ordem->inicio = novo_no;
            else
                ordem->fim->prox = novo_no;

            ordem->fim =novo_no;

        }
     ++n_elementos;
    }else
        throw "Fila cheia";
}
T desenfileira() {
// remove um item do inicio da fila; lança “Fila vazia” caso vazia
    if(n_elementos > 0){

        No *temp=(No*)malloc(sizeof(No));

        if(ordem->inicio == NULL)
            throw "lista vazia";
        if(temp == NULL)
            throw "fila overflow";

        temp = ordem->inicio;
        ordem->inicio = ordem->inicio->prox;

        if(ordem->inicio == NULL)
            ordem->fim = NULL;


        T dados = temp->dado;
        temp->prox = NULL;
        free(temp);
        --n_elementos;
        return dados;

    }else
        throw "Fila vazia";
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
