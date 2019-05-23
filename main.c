#include "common_fn.h"
#include "Degree_Centrality.h"
#include "Closeness_centrality.h"

int main () {
	
	// n ---> number of nodes  , m ---> number of edges
	int n , m;

	vector<vector<pair<int, int> > > adj_list(1, vector<pair<int, int> > ());
	
	readFile("H:\\Nader 2014\\CSE_1stYear\\2nd Term \\Data Structure\\Project\\inputFile.txt",adj_list,n,m);

	//Displays the nodes connected to each node
	for (int i=0; i< n; i++){
		cout<<"The nodes directly connected to node "<<i<<" are: ";
		for(int j=0; j<adj_list[i].size(); j++){
			cout<<"(node: "<<adj_list[i][j].first<<" , weight: "<<adj_list[i][j].second<<") "<<endl;
		}
		cout<<"\n";
	}
	
	return 0;
} 

