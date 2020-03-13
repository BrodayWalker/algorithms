//***************************************************************************
//  Broday Walker
//  Dr. Halverson
//  CMPS 5243
//  March 24, 2020
//  This program is a random number generator for the hash table program.
//  Running this program results in two text files being generated: one file
//  with 205 unique random integer numbers and one with 250 unique random
//  integer numbers.
//***************************************************************************
//  Compilation: g++ random_gen.cpp -o random_gen.exe
//  Execution: ./random_gen.exe
//***************************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <time.h>

using namespace std;

int main()
{
    // Two unordered sets are used
    unordered_set<int> small_set;
    unordered_set<int> big_set;
    int linebreak = 0;

    // Open the output files
    ofstream random205, random250;
    random205.open("random205.txt");
    random250.open("random250.txt");

    // Seed the random number generator
    srand(time(NULL));

    // Generate 205 random numbers for the small set
    for (int i = 0; i < 205; i++)
        small_set.insert(rand() % 5000);

    // Generate 250 random numbers for the big set
    for (int i = 0; i < 250; i++)
        big_set.insert(rand() % 5000);

    // Sanity check: print the size of each set to the console
    // If the sizes are too small, more random numbers will be generated
    // and added to the appropriate set(s).
    cout << "Sizes after initial insertions:\n";
    cout << "Size of small set (should be 205): " << small_set.size() << '\n';
    cout << "Size of big set (should be 250): " << big_set.size() << '\n';

    // If there were any duplicate numbers, the size of the small set
    // will be less than 205. Insert random numbers until the set size
    // is 205.
    while (small_set.size() < 205)
        small_set.insert(rand() % 5000);

    // If there were any duplicate number, the size of the big set
    // will be less than 250. Insert random numbers until the set size
    // is 250.
    while (big_set.size() < 250)
        big_set.insert(rand() % 5000);

    // Sanity check: print the size of each set to the console
    cout << "Sizes after filling in sets where necessary:\n";
    cout << "Size of small set (should be 205): " << small_set.size() << '\n';
    cout << "Size of big set (should be 250): " << big_set.size() << '\n';

    // Transfer the random numbers to the output files
    for (auto itor : small_set)
    {
        random205 << itor << " ";
        if (++linebreak % 10 == 0)
            random205 << '\n';
    }

    linebreak = 0;
    for (auto itor : big_set)
    {
        random250 << itor << " ";
        if (++linebreak % 10 == 0)
            random250 << '\n';
    }

    random205.close();
    random250.close();

    return 0;
}