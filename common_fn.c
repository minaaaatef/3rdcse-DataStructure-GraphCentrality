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