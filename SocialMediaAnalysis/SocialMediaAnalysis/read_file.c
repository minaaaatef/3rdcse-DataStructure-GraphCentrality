#include <iostream>
#include "read_file.h"


using namespace std;

Graph * readFile (const char* path , int &n ,int &m){
	
	// Redirect cin to read from a file 	
	freopen(path, "r", stdin);

	// n ---> number of nodes  , m ---> number of edges
	cin>>n>>m;

	//Creating a graph
	Graph *G1 = new Graph(n,m);

	G1->adj_list.resize(n);

	int a, b, c;

	// Building the adjacency List
	for (int i=0; i<m ;i++){
		cin>>a>>b>>c;
		G1->adj_list[a].push_back(make_pair(b,c));
		G1->adj_list[b].push_back(make_pair(a,c));
	}
	return G1;
}
