#include "hash.h"
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

int main()
{
    // Declarations
    int temp;

    // Open input file that holds data for Tuesday's example
    ifstream infile;
    infile.open("infile.txt");

    // Seed the random number generator
    srand(time(NULL));

    // Create a hash table of size 31 for initial testing
    Hash table(31);

    while(infile >> temp)
        table.insert(temp);


    table.Print_Table();

    infile.close();
    return 0;
}