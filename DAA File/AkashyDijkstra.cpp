// find out shortest distance and path covering distance from each of his friend’s location to his house
//find out the shortest dist from all other nodes to single src i.e akshay house
//Dijkstra's algorithm is designed to find the shortest path from a single source node to all other nodes in a weighted graph with non-negative edge weights. This means it calculates the shortest distance from the source node to every other node in the graph.

/*Dijkstra algorithm, does not directly find shortest distance from all nodes to source node It calculates distances from source node to other nodes not reverse 
To find shortest distances from all nodes to source node there are 2 options

This only in case of directed graph , (i) Reverse the edges: If you reverse the direction of all edges in the graph, then running Dijkstra's algorithm from the original destination node will give you the shortest paths from all nodes to this original dest. node.
(ii)Run the algorithm multiple times: To find shortest paths from every node to every other node, you can run Dijkstra's algorithm once from each node. 

If the graph is undirected, you do not need to reverse the edges to find the shortest paths from all other nodes to a single target node bcz,
In undirected graph dist from node A to node 𝐵 is the same as dist from node B to A */
#include<bits/stdc++.h>
using namespace std;

vector<int> Dijkstra(int V, int src, vector<vector<pair<int,int>>>&adjList)
{
    priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>>pq;    //min heap store dist , dest. node
    vector<int>dist(V, INT_MAX);
    dist[src] =0;
    pq.push({0, src});
    while(!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto &it :adjList[node])
        {
            int edgeDist = it.first;
            int adjnode = it.second;
        
            if(dis + edgeDist < dist[adjnode])
            {
                dist[adjnode]= dis+ edgeDist;
                pq.push({dist[adjnode] , adjnode});
            }

        }

    }
return dist;
}
void addEdges(int u, int v, int dist, vector<vector<pair<int,int>>> &adjList)
{
    adjList[u].push_back({dist,v});    //for directed 
    adjList[v].push_back({dist, u});    //for undirected also we can say revese directed
}
int main()
{
    int V, src;
    cout << "Enter no of vertices: \n";
    cin >> V;
    vector<vector<pair<int,int>>> adjList(V);
    vector<int>res;
    addEdges(0, 2, 6, adjList);
    addEdges(0, 1, 2, adjList);
    addEdges(2, 3, 8, adjList);
    addEdges(1, 3, 5, adjList);
    addEdges(3, 4, 10, adjList);
    addEdges(3, 5, 15, adjList);
    addEdges(4, 6, 2, adjList);
    addEdges(5, 6, 6, adjList);

    cout<<"Enter the Akshay location(source node) :";
    cin>>src;
    res = Dijkstra(V, src, adjList);
    cout<<"Distance from Akashy's friends house to Akashay's house is :\n";
    for(int i =0; i<res.size(); i++)
    {
        cout<<"dist from "<<i<<" to  "<<src<<" is "<<res[i]<<endl;
    }
    
return 0;
}