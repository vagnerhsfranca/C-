/*
 * graph.h
 *
 *  Created on: 10 de nov de 2017
 *      Author: ramide
 */

#ifndef GRAPH_H_
#define GRAPH_H_


class Graph {
private:
	int numVertices;

	int * used; 	// nós de fato usados; nós que não tem arestas são ignorados
	int **matrix; 	// matrix de adjacencia;
					// contabiliza número de arestas entre v1 e v2
					// isto é, se matrix[v1][v2] == 2 existem duas arestas entre v1 e v2

	int * group;  	// grupo a que pertence um nó; inicialmente ele próprio
					// significado: se dois nós estão no mesmo grupo, existe um caminho conectando eles

	void _union(int v1, int v2);	// Faz dois vértices pertencerem ao mesmo grupo
	int  _find(int v1, int v2);		// Diz se dois vértices pertencem ou não ao mesmo grupo
									// (isto é, se existe caminho ou não)

public:
	Graph(int numVerices);

	~Graph();

	int connected();			// Diz se o grafo é conexo ou não

	int degree(int v);			// Retorna o grau de um vértice.
								// Considere o número de arestas na matriz

	void edge(int v1, int v2);	// Adiciona uma aresta de v1 a v2.
								// Deve atualizar matriz nas linha correspondentes.
								// Também atualiza array used.
};


#endif /* GRAPH_H_ */
