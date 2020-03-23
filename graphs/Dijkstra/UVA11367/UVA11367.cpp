// ************************************************************************ //
//                             Broday Walker
//                                UVA 341
//  Description: Solved using Dijkstra's Algorithm
//
//  Compilation: g++ UVA11367.cpp -o main.exe -std=c++11
// *********************************************************************** //

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

const int BILLION = 1000000000;

int main()
{
    // Open the input file
    ifstream infile;
    infile.open("input.txt");

    int cities, roads, u, v, d, queries, fuel_capacity, start, end, result;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Read in n cities and m roads
    // Guarantees: 1 <= n < 1000 and 0 <= m <= 10000
    // 1. The first line of input gives n cities and m roads
    infile >> cities >> roads;

    // These declarations depend on the number of cities (nodes)
    vector<int> fuel_price(cities, 0), dist(cities, BILLION), parent(cities, -1);
    vector<vector<pair<int,int>>> adjList(cities);
    
    // 2. Then follows a line with n integers 1 <= p[i] <= 100, where p sub i is
    // the fuel price in the ith city.
    // Read in fuel prices
    for (int i = 0; i < fuel_price.size(); i++)
        infile >> fuel_price[i];

    // 3. Then follows m (roads) lines with three integers 0 <= u, v < n and 1 <= d <= 100,
    // telling that there is a road between u and v with length d.
    // Build the adjacency list
    for (int i = 0; i < roads; i++)
    {
        infile >> u >> v >> d;
        adjList[u].push_back(pair<int, int>(v, d));
    }

    // 4. Then comes a line with the number 1 <= q <= 100 giving the number of queries
    infile >> queries;
    
    // 5. Read in q lines of three integers per line: 1 <= c <= 100, s, and e
    // where c = fuel capacity of the vehicle, s = starting city, and e = end goal
    for (int i = 0; i < queries; i++)
    {
        int p, edge_cost, prev_cost = 0, cost = 0;
        bool possible = true;
        vector<int> path;
        infile >> fuel_capacity >> start >> end;

        // Set distance from start node to itself as 0
        dist[start] = 0;
        // Enqueue the distance and node id for the start node
        pq.push(pair<int, int>(0, start));
    
        // Dijkstra's
        while(!pq.empty())
        {
            // Get next node from the priority queue then remove it
            pair<int, int> front = pq.top();
            pq.pop();

            d = front.first;
            u = front.second; 
           
            // Ignore the item if we have already relaxed the edge
            if (d > dist[u])
                continue;

            // Iterate through adjacency list for node u
            for (int j = 0; j < adjList[u].size(); j++)
            {
                // Recall that the adjacency list stores the vertex v, then distance d
                pair<int, int> v = adjList[u][j];

                // If true, relax
                if (dist[u] + v.second < dist[v.first])
                {
                    // Relax edge
                    dist[v.first] = dist[u] + v.second;
                    // Track parent node
                    parent[v.first] = u;
                    // Enqueue the new pair
                    pq.push(pair<int, int>(dist[v.first], v.first));
                }
            }
        }
        
        // Start at this node and work back through the parent nodes to the start
        p = end;
        path.push_back(p);
        while (p != start)
        {
            path.push_back(parent[p]);
            p = parent[p];
        }


        // Print result
        if(possible)
            cout << cost << '\n';
        else
            cout << "impossible\n";
        
        // Reset distances
        for(int i = 0; i < dist.size(); i++)
            dist[i] =  BILLION;
    }




    // Close the input file
    infile.close();
    return 0;
}