#include <iostream>
#include <queue>

#define MAX 100

using namespace std;

int mainF2() {
	std::queue<int> fila;

	try {
		cerr << "Testando enfileira() [normal]: ";
		for (int i = 0; i < MAX; i++) {
			fila.push(i);
		}
		cerr << "OK" << endl;
	} catch (...) {
		cerr << "FALHOU!" << endl;
		exit(1);
	}

	cerr << "Testando tamanho() [cheia]: ";
	if (fila.size() != MAX) {
		cerr << "FALHOU (tam = " << fila.size() << ")" << endl;
		exit(1);
	}
	cerr << "OK" << endl;

	cerr << "Testando desenfileira() [normal]: ";
	for (int i = 0; i < MAX; i++) {

		if (fila.front() != i) {
			cerr << "FALHOU em " << i << endl;
			exit(1);
		}else{
            fila.pop();
		}
	}
	cerr << "OK" << endl;

	cerr << "Testando tamanho() [vazia]: ";
	if (fila.empty()) {
		cerr << "OK" << endl;
	}else{
        cerr << "FALHOU (tam = " << fila.size() << ")" << endl;
	}
	return 0;
}






