// ************************************************************************ //
//                             Broday Walker
//                           Depth-First Search
//   Description:
//
//
// *********************************************************************** //

#include <iostream>
#include <vector>

using namespace std;

const int N = 10;
const int UNVISITED = -1;
const int VISITED = 1;

void dfs(int);

// These are global for now just for ease of use. I would not
// do this in real life. The adjacency list is not initialized with any
// relationships/connections. This .cpp file was mainly used to practice
// writing the algorithm and to use it as a drop-in graph traversal for
// other problems.
vector<int> verts, parent;
vector<vector<pair<int, int>>> adjList;

int main()
{
    verts.resize(N);
    parent.resize(N);
    
    // Start at node 0
    dfs(0);

    return 0;
}

void dfs(int u)
{
    verts[u] = VISITED;

    // Will error for now because I haven't initialized the adjacency list
    // with any values.
    for(int j = 0; j < adjList[u].size(); j++) 
    {
        int v = adjList[u][j].first; 
        if(verts[v] == UNVISITED)
        {
            parent[v] = u;
            dfs(v); 
        }
    }
}