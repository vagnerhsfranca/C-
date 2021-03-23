#include <iostream>
#include "list.h"

class Graph {
private:
	// Aresta
	struct Edge {
		int dst;		// Destino da aresta (nó vizinho)
		int weight;		// Peso da aresta
		Edge(int dst, int weight) : dst(dst), weight(weight) {}
	};

	int nVert;			// Número de vértices
	List<Edge> * adj;	// Lista de adjacência

public:
	Graph(int nVert);
	~Graph();

	// Cria src -> dst com peso w
	void edge(int src, int dst, int w);

	List<int> * dfs(int src); // Busca em profundidade
	List<int> * bfs(int src); // Busca em largura
	List<int> * spf(int src, int dst); // Menor caminho entre src e dst

	void print(); // Exibe o grafo
	friend ostream & operator<<(ostream & out, const Graph::Edge & aluno);

private:
	void DFS(int src, int * visited, List<int> * result); // DFS de fato
	void BFS(int src, int * visited, List<int> * result); // BFS de fato

	void path(int src, int * visited, List<int> * result); // extrai menor caminho de prev
};




