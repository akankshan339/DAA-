#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int V) {
        rank.resize(V + 1);
        parent.resize(V + 1);
        for (int i = 0; i <= V; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {

        int ulp_u=findParent(u);      //find ultimate parent of u and v
    int ulp_v=findParent(v);
    if(ulp_u == ulp_v)
        return;
    else if(rank[ulp_u] < rank[ulp_v])
        parent[ulp_u] = ulp_v;         //parent of u is v
    else if(rank[ulp_u]> ulp_v)
        parent[ulp_v] = ulp_u;          //parent of v is u
    else
    {                             //parent of u and v are same
        parent[ulp_u] = ulp_v;          //can make any parent u or v 
        rank[ulp_v]++;                  //++ rank of parent of either u or v outside if else
    }
    }
};

class Graph {
    int V;
public:
    Graph(int V) {
        this->V = V;
    }

    void addEdge(int wt, int u, int v, vector<vector<int>>& adjList) {
        adjList.push_back({wt, u, v});
    }

    int Kruskal_MST(vector<vector<int>>& adjList) {
        sort(adjList.begin(), adjList.end());

        DisjointSet ds(V);
        vector<pair<int, pair<int, int>>> mst;
        int mincost = 0;

        for (auto edge : adjList) {
            int wt = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (ds.findParent(u) != ds.findParent(v)) {
                mst.push_back({wt, {u, v}});
                mincost += wt;
                ds.unionByRank(u, v);
            }
        }

        cout << "Map of cities and roads in form of a graph.: is\n";
        for (auto it : mst) {
            cout << it.second.first << " -- " << it.second.second << " weight = " << it.first << endl;
        }

        return mincost;
    }
};

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> adjList;
    Graph g(V);
    
    g.addEdge(2, 0, 1, adjList);        //wt, u, v
    g.addEdge(6, 0, 3, adjList);
    g.addEdge(3, 1, 2, adjList);
    g.addEdge(8, 1, 3, adjList);
    g.addEdge(5, 1, 4, adjList);
    g.addEdge(7, 4, 2, adjList);
    int mincost = g.Kruskal_MST(adjList);
    cout << "Minimum cost required to connect cities: " << mincost << endl;

    return 0;
}
