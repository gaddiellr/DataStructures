#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "graph.h"
using namespace std;

//loadGraph
// Carga los arcos del grafo y los almacena en una matriz de adyacencia y en una lista de adyacencia
void loadGraph(UMatrixGraph<char> m,UListGraph<char> l){
	cout <<"Matriz de adyacencia:\n\n"<< m.toString();
	cout <<"Lista de adyacencia:\n\n"<< l.toString();
}

int main() {
	UMatrixGraph<char> umg(5);
	umg.addEdge('A', 'B');
	umg.addEdge('B', 'C');
	umg.addEdge('B', 'D');
	umg.addEdge('C', 'E');
	umg.addEdge('D', 'C');
	umg.addEdge('E', 'D');
	UListGraph<char> ulg(5);
	ulg.addEdge('A', 'B');
	ulg.addEdge('B', 'C');
	ulg.addEdge('B', 'D');
	ulg.addEdge('C', 'E');
	ulg.addEdge('D', 'C');
	ulg.addEdge('E', 'D');
	loadGraph(umg,ulg);

	set<char> edges = umg.getConnectionFrom('B');
	set<char>::iterator itr;
	cout << "DFS(B) ->\t";
	edges = dfs('B', &umg);
	for (itr = edges.begin(); itr != edges.end(); itr++) {
		cout << (*itr) << "\t";
	}
	cout << "\n\n";
	cout << "BFS(B) ->\t";
	edges = bfs('B', &umg);
	for (itr = edges.begin(); itr != edges.end(); itr++) {
		cout << (*itr) << "\t";
	}
	cout << "\n";

	return 0;
}
