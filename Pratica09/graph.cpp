/*
 * graph.cpp

 *
 *  Created on: 10 de nov de 2017
 *      Author: ramide
 */
#include "graph.h"
#include <iostream>

using namespace std;

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
		delete[] matrix[i];

	delete[] matrix;
	delete[] used;
	delete[] group;
}

void Graph::edge(int v1, int v2) {
	// TODO

	if (matrix[v1][v2] == 0) {
		matrix[v1][v2] = 1;
		used[v1] = 1;
	}

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
	if (group[v1] == group[v2])
		return;

	for (int k = 0; k < numVertices; k++) {
		if (group[k] == group[v2])
			group[k] = group[v1];
	}
}

// Ver descrição na prática
int Graph::connected() {
	// TODO

	// Inicializar grupos

	for (int k = 0; k < numVertices; k++) {
		group[k] = k;
	}

	// Para todos as arestas, faça a união dos dois vértices
// (isto é, agora eles são parte do mesmo grupo)

	int k = 0, v = 0;

	for (k = 0; k < numVertices; k++) {

		for (v = 0; v < numVertices; v++) {

			if (matrix[v][k] != 0 || matrix[k][v] != 0) {
				_union(k, v);

			}
		}
		v = 0;
	}

// Para todos os nós (usados), verifique se estão no mesmo grupo
// (isto é, grafo o grafo é conexo)

	int i = 0, x=0;

	for(;used[i] != 1;i++){}

	int ok = used[i];
	int teste = -1;

	for(;x < numVertices; x++){
		if(used[x] == 1){
			teste = _find(i,x);
			if(teste != ok){
				return 0;
			}
		}
	}


	return 1;
}

int Graph::degree(int v) {
// TODO

	int grau = 0;
	for (int k = 0; k < numVertices; k++) {
		if (matrix[v][k] != 0 || matrix[k][v] != 0) {
			grau++;
		}
	}
	return grau;
}

