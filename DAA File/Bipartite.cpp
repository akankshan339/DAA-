#include<bits/stdc++.h>
using namespace std;

bool isBipartite(int V, int src, vector<vector<int>>& adjMat, vector<int>& color) {
    color[src] = 1;
    queue<int> q;
    q.push(src);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int i = 1; i <= V; i++) { 
            if(adjMat[node][i] == 1) { // if there is an edge
                if(color[i] == -1) { // if not colored, color with opposite color
                    color[i] = !color[node];
                    q.push(i);
                } else if(color[i] == color[node]) {
                    return false;
                }
            }
        }
    }
    return true;
}

void addEdges(int u, int v, vector<vector<int>>& adjMat) {
    adjMat[u][v] = 1;
    adjMat[v][u] = 1;
}

int main() {
    int V, src;
    cout << "Enter no of vertices: \n";
    cin >> V;
    vector<vector<int>> adjMat(V + 1, vector<int>(V + 1, 0));
    vector<int> color(V + 1, -1);
    // addEdges(1, 2, adjMat); // eg 1 to check Non bipartite graph
    // addEdges(2, 3, adjMat);
    // addEdges(2, 6, adjMat);
    // addEdges(6, 5, adjMat);
    // addEdges(3, 4, adjMat);
    // addEdges(4, 5, adjMat);
    // addEdges(4, 7, adjMat);
    // addEdges(7, 8, adjMat);

    addEdges(1, 2, adjMat); // eg 1 to check Non bipartite graph
    addEdges(2, 3, adjMat);
    addEdges(3, 4, adjMat);

    cout << "Enter source node: \n";
    cin >> src;
    bool res = isBipartite(V, src, adjMat, color);
    if(res)
        cout << "Bipartite Graph!!! \n";
    else
        cout << "Not Bipartite Graph!!! \n";
    return 0;
}
