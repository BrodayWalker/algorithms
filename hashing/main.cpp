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
    vector<int> linear_probes, double_probes;

    // Open input file that holds data for Tuesday's example
    ifstream infile;
    infile.open("infile.txt");

    // Seed the random number generator
    srand(time(NULL));

    // Create a hash table of size 31 for initial testing
    Hash linear_table(31);
    Hash double_table(31);

    // Insert 20 values from the input file
    // alpha = 64.5%
    // Linear probing
    while(infile >> temp)
    {
        p = linear_table.insert(temp, linear_table.LINEAR_PROBE);
        linear_probes.push_back(p);
    }

    infile.close();
    infile.open("infile.txt");

    // Double hashing
    while(infile >> temp)
    {
        p = double_table.insert(temp, double_table.DOUBLE_PROBE);
        double_probes.push_back(p);
    }


    // Print number of probes
    for (auto x : linear_probes)
        cout << x << " ";
    cout << '\n';

    linear_table.Print_Table();

    for(auto x : double_probes)
        cout << x << " ";
    cout << '\n';

    double_table.Print_Table();

    infile.close();
    return 0;
}