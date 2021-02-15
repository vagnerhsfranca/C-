#include <iostream>
using namespace std;

template <class T>

class Arranjo {

private:
    int tamanho; // tamanho do arranjo
    T * itens; //items do arranjo

public:
    Arranjo(int tam) {
    // instanciar o array de items com new (pratica 1) e setar tamanho;
        this->tamanho=tam;
        this->itens = new T[tam];
    }
virtual ~Arranjo() {
// destruir o array de items (prática 1);
    delete [] itens;
    cout << "Arranjo destruido" << endl;
}
virtual T get(int idx) {
// retornar um item do array a partir do indice;
    if(idx < 0 || idx > tamanho-1){
        throw "Erro";
    }else{
    return itens[idx];
    }
}
virtual void set(int idx, const T & item) {
// set o item do array apontado pelo indice usando =
    if(idx < 0 || idx > tamanho-1){
        throw "Erro";
    }else{
    this->itens[idx] = item;
    }
}
virtual void exibir();
};
template<class T>
void Arranjo<T>::exibir() {
// exibir cada item numa linha da forma "<idx>: <item>"
    for(int i=0; i<tamanho ; i++){
        cout << "<" << i << ">: " << itens[i] << endl;
    }
}
