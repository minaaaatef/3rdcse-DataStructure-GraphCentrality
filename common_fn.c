#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

void MakeAdjList(vector <vector<int>> &Adjlist )
{
    //clear The Adjlist Vector
    vector<int>().swap( Adjlist );
    // taking n as the num of nodes and m as the num of lines
    cin>>n>>m;
    //reinitialize the Adjlist vector
    Adjlist.resize(n,0);
    for (int x = 0 ; x < m ; x++)
    {
   
        int a, b;
        cin>>a>>b;
        Adjlist[a].push_back(b);
    } 
}


void readFile (const char* path,vector<vector<pair<int, int> > > &adj_list , int &n ,int &m){

	// Redirect cin to read from a file 	
	freopen(path, "r", stdin);

	// n ---> number of nodes  , m ---> number of edges
	cin>>n>>m;

	adj_list.resize(n);
	int a, b, c;

	// Building the adjacency List
	for (int i=0; i<m ;i++){
		cin>>a>>b>>c;
		adj_list[a].push_back(make_pair(b,c));
		adj_list[b].push_back(make_pair(a,c));
	}
}
