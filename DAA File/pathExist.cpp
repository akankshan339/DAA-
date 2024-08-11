//using adjencency List 
//for undirected graph path exist to given graph from any src to any dest node 
//for directed graph path does not exist to given graph from any src to any dest node eg 5 to 1 no path
#include<bits/stdc++.h>
using namespace std;

bool findPath(int src, int dest, vector<int>adjList[], vector<bool>&visited)
{
    visited[src] = true;

    if(src == dest)
        return true;

    for(int adj: adjList[src])
    {
        if(!visited[adj])
        {
            if(findPath(adj, dest, adjList, visited) == true)
               return true;
        }

    }
return false;
}
void addEdges(int u, int v, vector<int>adjList[])
{
    adjList[u].push_back(v);
  //  adjList[v].push_back(u);    //for undirected graph
}
int main()
{
    int V, src, dest;
    cout<<"Enter no of vertices: \n";
    cin>>V;
    vector<int>adjList[V+1];            //for 1 based indexing if take V then start from 0
    vector<bool>visited(V+1,false);
    addEdges(1, 2, adjList);
    addEdges(1, 3, adjList);
    addEdges(3, 4, adjList);
    addEdges(3, 2, adjList);
    addEdges(2, 4, adjList);
    addEdges(2, 5, adjList);
    addEdges(4, 5, adjList);

    cout<<"Enter source and Destination node : \n";
    cin>>src;
    cin>>dest;

    bool ans =findPath(src, dest, adjList, visited);
    if(ans)
        cout<<"Yes Path Exist : \n";
    else
        cout<<"Path does not Exist : \n";
return 0;
}

//using adjencency matrix

/*#include<bits/stdc++.h>
using namespace std;

bool findPath(int src, int dest, vector<vector<int>> &adjMat, vector<bool>&visited)
{
    visited[src] = true;

   if(src == dest)
    return true;
    for(int i =0; i<adjMat[src].size(); i++)
    {
        if(adjMat[src][i] == 1 && !visited[i])
        {
        if(findPath(i, dest, adjMat, visited))
        return true;
        }
    }
return false;
}
void addEdges(int u , int v, vector<vector<int>> &adjMat)
{
    adjMat[u][v] =1;
    adjMat[v][u] = 1;
}
int main()
{
    int V, src, dest;
    cout<<"Enter no of vertices: \n";
    cin>>V;
    vector<vector<int>> adjMat(V+1 , vector<int>(V+1, 0));
    vector<bool>visited(V+1,false);
    addEdges(1, 2, adjMat);
    addEdges(1, 3, adjMat);
    addEdges(3, 4, adjMat);
    addEdges(3, 2, adjMat);
    addEdges(2, 4, adjMat);
    addEdges(2, 5, adjMat);
    addEdges(4, 5, adjMat);

    cout<<"Enter source and Destination node : \n";
    cin>>src;
    cin>>dest;

    bool ans =findPath(src, dest, adjMat, visited);
    if(ans)
        cout<<"Yes Path Exist : \n";
    else
        cout<<"Path does not Exist : \n";
return 0;
}
*/