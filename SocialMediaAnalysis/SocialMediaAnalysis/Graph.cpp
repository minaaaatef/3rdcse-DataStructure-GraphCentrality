#include "Graph.h"
#include <queue>
#include <stack>
#include <functional>
#include<numeric>

#define INF 1e9

Graph::Graph(int num_nodes,int num_edges)
{
	this->num_nodes = num_nodes;
	adj_list.resize(num_nodes);

	this->num_edges = num_edges;
}


Graph::~Graph(void)
{
}

vector<vector<pair<int, int>>> Graph ::  Get_AdjList (void){
	return adj_list;
}

int Graph :: Get_numNodes(void){
	return num_nodes;
}

vector<int> Graph :: Degree_Centrality(void){
	vector <int> Degrees (this->num_nodes);

	for(int i=0 ; i<Degrees.size() ; i++){
		Degrees[i] = this->adj_list[i].size();
	}

	return Degrees;
}

vector<int> Graph :: shortest_distance(int src,vector<vector<pair<int,int> > > adj_list){
	
	// Create queue
	priority_queue<pair<int, pair<int, int> >,
				   vector<pair<int, pair<int, int>> >,
				   greater<pair<int, pair<int, int> > > >nodes_q;
	
	// Create d and p arrays
	int n = adj_list.size();
	vector<int> d(n, INF);
	vector<int> p(n, -1);
	
	nodes_q.push(make_pair(0, make_pair(src, src)));
	
	while(!nodes_q.empty()){
		pair<int,pair<int, int> > cur_p = nodes_q.top();
		nodes_q.pop();
		int cur_node = cur_p.second.first;
		int cur_prev_node = cur_p.second.second;
		int cur_dis = cur_p.first;
		
		if (d[cur_node] != INF)
			continue;

		d[cur_node] = cur_dis;
		p[cur_node] = cur_prev_node;
		
		// Add the nodes connected to current one
		for (int i=0; i< adj_list[cur_node].size();i++)
		{
			int next_node = adj_list[cur_node][i].first;
			int weight = adj_list[cur_node][i].second;
			if (d[next_node] !=INF)
				continue;
			nodes_q.push(make_pair(cur_dis + weight,
						  make_pair(next_node, cur_node)));
		}
	}
	
	return d;
}

vector<float> Graph :: Closeness_Centrality(void){

	vector <float> CC (this->num_nodes);
	vector<int> d (this->num_nodes);
	
	for(int i=0 ; i<this->adj_list.size();i++){
		d = shortest_distance(i,this->adj_list);
		CC[i] = float(this->num_nodes - 1)/accumulate(d.begin(),d.end(),0);

	}
	
	return CC;
}