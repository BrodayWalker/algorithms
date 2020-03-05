#include "hash.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>

using namespace std;

int main()
{
    // Declarations
    int temp, p;
    vector<int> probes;

    // Open input file that holds data for Tuesday's example
    ifstream infile;
    infile.open("infile.txt");

    // Seed the random number generator
    srand(time(NULL));

    // Create a hash table of size 31 for initial testing
    Hash table(31);

    // Insert 20 values from the input file
    // alpha = 64.5%
    while(infile >> temp)
    {
        p = table.insert(temp, table.LINEAR_PROBE);
        probes.push_back(p);
    }

    // Print number of probes
    for (auto x : probes)
        cout << x << " ";
    cout << '\n';

    table.Print_Table();

    infile.close();
    return 0;
}