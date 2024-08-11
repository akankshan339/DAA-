#include <bits/stdc++.h>
using namespace std;
int primMST(int V, vector<vector<pair<int, int>>>& adjList) {
    // Priority queue to select the edge with the maximum weight
    priority_queue<pair<int, int>> pq;
    vector<bool> inMST(V, false);
    vector<int> maxEdgeWeight(V, INT_MIN);
    // Start with the first vertex (arbitrary choice)
    pq.push({0, 0}); // Push initial edge with weight 0
    maxEdgeWeight[0] = 0;
    int maxWeight = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        maxWeight += maxEdgeWeight[u];

        for (auto& edge : adjList[u]) {
            int adjWeight = edge.first;
            int v = edge.second;
            if (!inMST[v] && adjWeight > maxEdgeWeight[v]) {
                maxEdgeWeight[v] = adjWeight;
                pq.push({adjWeight, v});
            }
        }
    }
    return maxWeight;
}
int main() {
    int V;
    cout<<"Enter no of vertices : ";
    cin>>V;
    vector<vector<pair<int, int>>> adjList(V); 
    // Adding edges to the adjacency list
    adjList[0].push_back({7, 2});
    adjList[0].push_back({5, 3});
    adjList[1].push_back({8, 2});
    adjList[1].push_back({5, 3});
    adjList[2].push_back({7, 0});
    adjList[2].push_back({8, 1});
    adjList[2].push_back({9, 3});
    adjList[2].push_back({7, 4});
    adjList[3].push_back({5, 0});
    adjList[3].push_back({9, 2});
    adjList[3].push_back({15, 4});
    adjList[3].push_back({6, 5});
    adjList[4].push_back({5, 1});
    adjList[4].push_back({7, 2});
    adjList[4].push_back({15, 3});
    adjList[4].push_back({8, 5});
    adjList[4].push_back({9, 6});
    adjList[5].push_back({6, 3});
    adjList[5].push_back({8, 4});
    adjList[5].push_back({11, 6});
    adjList[6].push_back({9, 4});
    adjList[6].push_back({11, 5});
    int maxWeight = primMST(V, adjList);
    cout << "Maximum cost to connect cities: " << maxWeight << endl;
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// int primMST(int V, vector<vector<pair<int, int>>>& adjList) {
//     // Priority queue to select the edge with the maximum weight
//     priority_queue<pair<int, int>> pq;
//     vector<bool> inMST(V, false);
//     vector<int> maxEdgeWeight(V, INT_MIN);

//     // Start with the first vertex (arbitrary choice)
//     pq.push({0, 0}); // Push initial edge with weight 0
//     maxEdgeWeight[0] = 0;

//     int maxWeight = 0;

//     while (!pq.empty()) {
//         int u = pq.top().second;
//         pq.pop();

//         if (inMST[u]) continue;

//         inMST[u] = true;
//         maxWeight += maxEdgeWeight[u];

//         for (auto& [adjWeight, v] : adjList[u]) {
//             if (!inMST[v] && adjWeight > maxEdgeWeight[v]) {
//                 maxEdgeWeight[v] = adjWeight;
//                 pq.push({adjWeight, v});
//             }
//         }
//     }

//     return maxWeight;
// }

// int main() {
//     int V = 7;
//     vector<vector<pair<int, int>>> adjList(V);
    
//     // Adding edges to the adjacency list
//     adjList[0].push_back({7, 2});
//     adjList[0].push_back({5, 3});
//     adjList[1].push_back({8, 2});
//     adjList[1].push_back({5, 3});
//     adjList[2].push_back({7, 0});
//     adjList[2].push_back({8, 1});
//     adjList[2].push_back({9, 3});
//     adjList[2].push_back({7, 4});
//     adjList[3].push_back({5, 0});
//     adjList[3].push_back({9, 2});
//     adjList[3].push_back({15, 4});
//     adjList[3].push_back({6, 5});
//     adjList[4].push_back({5, 1});
//     adjList[4].push_back({7, 2});
//     adjList[4].push_back({15, 3});
//     adjList[4].push_back({8, 5});
//     adjList[4].push_back({9, 6});
//     adjList[5].push_back({6, 3});
//     adjList[5].push_back({8, 4});
//     adjList[5].push_back({11, 6});
//     adjList[6].push_back({9, 4});
//     adjList[6].push_back({11, 5});

//     int maxWeight = primMST(V, adjList);
//     cout << "Maximum cost to connect cities: " << maxWeight << endl;

//     return 0;
// }
