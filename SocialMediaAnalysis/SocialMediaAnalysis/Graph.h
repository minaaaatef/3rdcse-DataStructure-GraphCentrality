#pragma once
#include <vector>
using namespace std;

class Graph
{
private:
	vector<vector<pair<int, int> > > adj_list;
	int num_nodes , num_edges;
	vector<int> Graph :: shortest_distance(int src,vector<vector<pair<int,int> > > adj_list);

public:
	Graph(int num_nodes,int num_edges);
	~Graph(void);
	int Get_numNodes(void);
	vector<vector<pair<int, int> > > Get_AdjList (void);
	vector<int> Degree_Centrality(void);
	vector<float> Closeness_Centrality(void);
	friend Graph * readFile (const char* path , int &n ,int &m);
};

