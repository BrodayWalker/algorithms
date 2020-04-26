//***************************************************************************
//  Broday Walker
//  Dr. Halverson
//  CMPS 5243 - Algorithm Analysis
//  April 26, 2020
//  Purpose: 
//
//  Compilation Instructions: g++ AdjMatrixGen.cpp -o AdjMatrixGen.exe -std=c++11
//  How to run: ./AdjMatrixGen.exe
//  Output: Printed to OutputAdjMatrix.txt
//***************************************************************************

#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int main()
{
    // A variable to control the number of times datasets processed
    int dataset = 1;

    // Open the output text file
    ofstream outfile;
    outfile.open("OutputAdjMatrix.txt");

    while(dataset <= 3)
    {
        // Declarations for each matrix
        string u, v, start, end;
        map<string, set<string>> adjMat;
        // The naming scheme for the iterators is intended to follow the 
        // U -> V pattern from the textbook
        map<string, set<string>>::iterator u_itor; // Iterator for the vertices
        map<string, set<string>>::iterator outer_row;
        set<string>::iterator v_itor; // Iterator for adjacent vertices
        
        // Input file declarations
        ifstream infile;

        if(dataset == 1)
            infile.open("dataset1.txt");
        else if(dataset == 2)
            infile.open("dataset2.txt");
        else
            infile.open("dataset3.txt");
        
        // Read in all the edges between vertices
        while (infile >> u >> v)
        {
            // Insert the adjacent vertices into their respective set in 
            // the matrix
            // C++ sets are ordered and are typically implemented as red-black 
            // trees under the hood
            // The set container is not as fast as an unordered_set C++ container, 
            // but the ordering facilitates a simpler printing scheme later in 
            // the program

            adjMat[u].insert(v); // U -> V
            adjMat[v].insert(u); // V -> U
        }

        u_itor = adjMat.begin(); // Points to the beginning of the map container

        // Title
        outfile << "ADJACENCY MATRIX " << dataset << '\n';
        outfile << "===============================================\n";

        // For formatting the column headers
        outfile << setw(4) << " ";

        // Print the column headers
        while(u_itor != adjMat.end())
        {
            outfile << setw(4) << u_itor->first;
            u_itor++;
        }
        outfile << '\n';

        // Set the iterator back to the beginning of the map
        u_itor = adjMat.begin();

        // adjMat.end() is one memory location beyond the end of the container,
        // so the loop runs from the beginning of the container to the end + 1
        // to allow for easy processing of the last location as well
        while(u_itor != adjMat.end())
        {
            // The outer_row iterator initially points to the first location in 
            // the map that holds the vertices
            // The value pointed to by outer_row will be compared to the value 
            // pointed to below by v_itor. If the value of both pointers is equal, 
            // the edge exists and a 1 is printed. In that case, both pointers are 
            // incremented. If the values pointed to by both are not equal, no 
            // edge exists, so a 0 is printed. In that case, only the outer_row 
            // pointer is incremented.
            outer_row = adjMat.begin();
            
            // Consider the edge U -> V
            // itor->first represents vertex U
            outfile << setw(4) << u_itor->first;

            // Point v_itor to the beginning of vertex U's adjacency matrix
            // In other words, this points to what will be the beginning of 
            // the row of the adjacency matrix for vertex U.
            v_itor = u_itor->second.begin();
            

            // While not all vertices have been compared
            while(outer_row != adjMat.end())
            {   
                // Different syntax for each pointer is used as v_itor is pointing
                // to a set container only while outer_row is pointing to a map
                // of pairs of strings and sets of strings

                // The value of v_itor will be an adjacent vertex to vertex U
                // The value of outer_row->first will be one of the vertices
                // in the set of all the vertices in this graph
                if(*v_itor == outer_row->first)
                {
                    outfile << setw(4) << "1";
                    v_itor++;
                }
                else
                    outfile << setw(4) << "0";
                
                outer_row++;
            }
            outfile << '\n';

            // Go to the next vertex that needs a matrix row generated
            u_itor++;    
        }

        outfile << "===============================================\n\n\n";

        // Close this input file
        infile.close();

        dataset++;
    }

    outfile.close();
    return 0;
}