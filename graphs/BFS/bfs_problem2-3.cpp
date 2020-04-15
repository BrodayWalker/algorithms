//***************************************************************************
//  Broday Walker
//  Dr. Halverson
//  CMPS 5243 - Algorithm Analysis
//  April 17, 2020
//  Purpose: This code contains the algorithm used to solve section 22.2,
//  question 2-3. This code shows that only one bit is needed to keep track
//  of the color of each vertex with no negative effects on the results of
//  running BFS. Only one minor change was made to the algorithm in this
//  code; the rest is identical to bfs_problem2-1.cpp. The same input is
//  also used for the graph.
//
//  Compilation Instructions: g++ bfs_problem2-3.cpp -o main.exe
//  How to run: ./main.exe
//  Output: contained in output2-3.txt
//***************************************************************************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

const int N = 6; // The number of nodes

// WHITE = 0, GRAY = 1
enum Color {WHITE, GRAY};

int main()
{
    // All size declarations are N + 1 because the book numbers vertices 
    // from 1 to N rather than 0 to N - 1. For this reason, the 0th index 
    // will be ignored in all vectors.

    // Declare an adjacency list of size N
    vector<vector<int>> adjList(N + 1); 
    // These vectors hold the distance from the source and the parent
    vector<int> dist(N + 1, INT_MAX), parent(N + 1, -1);
    // Declare a vector of Colors and initialize as undiscovered
    vector<Color> color(N + 1, WHITE);

    queue<int> q;
    int source, row_size, vert;

    ifstream infile;
    infile.open("input2-1.txt");
    ofstream outfile;
    outfile.open("output2-3.txt");
    
    // Read from the input file to build the adjacency-list
    for(int i = 1; i < N + 1; i++)
    {
        infile >> row_size;

        for(int j = 0; j < row_size; j++)
        {
            infile >> vert;
            adjList[i].push_back(vert);
        }
    }

    
    outfile << "Adjacency-List Representation of Graph from Figure 22.2(a)"
            << "\n"
            << "===========================================\n";

    // Print the adjacency-list 
    for(int i = 1; i < adjList.size(); i++)
    {
        // Print the vertex we are on
        outfile << "Vertex " << i << ": ";

        // Print all adjacent vertices 
        for(int j = 0; j < adjList[i].size(); j++)
            outfile << adjList[i][j] << " ";

        outfile << '\n';
    }
    
    outfile << "===========================================\n\n\n";


    // Set the source vertex
    source = 3;
    // Set the source's distance as 0
    dist[source] = 0;
    // Set source to discovered
    color[source] = GRAY;
    // Enqueue the source
    q.push(source);
    

    // Do BFS
    while(!q.empty())
    {
        // Get front of queue
        int u = q.front();
        q.pop();

        // Traverse adjacency-list for vertex u and enqueue all undiscovered
        // vertices
        for(int j = 0; j < adjList[u].size(); j++)
        {
            // Get next adjacent vertex
            int v = adjList[u][j];
            // If adjacent vertex is undiscovered, enqueue it
            if(color[v] == WHITE)
            {
                color[v] = GRAY; // Set to discovered
                dist[v] = dist[u] + 1; // Distance is u's distance + 1
                parent[v] = u; // Vertex u is vertex v's parent
                q.push(v); // Enqueue vertex v
            }
        }
        // Finished processing vertex u
        // No need to change the color of the vertex further
    }

    outfile << "BFS Results\n";
    outfile << setw(6) << "Vertex" << setw(10) << "Parent" << setw(12) 
            << "Distance" << '\n';
    // Print the distance from source and parent for each vertex
    for(int i = 1; i < N + 1; i++)
    {
        // Print vertex number
        outfile << setw(6) << i << setw(10) << parent[i] << setw(12);
        
        // If the vertex was discovered, print the parent vertex number
        // and distance as an integer
        if(dist[i] != INT_MAX)
            outfile << dist[i];
        else
            outfile << "Infinity";
        
        outfile << '\n';
    }
    

    infile.close();
    outfile.close();
    return 0;
}