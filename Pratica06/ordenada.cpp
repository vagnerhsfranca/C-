#include <iostream>

using namespace std;

class ListaOrdenada {
private:
	int * items;
	int tamanho, capacidade;
public:
	ListaOrdenada(int cap) {
		this->capacidade = cap;
		this->tamanho = 0;
		items = new int[cap];
	}

	~ListaOrdenada() {
		delete [] items;
	}

	void insere(int key) {
        if(tamanho < capacidade){
            int i = tamanho-1;
            while(key < items[i]){
                items[i+1] = items[i];
                i--;
            }
            items[i+1] = key;
            tamanho++;
        }
	}

	int buscaSequencial(int key) {

		for(int i = 0; i <= tamanho; i++){
            if(items[i] == key)
                return i;
            if(items[i] > key)
                return -1;
		}
	}

	int buscaBinaria(int item) {
		return buscaBinaria(0, tamanho - 1, item);
	}

	int valida() {
		for (int i = 0; i < tamanho - 1; i++) {
			if (items[i] > items[i + 1]) return 0;
		}
		return 1;
	}

	void exibe() {
		for (int i = 0; i < tamanho; i++) {
			cout << i << ": " << items[i] << "; ";
		}
		cout << endl;
	}
	void remove(int key){
	    int indice = buscaBinaria(key);
	    if(tamanho > 0 && indice != -1){
            for(int i = indice ; i < capacidade; i++){
                items[i] = items[i+1]; //recebe o que havia na posicao a diante
            }
            tamanho--;
        }
    }

private:

	int buscaBinaria(int inicio, int final, int item) {
        if(inicio > final)
            return -1;

        int meio = ((inicio + final)/2);

        if(items[meio] == item)
            return meio;

        if(items[meio] > item)
            return buscaBinaria(inicio, meio-1, item);
        else
            return buscaBinaria(meio+1, final, item);

	}

};


int mainO() {

	ListaOrdenada lista(10);

	int elementos [] = {10, 5, 25, 1, 5, 13, 50, 99, 33, 12};

	for (int i = 0; i < 10; i++) {
		lista.insere(elementos[i]);
	}

	cout << "Lista v�lida: " << (lista.valida()?"sim":"n�o") << endl;

	lista.exibe();

	int teste [] = {5, 7, 16, 99, 45, 12, 33, 1, 60, 6};

	for (int i = 0; i < 10; i++) {
		cout << "Buscando " << teste[i] << ": sequencial = " << lista.buscaSequencial(teste[i]) << " binaria = " << lista.buscaBinaria(teste[i]) << endl;

	}

	for(int i = 0; i < 10; i++){//removendo
        lista.remove(teste[i]);
	}

	cout << endl << "REMOVENDO ELEMENTOS" << endl << "Lista apos remocao: ";
	lista.exibe();

}


