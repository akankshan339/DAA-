//Detect cycle in directed graph using DFS
//In directed graph (on same path node has to be visted again) visited algorithm fails bcz cycle considered only,
//if direction is clockwise or anticlockwise
#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adjList[], vector<int> &vis, vector<int> &pathVis)
{
    vis[node] = 1;
    pathVis[node] =1;
    
    for(auto &adj :adjList[node])        //traverse adjacent nodes
    {
        if(!vis[adj])               //if node is not visited
        {
            if(dfs(adj, adjList, vis, pathVis) == true)
                return true;
        }

        else if(pathVis[adj])       //if node has alredy visited but has to visit on same path i.e path vis is 1
            return true;        //cycle detected
    }
pathVis[node] = 0;
return false;
}

bool detectCycle(int V, vector<int> adjList[], vector<int> &vis, vector<int> &pathVis)
{
for(int i =1; i<=V; i++)             //adding edges based on 1-based indexing
{
    if(!vis[i])             //if vis[i] == 1                        
        if( dfs(i, adjList, vis, pathVis) == true)
            return true;
}

return false;
}

void addEdges(int u, int v, vector<int> adjList[])
{
    adjList[u].push_back(v);    //for directed graph
}

int main()
{
    int V, src;
    cout << "Enter no of vertices: \n";
    cin >> V;
    vector<int> adjList[V+1];  // V + 1 to handle 1-based indexing
    vector<int> vis(V+1, 0);
    vector<int> pathVis(V+1, 0);
    // addEdges(0, 1, adjList);
    // addEdges(1, 2, adjList);
    // addEdges(2, 3, adjList);
    // addEdges(3, 0, adjList);

    addEdges(1, 2, adjList);    //here cycle is not in 1 direction either clock wise or anticlockwise
    addEdges(2, 3, adjList);
    addEdges(3, 4, adjList);
    addEdges(4, 5, adjList);
    addEdges(5, 6, adjList);
    addEdges(3, 7, adjList);
    addEdges(7, 5, adjList);

    addEdges(8, 9, adjList);    //here is cycle formed
    addEdges(9, 10, adjList);
    addEdges(10, 8, adjList);
    addEdges(8, 2, adjList);

    bool ans = detectCycle(V, adjList, vis, pathVis);
    if(ans)
        cout<<"Yes Cycle Exist in graph :\n";
    else
        cout<<"No Cycle Exist in graph :\n";
return 0;
}