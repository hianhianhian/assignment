#include "pch.h"
#include <iostream>
using namespace std;

#define V 5

/*
class Graph {
private:
	int** adjMatrix;
	int numVertices;
public:
	Graph(int numVertices) {
		this->numVertices = numVertices;
		adjMatrix = new int*[numVertices];
		for (int i = 0; i < numVertices; i++) {
			adjMatrix[i] = new int[numVertices];
			for (int j = 0; j < numVertices; j++)
				adjMatrix[i][j] = 0;
		}
	}

	void addEdge(int i, int j, int weight) {
		adjMatrix[i][j] = weight;
		adjMatrix[j][i] = weight;
	}

	void removeEdge(int i, int j) {
		adjMatrix[i][j] = 0;
		adjMatrix[j][i] = 0;
	}

	bool isEdge(int i, int j) {
		return adjMatrix[i][j];
	}
	void toString() {
		for (int i = 0; i < numVertices; i++) {
			cout << i << " : ";
			for (int j = 0; j < numVertices; j++)
				cout << adjMatrix[i][j] << " ";
			cout << "\n";
		}
	}

	~Graph() {
		for (int i = 0; i < numVertices; i++)
			delete[] adjMatrix[i];
		delete[] adjMatrix;
	}
};
*/

void printSolution(int dist[], int src, int dest) {
	printf("Source: %d - Destination: %d\n", src, dest);
	printf("Distance from Source: %d\n", abs(dist[dest]));
}

void printPath(int traversed[]) {
	printf("Path: ");
	for (int i = 0; i < V; i++) {
		if (traversed[i] >= 0) {
			if (i > 0) cout << " -> ";
			cout << traversed[i];
		}
	}
	cout << "\n----------------------------------------------------------\n\n";
}

// Utility function that returns the index of the vertex with minimum distance value
// if it is not visited yet
int minDistance(int dist[], bool visited[]) {
	int min = INT_MAX, min_index;

	for (int i = 0; i < V; i++) {
		if (dist[i] <= min && visited[i] == false) {
			min = dist[i];
			min_index = i;
		}
	}
	return min_index;
}

void shortest_path_dijkstra(int g[V][V], int src, int dest) {
	int dist[V];
	int traversed[V];
	bool visited[V];

	for (int i = 0; i < V; i++) {
		dist[i] = INT_MAX;
		visited[i] = false;
		traversed[i] = -1;
	}

	dist[src] = 0;

	int count;
	for (int i = 0; i < V - 1; i++) {
		int u = minDistance(dist, visited);
		count = i;
		if (u == dest) {
			break;
		}

		visited[u] = true;

		for (int v = 0; v < V; v++) {
			if (!visited[v] && g[u][v] && dist[u] != INT_MAX && dist[u] + g[u][v] < dist[v]) {
				dist[v] = dist[u] + g[u][v];
				traversed[i] = u;
			}
		}
	}

	traversed[count] = dest;
	printSolution(dist, src, dest);
	printPath(traversed);
}

void longest_path(int g[V][V], int src, int dest) {
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			g[i][j] *= -1;
		}
	}

	shortest_path_dijkstra(g, src, dest);
}


int main() {
	/*
	Graph g(5);

	g.addEdge(0, 1, 6);
	g.addEdge(0, 3, 7);
	g.addEdge(0, 4, 3);
	g.addEdge(1, 2, 8);
	g.addEdge(2, 3, 6);
	g.addEdge(3, 4, -2);

	// g.toString();
	 Output
		0 : 0 6 0 7 3
		1 : 6 0 8 0 0
		2 : 0 8 0 6 0
		3 : 7 0 6 0 -2
		4 : 3 0 0 -2 0
	 

	*/

	int g[V][V] = {
	{ 0, 6, 0, 7, 3 },
	{ 6, 0, 8, 0, 0 },
	{ 0, 8, 0, 6, 0 },
	{ 7, 0, 6, 0, -2 },
	{ 3, 0, 0, -2, 0 }
	};

	cout << "Q1. Shortest paths ======================================\n";

	shortest_path_dijkstra(g, 0, 2);	// a->e->d->c	or 0->4->3->2
	shortest_path_dijkstra(g, 1, 4);	// b->a->e		or 1->0->4
	shortest_path_dijkstra(g, 1, 3);	// b->a->e->d	or 1->0->4->3
	shortest_path_dijkstra(g, 2, 4);	// c->d->e		or 2->3->4

	cout << "Q2. Longest paths ========================================\n";

	longest_path(g, 0, 2);	// a->b->c			or 0->1->2
	longest_path(g, 1, 4);	// b->c->d->a->e	or 1->2->3->0->4 
	longest_path(g, 1, 3);	// b->c->d			or 1->2->3
	longest_path(g, 2, 4);	// c->b->a->e		or 2->1->0->4
}