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

	int * used; 	// n�s de fato usados; n�s que n�o tem arestas s�o ignorados
	int **matrix; 	// matrix de adjacencia;
					// contabiliza n�mero de arestas entre v1 e v2
					// isto �, se matrix[v1][v2] == 2 existem duas arestas entre v1 e v2

	int * group;  	// grupo a que pertence um n�; inicialmente ele pr�prio
					// significado: se dois n�s est�o no mesmo grupo, existe um caminho conectando eles

	void _union(int v1, int v2);	// Faz dois v�rtices pertencerem ao mesmo grupo
	int  _find(int v1, int v2);		// Diz se dois v�rtices pertencem ou n�o ao mesmo grupo
									// (isto �, se existe caminho ou n�o)

public:
	Graph(int numVerices);

	~Graph();

	int connected();			// Diz se o grafo � conexo ou n�o

	int degree(int v);			// Retorna o grau de um v�rtice.
								// Considere o n�mero de arestas na matriz

	void edge(int v1, int v2);	// Adiciona uma aresta de v1 a v2.
								// Deve atualizar matriz nas linha correspondentes.
								// Tamb�m atualiza array used.
};


#endif /* GRAPH_H_ */
