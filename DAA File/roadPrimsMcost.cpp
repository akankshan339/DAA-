#include<bits/stdc++.h>
using namespace std;

int prims(int V, vector<vector<pair<int, int>>>&adjList)
{
int mincost =0;
vector<pair<int , pair<int, int>>>mst;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
vector<int>vis(V);
vector<int>parent(V, -1);
pq.push({0,0});
while(!pq.empty())
{
auto it = pq.top();
int node =it.second;
int wt = it.first;
pq.pop();

if(vis[node] == 1)
    continue;
vis[node] = 1;
mincost +=wt;
if(parent[node] != -1)
    mst.push_back({wt, {parent[node], node}});

for(auto it:adjList[node])
{
    int adjnode = it.first;
    int edwt = it.second;
    if(!vis[adjnode])
    {
        pq.push({edwt, adjnode});
        parent[adjnode] = node; // Set the parent of the adjacent node
    }   
}
}
cout << "Map of cities and roads in form of a graph.: is \n";
        for (auto it : mst) 
            cout << it.second.first << " -- " << it.second.second << " weight = " << it.first << endl;

return mincost;
}
void addEdge(int parent, int node, int wt, vector<vector<pair<int,int>>>&adjList)
{
adjList[parent].push_back({node, wt});
adjList[node].push_back({parent, wt});

}
int main()
{
    int V;
    cout<<"Enter the no of vertices: ";
    cin>>V;
    vector<vector<pair<int,int>>>adjList(V);
    
    // addEdge(0, 1, 2, adjList);
    // addEdge(0, 3, 6, adjList);
    // addEdge(1, 2, 3, adjList);
    // addEdge(1, 3, 8, adjList);
    // addEdge(1, 4, 5, adjList);
    // addEdge(4, 2, 7, adjList);

//     addEdge(0, 2, 7, adjList);
// addEdge(0, 3, 5, adjList);
// addEdge(1, 2, 8, adjList);
// addEdge(1, 3, 5, adjList);
// addEdge(2, 0, 7, adjList);
// addEdge(2, 1, 8, adjList);
// addEdge(2, 3, 9, adjList);
// addEdge(2, 4, 7, adjList);
// addEdge(3, 0, 5, adjList);
// addEdge(3, 2, 9, adjList);
// addEdge(3, 4, 15, adjList);
// addEdge(3, 5, 6, adjList);
// addEdge(4, 1, 5, adjList);
// addEdge(4, 2, 7, adjList);
// addEdge(4, 3, 15, adjList);
// addEdge(4, 5, 8, adjList);
// addEdge(4, 6, 9, adjList);
// addEdge(5, 3, 6, adjList);
// addEdge(5, 4, 8, adjList);
// addEdge(5, 6, 11, adjList);
// addEdge(6, 4, 9, adjList);
// addEdge(6, 5, 11, adjList);

    

    int mincost=prims(V, adjList);
    cout<<"Minimum cost required to connect cities: "<<mincost;

    return 0;
}