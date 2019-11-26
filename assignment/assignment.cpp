// assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

#define V 5

// stores adjacency list items
struct adjNode {
	int index, cost;
	adjNode* next;
};
// structure to store edges
struct graphEdge {
	int src, dest, weight;
};
class Graph {
	// insert new nodes into adjacency list from given graph
	adjNode* getAdjListNode(int index, int weight, adjNode* head) {
		adjNode* newNode = new adjNode;
		newNode->index = index;
		newNode->cost = weight;

		newNode->next = head;   // point new node to current head
		return newNode;
	}
	int numVertices;  // number of nodes in the graph
public:
	adjNode **head;                //adjacency list as array of pointers
	// Constructor
	Graph(graphEdge edges[], int n, int numVertices) {
		// allocate new node
		head = new adjNode*[numVertices]();
		this->numVertices = numVertices;

		// initialize head pointer for all vertices
		for (int i = 0; i < numVertices; ++i)
			head[i] = nullptr;

		// construct directed graph by adding edges to it
		for (unsigned i = 0; i < n; i++) {
			int src = edges[i].src;
			int dest = edges[i].dest;
			int weight = edges[i].weight;
			// insert in the beginning
			adjNode* newNode = getAdjListNode(dest, weight, head[src]);

			// point head pointer to new node
			head[src] = newNode;
		}
	}
	// Destructor
	~Graph() {
		for (int i = 0; i < numVertices; i++)
			delete[] head[i];
		delete[] head;
	}
};
// print all adjacent vertices of given vertex
void display_AdjList(adjNode* ptr, int i)
{
	while (ptr != nullptr) {
		cout << "(" << i << ", " << ptr->index << ", " << ptr->cost << ") ";
		ptr = ptr->next;
	}
	cout << endl;
}

void shortest_path_dijkstra(Graph graph, int src, int dest) {
	int distance[V];


}

// graph implementation
int old_main()
{
	// graph edges array.
	graphEdge edges[] = {
		// (x, y, w) -> edge from x to y with weight w
		// a = 0, b = 1, ... , e = 4
		{0,1,6},{0,4,3},{0,3,7},{1,0,6},{1,2,8},{2,1,8},{2,3,6},{3,0,7},{3,2,6},{3,4,-2},{4,0,3},{4,3,-2}
	};
	int numVertices = 5;      // Number of vertices in the graph
	// calculate number of edges
	int n = sizeof(edges) / sizeof(edges[0]);
	// construct graph
	Graph graph(edges, n, numVertices);




	/*
	// print adjacency list representation of graph
	cout << "Graph adjacency list " << endl << "(src, dest, weight):" << endl;
	for (int i = 0; i < numVertices; i++)
	{
		// display adjacent vertices of vertex i
		display_AdjList(graph.head[i], i);
	}
	*/
	return 0;
}