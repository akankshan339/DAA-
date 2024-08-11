// works only in directed graphs if undirected 1st convert it into directed
// Relaxing Edges N-1 times, gives us Single Source Shortest Path (N-1) bcz edges can be in any order
// in worst case , a graph of n nodes it will take n-1 edges to reach from 1st to lastthen iterate n-1
// Also works on -ve edge weights and also detect -ve cycles (sum of all edge weight of graph is -ve)
// In Dijkstra if -ve cycle comes, it keep on rotating in cycle & gives TLE

#include <bits/stdc++.h>
using namespace std;

vector<int> BellmanFord(int V, int src, vector<vector<int>> &adjList)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++)                 // Relax edges V-1 times
    {
        for (auto adj : adjList)
        {
            int u = adj[0];
            int v = adj[1];
            int d = adj[2];

            if(dist[u] != INT_MAX && dist[u] + d < dist[v])
                dist[v] = dist[u] +d;
        }
    }
        //Nth relaxtation to detect -ve cycle 
        for (auto adj : adjList)
        {
            int u = adj[0];
            int v = adj[1];
            int d = adj[2];

            if(dist[u] != INT_MAX && dist[u] + d < dist[v])
                return {-1};
        }
    return dist;
}
void addEdges(int u, int v, int dist, vector<vector<int>> &adjList)
{
    adjList.push_back({u, v, dist}); // only work for directed graphs
    // adjList[v].push_back({dist,u});
}

int main()
{
    int V, src;
    cout << "Enter no of vertices: \n";
    cin >> V;
    vector<vector<int>> adjList;
    vector<int> res;

    addEdges(0, 2, 6, adjList);         //Akashay graph shortest path using bellman ford
    addEdges(0, 1, 2, adjList);         //same shortest path will come using bellman ford also since there is no -ve edge weights in akashay graph
    addEdges(2, 3, 8, adjList);
    addEdges(1, 3, 5, adjList);
    addEdges(3, 4, 10, adjList);
    addEdges(3, 5, 15, adjList);
    addEdges(4, 6, 2, adjList);
    addEdges(5, 6, 6, adjList);

    // addEdges(3, 2, 6, adjList);     //edges can be in any order
    // addEdges(5, 3, 1, adjList);
    // addEdges(0, 1, 5, adjList);
    // addEdges(1, 5, -3, adjList);
    // addEdges(1, 2, -2, adjList);
    // addEdges(3, 4, -2, adjList);
    // addEdges(2, 4, 3, adjList);

    // addEdges(0, 1, 1, adjList);         //eg of -ve cycle in graph 
    // addEdges(1, 2, 1, adjList);
    // addEdges(2, 3, 1, adjList);
    // addEdges(3, 4, 1, adjList);
    // addEdges(4, 1, -5,adjList);
    
    cout << "Enter source node: \n";
    cin >> src;
    res = BellmanFord(V, src, adjList);

    if (res[0] == -1) 
        cout << "Graph contains a negative weight cycle\n";
    else
    {
        //cout << "Distances from source node " << src << " to other nodes using Bellman-Ford Algorithm:\n";
        cout << "Distance from Akashy's house to his friends house using Bellman Ford Algorithm:\n";
        for (int i = 0; i < res.size(); i++)
        {
            if (res[i] == INT_MAX) 
                cout << "Distance from " << src << " to " << i << " is infinity\n";
            else 
                cout << "Distance from " << src << " to " << i << " is " << res[i] << endl;
        }   
    }
    return 0;
}