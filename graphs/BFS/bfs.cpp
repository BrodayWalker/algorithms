// ************************************************************************ //
//                             Broday Walker
//                          Breadth-First Search
//   Description:
//
//
// *********************************************************************** //

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 10;
const int UNVISITED = -1;
const int VISITED = 1;

void bfs(int);

// These are global for now just for ease of use. I would not
// do this in real life. The adjacency list is not initialized with any
// relationships/connections. This .cpp file was mainly used to practice
// writing the algorithm and to use it as a drop-in graph traversal for
// other problems.
vector<int> verts, parent, d;
vector<vector<pair<int, int>>> adjList;
queue<int> q;

int main()
{
    verts.resize(N);
    parent.resize(N);

    // Start at vertex 0
    // Distance to start node is 0
    d[0] = 0;
    verts[0] = VISITED;
    q.push(0);

    return 0;
}

void bfs(int u)
{
    u = q.front();
    q.pop();

    while(!q.empty())
    {
        for(int j = 0; j < adjList[u].size(); j++)
        {
            int v = adjList[u][j].first;
            if(v == UNVISITED)
            {
                verts[v] = VISITED;
                d[v] = d[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}