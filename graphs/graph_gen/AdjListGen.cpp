//***************************************************************************
//  Broday Walker
//  Dr. Halverson
//  CMPS 5243 - Algorithm Analysis
//  April 26, 2020
//  Purpose: 
//
//  Compilation Instructions: g++ AdjListGen.cpp -o AdjListGen.exe -std=c++11
//  How to run: ./AdjListGen.exe
//  Output: Printed to OutputAdjLists.txt
//***************************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    // Declarations
    string u, v;
    map<string, vector<string>> adjList;
    map<string, vector<string>>::iterator itor;

    // Input and output file declarations
    ifstream infile;
    infile.open("small_data.txt");
    ofstream outfile;
    outfile.open("OutputAdjLists.txt");

    // Read in all the edges between vertices
    while (infile >> u >> v)
    {
        // Add the adjacent vertices to their respective list
        adjList[u].push_back(v); // U -> V
        adjList[v].push_back(u); // V -> U
    }

    outfile << left << setw(12) << "Vertices" << setw(12) << "Adjacent" << '\n';

    // Set the iterator to the beginning of the map
    itor = adjList.begin();
    while(itor != adjList.end())
    {
        // Consider the edge U -> V
        // itor->first represents vertex U
        outfile << setw(12) << itor->first;
        for(int i = 0; i < itor->second.size(); i++)
            // itor->second is a vector of strings
            // itor->second[i] is the ith vertex in U's adjacency list
            outfile << itor->second[i] << " ";
        outfile << '\n';

        // Increment the iterator
        itor++;    
    }

    // Close up shop
    infile.close();
    outfile.close();
    return 0;
}