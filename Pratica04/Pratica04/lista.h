using namespace std;

template <class T>

class Lista {

private:
// itens da lista, capacidade e n_elementosanho atual
    T * itens;
    int capacidade;
    int n_elementos; // = final da lista

public:

    Lista(int cap) {
    // inicilização do array, capacidade e n_elementosanho
        capacidade = cap;
        itens = new T[capacidade];
        n_elementos = 0;
    }

    ~Lista() {
    //destruição do array
        delete [] itens;
    }

    void adiciona (const T & item) {
    // adiciona um item ao final da lista; lança “Lista cheia” caso cheia
        if(n_elementos < capacidade){
            itens[n_elementos % capacidade] = item;
            ++n_elementos;
        }else{
            throw "Lista cheia";
        }
    }

    T pega(int idx) {
    // pega um item pelo indice (começa em 1);
    // lança “Item inválido” se posição inválida
        if(n_elementos > 0){

            if(idx <= capacidade || idx >= 1){
                return itens[idx-1];
            }else{
                throw "Item invalido";
            }

        }else{
            throw "Lista vazia";
        }
    }

    void insere (int idx, const T & item) {
    // insere um item na posição indicada (a partir de 1).
    // lança “Lista cheia” caso cheia
    // lança “Item inválido” se posição inválida
    // desloca itens existentes para a direita
        if(n_elementos < capacidade){

                if(idx > capacidade || idx < 1){
                    throw "Item invalido";
                }else{
                    for(int i = n_elementos; i >= idx-1; i--){
                        itens[i + 1] = itens[i];
                    }
                    itens[idx-1] = item;
                    ++n_elementos;
                }

        }else{
            throw "Lista cheia";
        }
    }

    void remove(int idx) {
    // remove item de uma posição indicada
    // lança “Item inválido” se posição inválida
    // desloca itens para a esquerda sobre o item removido
        if(n_elementos > 0){

            if(idx > capacidade || idx < 1){
                throw "Item invalido";
            }else{
                for(int i=idx-1; i < capacidade; i++){
                    itens[i] = itens[i+1]; //recebe o que havia na posicao a diante
                }
            }

            --n_elementos;

        }else{
            throw "Fila vazia";
        }
    }

    void exibe() {
    // exibe os itens da saida padrão separados por espaços
        for(int i=0; i < n_elementos; i++){
            cout << itens[i] << " ";
        }
        cout << endl;
    }

    int tamanho() {
    // retorna a quantidade de itens atualmente na lista
        return n_elementos;
    }
};
