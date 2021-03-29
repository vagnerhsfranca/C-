

#include "graph.h"
#include "queue.h"
#include "heap.h"

// Cria array do tipo T com tamanho "size" e inicializa com valor "def"
template <class T>
T * array(int size, T def) {
	T * arr = new T[size];
	for (int i = 0; i < size; i++) arr[i] = def;
	return arr;
}

Graph::Graph(int nVert) {
	this->nVert = nVert;
	this->adj = new List<Edge>[nVert];
}

Graph::~Graph() {
	delete [] adj;
}

// Criação da aresta src --> dst
void Graph::edge(int src, int dst, int w) {
	adj[src].add(Edge(dst, w));
}

// Busca em profundidade
List<int> * Graph::dfs(int src) {
	List<int> * result = new List<int>();
	int * visited = array(nVert, 0);

	DFS(src, visited, result);

	delete [] visited;
	return result;
}

// Busca em profundidade
void Graph::DFS(int src, int * visited, List<int> * result) {
	visited[src] = src;
	cout << src <<endl;

	for(int i=src; i < nVert; i++)
        if(visited[src+1] == NULL)
            DFS(src+1, visited, ++result);
}

// Busca em largura
List<int> * Graph::bfs(int src) {
	Queue<int> queue;
	List<int> * result = new List<int>();
	int * visited = array(nVert, 0);

	BFS(src, visited, result);

	delete [] visited;
	return result;
}

// Busca em largura
void Graph::BFS(int src, int * visited, List<int> * result) {
    for(int i = 0; i < nVert; i++){
        visited[i] = NULL;
    }
    Queue <int> *fila();
    visited[src] = src;

    while(fila.empty() != 1){
        x= fila.dequeue();
        for(int i = src; i < nVert; i++){
            if(visited[src+1] = NULL){
                fila.enqueue(++src);
            }
        }
    }
}

List<int> * Graph::spf(int src, int dst) {
	int * dist = array(nVert, 99999);
	int * prev = array(nVert, -1);
	dist[src] = 0;

	// Cria o heap (mínimo) baseado na distância
	Heap<int> pq(nVert, dist);

	while(!(pq.empty())) {
		int node = pq.dequeue();	// pega nó com menor distância acumulada

		int len = adj[node].length();	// pega número de aresta c/ vizinhos
		for (int i = 0; i < len; i++) {
			Edge edge = adj[node].get(i);	// pega aresta
			int v = edge.dst;				// nó vizinho
			int w = edge.weight;			// peso da aresta

			int D = dist[node] + w;			// nova distância

			if (D < dist[v]) {				// menor que antiga?
				prev[v] = node;				// atualize anterior
				dist[v] = D;				// atualize distância
				pq.decrease(v);				// atualize o heap (PQ)
			}
		}
	}

	List<int> * result = new List<int>();	// menor caminho

	path(dst, prev, result);				// extrair caminho em result

	delete [] dist;
	delete [] prev;

	return result;
}

void Graph::path(int dst, int * prev, List<int> * result) {
	// TO DO
}


void Graph::print() {
	for (int i = 0; i < nVert; i++) {
		cout << i << ": ";
		adj[i].print();
	}
}

ostream & operator<<(ostream & out, const Graph::Edge & edge) {
	return out << "(" << edge.dst << ", " << edge.weight << ")";
}





