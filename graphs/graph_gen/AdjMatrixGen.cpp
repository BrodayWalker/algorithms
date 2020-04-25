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

#include <algorithm> // for lexicographical_compare
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    // Declarations
    string u, v, start, end;
    vector<string> keys;
    unordered_map<string, vector<string>> adjMat;
    unordered_map<string, vector<string>>::iterator itor;

    // Input and output file declarations
    ifstream infile;
    infile.open("small_data.txt");
    ofstream outfile;
    outfile.open("OutputAdjMatrix.txt");


    // Read in all the edges between vertices
    while (infile >> u >> v)
    {

        // Add the adjacent vertices to their respective list in the matrix
        adjMat[u].push_back(v); // U -> V
        adjMat[v].push_back(u); // V -> U
    }

    itor = adjMat.begin();
    start = itor->first;
    end = itor->first;

    while(itor != adjMat.end())
    {
        if(start.compare(itor->first) )
            start = itor->first;

        if(itor->first > end)
            end = itor->first;

        itor++;
    }

    /*
    // Get the lexicographically smallest string
    start = adjMat.begin()->first;
    // Keep in mind that adjMat.end() is actually one memory location beyond 
    // the end of adjMat
    itor = adjMat.end();
    // itor is decremented to point to the real last element in adjMat
    end = (--itor)->first;
    */

    cout << start << " " << end << '\n';



    // Build a list of vertices between the smallest vertex to the largest vertex 
    // in lexicographically-ascending order

    
    // Generate a list of vertices between the smallest vertex and the largest
    // This is necessary as it is not possible to increment a whole string, but
    // is is possible to increment a character; luckily, strings are arrays of
    // characters. This while loop includes some extra logic to handle keys that
    // are strings made up of numbers or letters but not both mixed together.

    //
    //  lexicographical_compare(start.begin(), start.end(), end.begin(), end.end()) != 0
    //
    //  start.compare(end) != 0
    while(start.compare(end) != 0)
    {
        int last_elem = start.size() - 1;
        
        // Insert the key into the vector of keys
        // These are used later to print column and row headers
        keys.push_back(start);

        // Some extra logic for increments the string represenation of numbers
        if(start[last_elem] == '9')
        {
            int rollover = last_elem;
            // Find the most significant digit that is not a nine and increment it
            while(start[rollover] == '9' && rollover >= 0)
                rollover--;
            // If rollover == -1, all characters that make up the string are nines
            // This would happen if, for example, start = "999" and we want to make
            // start = "1000"
            if(rollover == -1)
            {
                start[0] = '1';

                for(int i = 1; i <= last_elem; i++)
                    start[i] = '0';

                start.push_back('0');
            }
            else 
            {
                // Consider the string start = "1299"
                // Rollover would point to start[1]
                // Start[rollover] goes from '2' to '3'
                // Zero out all less significant digits
                // Result is start = "1300"
                start[rollover]++;
                for(int i = rollover + 1; i <= last_elem; i++)
                    start[i] = '0';
            }
        }
        else
            start[last_elem]++;

    }
    keys.push_back(end);
    
    for(auto x : keys)
        outfile << x << " ";
    outfile << '\n';


    outfile << left;

    // Set the iterator to the beginning of the map
    itor = adjMat.begin();
    while(itor != adjMat.end())
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