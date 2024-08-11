// #include<bits/stdc++.h>
// using namespace std;

// int shortestPathWeight(int V, int src, int dest, int K, vector<int> &adjList)
// {
//     int edgesWt =0;
//     vector<int>dist(V, INT_MAX);
//     dist[src] =0;


//     return edgesWt;
// }

// void addEdges(int u, int v, int wt, vector<int>&adjList)
// {

// }
// int main()
// {
//     int V, src , dest, K, wt;
//     cout << "Enter no of vertices: \n";
//     cin >> V;
//     vector<int> adjList(V);

//     addEdges(0, 2, 6, adjList);
//     addEdges(0, 1, 2, adjList);
//     addEdges(2, 3, 8, adjList);
//     addEdges(1, 3, 5, adjList);
//     addEdges(3, 4, 10, adjList);
//     addEdges(3, 5, 15, adjList);
//     addEdges(4, 6, 2, adjList);
//     addEdges(5, 6, 6, adjList);
//     cout << "Enter source node: \n";
//     cin >> src;
//     cout << "Enter destination node: \n";
//     cin >> dest;
//     cout<<"Enter no of edges: \n";
//     cin>>K;
//     wt = shortestPathWeight(V, src, dest, K, adjList);
    
// return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// const int INF = INT_MAX;

// int shortestPathWithKEdges(vector<vector<pair<int, int>>> &adjList, int source, int destination, int k) {
//     int V = adjList.size();
//     vector<vector<int>> dist(V, vector<int>(k + 1, INT_MAX));

//     priority_queue<pair< int, int> , vector<pair<int, int>>,  greater<pair<int, int>>> pq;


//     pq.push({0, source, 0});
//     dist[source][0] = 0;

//     while (!pq.empty()) {
//         auto [curDist, u, edges] = pq.top();
//         pq.pop();

//         if (u == destination && edges == k) {
//             return curDist;
//         }

//         if (edges > k) {
//             continue;
//         }

//         for (auto &[v, weight] : adjList[u]) {
//             if (dist[v][edges + 1] > curDist + weight) {
//                 dist[v][edges + 1] = curDist + weight;
//                 pq.push({dist[v][edges + 1], v, edges + 1});
//             }
//         }
//     }

//     return -1; // No path found
// }

// int main() {
//     int V, E;
//     cout << "Enter number of vertices and edges: ";
//     cin >> V >> E;

//     vector<vector<pair<int, int>>> adjList(V);
//     cout << "Enter the edges (u v weight):" << endl;
//     for (int i = 0; i < E; ++i) {
//         int u, v, weight;
//         cin >> u >> v >> weight;
//         adjList[u].push_back({v, weight}); // Directed graph
//     }

//     int source, destination, k;
//     cout << "Enter source, destination, and k: ";
//     cin >> source >> destination >> k;

//     int shortestWeight = shortestPathWithKEdges(adjList, source, destination, k);

//     if (shortestWeight == -1) {
//         cout << "No path from source to destination with exactly " << k << " edges." << endl;
//     } else {
//         cout << "Weight of the shortest path from source to destination with exactly " << k << " edges: " << shortestWeight << endl;
//     }

//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

int kEdgesShortestPath(int V, int src, int dest, int K, vector<vector<pair<int, int>>>& adjList) {
    vector<vector<vector<int>>> dp(V, vector<vector<int>>(V, vector<int>(K + 1, INF)));

    // Base case: distance from a node to itself with 0 edges is 0
    for (int u = 0; u < V; ++u) {
        dp[u][u][0] = 0;
    }

    // Fill the dp table
    for (int e = 1; e <= K; ++e) {
        for (int u = 0; u < V; ++u) {
            for (auto& edge : adjList[u]) {
                int v = edge.second;
                int w = edge.first;
                for (int src = 0; src < V; ++src) {
                    if (dp[src][u][e-1] != INF) {
                        dp[src][v][e] = min(dp[src][v][e], dp[src][u][e-1] + w);
                    }
                }
            }
        }
    }

    return (dp[src][dest][K] == INF) ? -1 : dp[src][dest][K];
}

void addEdges(int u, int v, int dist, vector<vector<pair<int, int>>>& adjList) {
    adjList[u].push_back({dist, v});  // directed
}

int main() {
    int V, src, dest, K;
    cout << "Enter number of vertices: \n";
    cin >> V;
    vector<vector<pair<int, int>>> adjList(V);
    int pathwt = 0;

    addEdges(0, 2, 3, adjList);
    addEdges(0, 1, 10, adjList);
    addEdges(0, 3, 2, adjList);
    addEdges(1, 3, 7, adjList);
    addEdges(2, 3, 6, adjList);

    cout << "Enter the source node and destination node: ";
    cin >> src >> dest;

    cout << "Enter number of edges: ";
    cin >> K;

    pathwt = kEdgesShortestPath(V, src, dest, K, adjList);

    if (pathwt == -1) {
        cout << "There is no path from " << src << " to " << dest << " with exactly " << K << " edges.\n";
    } else {
        cout << "Weight of the shortest path from " << src << " to " << dest << " with exactly " << K << " edges on the path is " << pathwt << endl;
    }

    return 0;
}
