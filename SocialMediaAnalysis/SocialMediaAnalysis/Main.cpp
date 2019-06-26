#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include "Graph.h"
#include <fstream>


#define inf 1e9

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


int main () {
	
	// n ---> number of nodes  , m ---> number of edges
	int n , m;
	
	//Graph G1
	Graph *G1 = readFile("H:\\Nader 2014\\CSE_1stYear\\2nd Term \\Data Structure\\Project\\inputFile.txt",n,m);
	

	//Displays the nodes connected to each node
	for (int i=0; i< n; i++){
		cout<<"The nodes directly connected to node "<<i<<" are: ";
		for(int j=0; j<G1->Get_AdjList()[i].size(); j++){
			cout<<"(node: "<<G1->Get_AdjList()[i][j].first<<" , weight: "<<G1->Get_AdjList()[i][j].second<<") "<<endl;
		}
		cout<<"\n";
	}
	
	
	vector<int> Degrees (n);
	Degrees = G1->Degree_Centrality();
	
	for (auto i : Degrees)
		cout<<Degrees[i]<<endl;
	
	cout<<endl;

	vector<float> Closeness (n);
	Closeness = G1->Closeness_Centrality();

	for (int i =0 ; i< Closeness.size(); i++)
		cout<<Closeness[i]<<endl;
	
	ofstream myfile;
	myfile.open ("Output.txt");
	for (int i =0 ; i< Closeness.size(); i++)
		myfile << Closeness[i]<<endl;
	
	myfile.close();

	cout<<endl;
	return 0;
} 

