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
    int dataset = 1;

    // Declare and open output file
    ofstream outfile;
    outfile.open("OutputAdjLists.txt");

    while(dataset <= 3)
    {
        // Graph declarations
        string u, v;
        map<string, vector<string>> adjList;
        map<string, vector<string>>::iterator itor;

        // Input file declaration
        ifstream infile;

        // Open and use every input file once 
        if(dataset == 1)
            infile.open("dataset1.txt");
        else if(dataset == 2)
            infile.open("dataset2.txt");
        else
            infile.open("dataset3.txt");
        
        // Read in all the edges between vertices
        while (infile >> u >> v)
        {
            // Add the adjacent vertices to their respective list
            adjList[u].push_back(v); // U -> V
            adjList[v].push_back(u); // V -> U
        }

        outfile << "ADJACENCY LIST " << dataset << '\n';
        outfile << "------------------------------\n";
        outfile << left << setw(10) << "Vertices" << setw(12) << "Adjacent" << '\n';

        // Set the iterator to the beginning of the map
        itor = adjList.begin();
        while(itor != adjList.end())
        {
            // Consider the edge U -> V
            // itor->first represents vertex U
            outfile << setw(3) << " " << setw(7) << itor->first;
            for(int i = 0; i < itor->second.size(); i++)
                // itor->second is a vector of strings
                // itor->second[i] is the ith vertex in U's adjacency list
                outfile << itor->second[i] << " ";
            outfile << '\n';

            // Increment the iterator
            itor++;    
        }

        outfile << "\n\n";

        // Close this input file
        infile.close();

        dataset++;
    }

    outfile.close();
    return 0;
}