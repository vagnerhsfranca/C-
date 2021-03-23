template <class T>
class Fila
{

private:

    typedef struct No{
        No *inicio;
        No *fim;
        T dado;
        No *prox;
    };

    No* fila;
    int capacidade;
    int n_elementos;

public:

    Fila(int cap){
    // inicializar array de items, capacidade, tamanho, posição inicial
        capacidade = cap;
        n_elementos = 0;

        fila->fim = NULL;
        fila->inicio = NULL;
    }

    ~Fila() {

        while(n_elementos > 0){
            desenfileira();
            --n_elementos;
        }
    }

    void enfileira(const T & item)
    {
    // adiciona um item ao final da fila; lança “Fila cheia” caso cheia
        if(n_elementos < capacidade)
        {
            No *novo_no;

            if((novo_no = new No) == NULL){//caso o programa não consiga alocar memória para o objeto
                throw "list overflow";

            }else{
                novo_no->dado = item;
                novo_no->prox = NULL;

                if(fila->inicio == NULL)
                    fila->inicio = novo_no;
                else
                    fila->fim->prox = novo_no;

                fila->fim =novo_no;
            }
            ++n_elementos;

        }else
            throw "Fila cheia";
    }

    T desenfileira()
    {
    // remove um item do inicio da fila; lança “Fila vazia” caso vazia
        if(n_elementos > 0){

            No *temp;

            temp = fila->inicio;
            fila->inicio = fila->inicio->prox;

            T dados = temp->dado;
            --n_elementos;
            delete temp;
            return dados;

        }else
            throw "Fila vazia";
    }

    int cheia(){
    // retorna 1 se cheia, 0 caso contrário
        return (n_elementos == capacidade);
    }

    int vazia(){
    // retorna 1 se vazia, 0 caso contrário
        return (n_elementos == 0);
    }

    int tamanho(){
    // retorna a quantidade de itens atualmente na fila
        return n_elementos;
    }
};
