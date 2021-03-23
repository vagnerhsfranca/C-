/*
 * graph.cpp

 *
 *  Created on: 10 de nov de 2017
 *      Author: ramide
 */
 #include<iostream>
 using namespace std;
#include "graph.h"

Graph::Graph(int numVertices) {
	this->numVertices = numVertices;

	used = new int[numVertices];
	group = new int[numVertices];
	matrix = new int*[numVertices];

	for (int i = 0; i < numVertices; i++) {
		used[i] = 0;
		matrix[i] = new int[numVertices];
		for (int n = 0; n < numVertices; n++)
			matrix[i][n] = 0;
	}
}

Graph::~Graph() {
	for (int i = 0; i < numVertices; i++)
		delete [] matrix[i];

	delete [] matrix;
	delete [] used;
	delete [] group;
}


void Graph::edge(int v1, int v2) {
	matrix[v1][v2]++;
}

// Indica se existe caminho entre v1 e v2,
// isto é, se eles fazem parte do mesmo grupo
int Graph::_find(int v1, int v2) {
	return (group[v1] == group[v2]);
}

// Faça a união dos grupos de v1 e v2
// Ao final, group[v1] == group[v2],
// e todos os nós que faziam parte do grupo de v1
// agora fazem o parte do grupo de v2 (e vice-versa)
void Graph::_union(int v1, int v2) {
	if (group[v1] == group[v2]) return;

	for (int k = 0; k < numVertices; k++) {
		if (group[k] == group[v2])
			group[k] = group[v1];
	}
}

// Ver descrição na prática
int Graph::connected() {
    // Inicializar grupos
    for(int i=0 ;i < numVertices; i++){
        group[i] = i;
    }
    //impressao teste de grupo
    cout << "Teste grupo\n" <<"  ";
    for(int i = 0; i < numVertices; i++)
        cout << group[i] <<" ";
    cout << endl;

    //imprimindo teste de grupos antes da uniao
    cout << "Teste antes da uniao _FIND()(DISCONNECT)\n";
    for(int i = 0; i < numVertices; i++){
        cout << i <<":";
        for(int j = 0; j < numVertices; j++)
            cout << _find(i,j) << " ";
        cout << endl;
	}

    //Para todos as arestas, faça a união dos dois vértices
    //(isto é, agora eles são parte do mesmo grupo)
    for(int i = 0; i < numVertices; i+=2){
        for(int j = i+1; j < numVertices; j++){
            _union(i,j);
        }
    }
    //impressao de teste de Uniao
    cout << "Teste de uniao (matrix[x][y] == 1) = Uniao OK\n";
    for(int i = 0; i < numVertices; i++){
        cout << i <<":";
        for(int j=0; j < numVertices; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    // Para todos os nós (usados), verifique se estão no mesmo grupo
	// (isto é, grafo o grafo é conexo)
	cout << "Testando se Node _FIND() usados(!= 0) estao no mesmo grupo\n";
	for(int i = 0; i < numVertices; i++){
             cout << i <<":";
        for(int j = 0; j < numVertices; j++)
            if(matrix[i][j] != 0)
                cout << _find(i,j) << " ";
            else
                    cout << "0 ";
        cout << endl;
	}
    cout << "Testando se Node _FIND() nao usados(!= 0) estao no mesmo grupo\n";
	for(int i = 0; i < numVertices; i++){
             cout << i <<":";
        for(int j = 0; j < numVertices; j++)
            if(matrix[i][j] == 0)
                cout << _find(i,j) << " ";
            else
                cout << "0 ";
        cout << endl;
	}
    cout << "\n" << endl;
	return 1;
}

int Graph::degree(int v) {
	int conectados = 0;

	for(int i = 0; i < numVertices; i++)
        if(matrix[v][i] != 0)
            conectados += matrix[v][i];


    return conectados;
}



