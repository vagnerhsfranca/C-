/*
 * domino.cpp
 *
 *  Created on: 10 de nov de 2017
 *      Author: ramide
 */

#include <iostream>

#include "graph.h"

using namespace std;

int main() {
	Graph graph(7);

	graph.edge(1,2);
	graph.edge(2,4);
	graph.edge(2,1);
	graph.edge(6,4);
	graph.edge(4,2);
	graph.edge(0,5);

	if (!(graph.connected())) {
		cout << "N�O (N�o conexo)" << endl;
		return 1;
	}

	// Verifica quantos v�rtices tem grau �mpar (odd)
	int oddDegree = 0;
	for (int i = 0; i < 7; i++) {
		if (graph.degree(i) % 2)
			oddDegree++;
	}

	if (oddDegree > 2) {
		cout << "N�O (Mais de 2 v�rtices com grau �mpar)" << endl;
		return 1;
	}

	cout << "SIM" << endl;
}

/*
5
1 2
2 4
2 1
6 4
4 2
*/

