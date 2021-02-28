//teste de pilha com #include <stack>
#include <iostream>
#include <stack>

using namespace std;

#define MAX 100

int mainP(){

    std::stack<int> pilha;

    try {
		cerr << "Testando push() [normal]: ";
		for (int i = 0; i < MAX; i++) {
			pilha.push(i);
		}
		cerr << "OK" << endl;
	} catch (const char *) {
		cerr << "FALHOU!" << endl;
		exit(1);
	}

	cerr << "Testando size() [cheia]: ";
	if (pilha.size() != MAX) {
		cerr << "FALHOU (tam = " << pilha.size() << ")" << endl;
		exit(1);
	}
	cerr << "OK" << endl;

    cerr << "Testando pop() [normal]: ";
	for (int i = (MAX - 1); i >= 0; i--) {
		pilha.pop();

        if(pilha.empty()){
            cerr << "OK" << endl;
        }
	}

    cerr << "Testando empty() [vazia]: ";
        if(pilha.empty()){
            cerr << "OK" << endl;
        }
}
