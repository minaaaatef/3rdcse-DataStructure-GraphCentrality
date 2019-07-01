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
	Graph *G1 = readFile("inputFile.txt",n,m);
	
	vector<int> Degrees (n);
	Degrees = G1->Degree_Centrality();

	vector<float> Closeness (n);
	Closeness = G1->Closeness_Centrality();

	vector<float> Betweenness (n);
	Betweenness = G1->Betweenness_Centrality();

	cout <<"Degree Centrality"<<"\n"<<"Start"<<"\n";
	for (auto i : Degrees)
		cout<<Degrees[i]<<"\n";
	cout<<"Stop";
	cout<<"\n";

	
	cout <<"Closeness Centrality"<<"\n"<<"Start"<<"\n";
	for (int i =0 ; i< Closeness.size(); i++)
		cout<<Closeness[i]<<"\n";
	cout<<"Stop";
	cout<<"\n";

	cout <<"Betweenness Centrality"<<"\n"<<"Start"<<"\n";
	for (int i =0 ; i< Betweenness.size(); i++)
		cout<<Betweenness[i]<<"\n";
	cout<<"Stop";
	cout<<"\n";

	ofstream myfile;

	myfile.open ("Degree.txt");
	for (int i =0 ; i< Degrees.size(); i++)
		myfile << Degrees[i]<<endl;
	
	myfile.close();

	myfile.open ("Closeness.txt");
	for (int i =0 ; i< Closeness.size(); i++)
		myfile << Closeness[i]<<endl;
	
	myfile.close();

	myfile.open ("Betweenness.txt");
	for (int i =0 ; i< Betweenness.size(); i++)
		myfile << Betweenness[i]<<endl;
	
	myfile.close();

	cout<<endl;
	return 0;
} 

