#include <iostream>
#include <list>
#include <stdlib.h>
#include <time.h> 
#include <ostream>
#include <vector>
#include <queue>
#include<chrono>
using namespace std;

// This funciton will print out the shortest path
void shortestPath(int const &, int const &, int*);

// Class to create graphs and perfrom BFS
class Graph{
	int V;
	vector<list<int>> adjacency;
public:
	Graph(int V);
	void createAdjacency(int v, int w);
	void BFS(int s, int t);
};

// This function will create the 4 graph objects
void createGraphs(Graph&, Graph&, Graph&, Graph&);

int  main() {

	srand(time(NULL));

	// Graph objects
	Graph g_twenty(20);
	Graph g_forty(40);
	Graph g_eighty(80);
	Graph g_onesixty(160);

	// start and end points for each graph
	int start_twenty = rand() % 19 + 1;
	int end_twenty = rand() % 19 + 1;
	int start_forty = rand() % 39 + 1;
	int end_forty = rand() % 39 + 1;
	int start_eighty = rand() % 79 + 1;
	int end_eighty = rand() % 79 + 1;
	int start_onesixty = rand() % 159 + 1;
	int end_onesixty = rand() % 159 + 1;

	createGraphs(g_twenty, g_forty, g_eighty, g_onesixty);

	// Run BFS and output results and time for all 4 graphs
	cout << "-------------------------------------------------------" << endl;
	
	cout << "20 Verticies & 50 Edges" << endl;
	cout << "Starting Point: " << start_twenty << endl << "Ending Point: " << end_twenty << endl;
	auto twenty_start = chrono::high_resolution_clock::now();
	g_twenty.BFS(start_twenty, end_twenty);
	auto twenty_end = chrono::high_resolution_clock::now();
	auto twenty_time = twenty_end - twenty_start;
	cout << "Time Elapsed: " << chrono::duration_cast<chrono::nanoseconds>(twenty_time).count() << " nanoseconds" << endl;
	
	cout << "-------------------------------------------------------" << endl;
	
	cout << "40 Verticies & 200 Edges" << endl;
	cout << "Starting Point: " << start_forty << endl << "Ending Point: " << end_forty << endl;
	auto forty_start = chrono::high_resolution_clock::now();
	g_forty.BFS(start_forty, end_forty);
	auto forty_end = chrono::high_resolution_clock::now();
	auto forty_time = forty_end - forty_start;
	cout << "Time Elapsed: " << chrono::duration_cast<chrono::nanoseconds>(forty_time).count() << " nanoseconds" << endl;
	
	cout << "-------------------------------------------------------" << endl;
	
	cout << "80 Verticies & 800 Edges" << endl;
	cout << "Starting Point: " << start_eighty << endl << "Ending Point: " << end_eighty << endl;
	auto eighty_start = chrono::high_resolution_clock::now();
	g_eighty.BFS(start_eighty, end_eighty);
	auto eighty_end = chrono::high_resolution_clock::now();
	auto eighty_time = eighty_end - eighty_start;
	cout << "Time Elapsed: " << chrono::duration_cast<chrono::nanoseconds>(eighty_time).count() << " nanoseconds" << endl;
	
	cout << "-------------------------------------------------------" << endl;
	
	cout << "160 Verticies & 3200 Edges" << endl;
	cout << "Starting Point: " << start_onesixty << endl << "Ending Point: " << end_onesixty << endl;
	auto onesixty_start = chrono::high_resolution_clock::now();
	g_onesixty.BFS(start_onesixty, end_onesixty);
	auto onesixty_end = chrono::high_resolution_clock::now();
	auto onesixty_time = onesixty_end - onesixty_start;
	cout << "Time Elapsed: " << chrono::duration_cast<chrono::nanoseconds>(onesixty_time).count() << " nanoseconds" << endl;
	
	cout << "-------------------------------------------------------" << endl;

	return 0;
}

void createGraphs(Graph &g_twenty, Graph &g_forty, Graph &g_eighty, Graph &g_onesixty){
	// Generate random graphs based on verticies and edges amount
	//		Generate 50 random edges based on number of vertcies(randomly)
	//		createAdjacency will create an edge between two random verticies
	for (int i = 0; i < 50; i++) {
		int vertex1 = rand() % 19 + 1;
		int vertex2 = rand() % 19 + 1;
		g_twenty.createAdjacency(vertex1, vertex2);
	}
	for (int i = 0; i < 200; i++) {
		int vertex1 = rand() % 39 + 1;
		int vertex2 = rand() % 39 + 1;
		g_forty.createAdjacency(vertex1, vertex2);
	}
	for (int i = 0; i < 800; i++) {
		int vertex1 = rand() % 79 + 1;
		int vertex2 = rand() % 79 + 1;
		g_eighty.createAdjacency(vertex1, vertex2);
	}
	for (int i = 0; i < 3200; i++) {
		int vertex1 = rand() % 159 + 1;
		int vertex2 = rand() % 159 + 1;
		g_onesixty.createAdjacency(vertex1, vertex2);
	}
}

// Sets the graph size based on the number of verticies passed in
Graph::Graph(int V){
	this->V = V;
	adjacency.resize(V);
}

// Create Adjecency List using adjacent verticies
void Graph::createAdjacency(int v, int v2){
	adjacency[v].push_back(v2);
}

void Graph::BFS(int s, int t){
	// Create new list to set up BFS
	int* hop = new int[V];
	int* parent = new int[V];

	// Create enqueue
	queue<int> enqueue;
	// Create adjacentV iterator
	list<int>::iterator adjacentV;

	// Set all hop distances to infinite amount
	// Set all parent nodes to nil amount
	for (int i = 0; i < V; i++) {
		hop[i] = 999999999;
		parent[i] = -1;
	}

	// Create working verticie
	hop[s] = 0;
	enqueue.push(s);

	// loop until queue is empty
	while (!enqueue.empty()) {
			s = enqueue.front();
			enqueue.pop();
			// loop for adjacent nodes
			for (adjacentV = adjacency[s].begin(); adjacentV != adjacency[s].end(); adjacentV++) {
				if (hop[*adjacentV] == 999999999) {
					enqueue.push(*adjacentV);
					hop[*adjacentV] = hop[s] + 1; // set hop distance
					parent[*adjacentV] = s; // set parent node
				}
			}
	}
	if (hop[t] != 999999999) {
		shortestPath(s, t, parent);
	}
	else {
		cout << "There is no Path";
	}
	cout << endl;
}

void shortestPath(int const &s, int const &t, int* parent) {
	if (s == t || t == -1) {
		cout << "Shortest Path is: ";
	}
	else {
		shortestPath(s, parent[t], parent);
		cout << t << " ";
	}
}