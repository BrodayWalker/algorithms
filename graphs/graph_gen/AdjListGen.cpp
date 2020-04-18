//***************************************************************************
//  Broday Walker
//  Dr. Halverson
//  CMPS 5243 - Algorithm Analysis
//  April 18, 2020
//  Purpose: 
//
//  Compilation Instructions: 
//  How to run:
//  Output:
//***************************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // Declarations
    int u, v;
    vector<vector<int>> adjList;

    // Input and output file declarations
    ifstream infile;
    infile.open("small_data.txt");
    ofstream outfile;
    outfile.open("OutputAdjLists.txt");

    // Read in the data pairs
    while(infile >> u >> v)
    {
    
        // Resize the adjacency list vector if necessary because he number of
        // vertices in the graph is not always known before building the 
        // adjacency list

        // Note: We must check for greater than or equal to because sub-
        // scripting starts at 0. If the adjList size is 10 and we try
        // to subscript adjList[10], we are going to have a bad time.
        // This is also the reason why the resize operation uses the vertex
        // ID plus 1.
        if(u >= adjList.size()  || v >= adjList.size())
        {
            // Resize the adjacency list to hold the largest vertex ID
            if(u >= v)
                adjList.resize(u + 1);
            else
                adjList.resize(v + 1);
        }
           
        // Add the edge to both vertices' adjacency list because this is
        // an undirected graph
        adjList[u].push_back(v); // U -> V
        adjList[v].push_back(u); // V -> U
    }


    // Print the column labels
    outfile << setw(12) << left << "Vertices" << setw(8) << "Adjacent" << '\n';
    // Print the adjacency list
    for(int i = 0; i < adjList.size(); i++)
    {
        outfile << setw(12) << i;

        for(int j = 0; j < adjList[i].size(); j++)
            outfile << adjList[i][j] << " ";
        
        outfile << '\n';
    }





    // Close up shop
    infile.close();
    outfile.close();
    return 0;
}