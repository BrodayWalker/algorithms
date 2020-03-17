//***************************************************************************
//  Broday Walker
//  Dr. Halverson
//  CMPS 5243
//  March 10, 2020
//  This program implements a hash class capable of both linear probing and
//  double hashing. Twenty keys are used to test the functionality of both
//  collision resolution policies. 
//
//***************************************************************************
//  Compilation: g++ main.cpp hash.cpp -o main.exe
//  Execution: ./main.exe
//***************************************************************************

#include "hash.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

float avg_probes(const vector<int> &);
void print_header(Hash::CRP, float, ofstream &);

int main()
{
    // Declarations
    int temp, probes; 
    float avg_linear, avg_double;
    vector<int> linear_probes, double_probes;

    // Open files
    ifstream infile;
    infile.open("infile.txt");
    ofstream outfile;
    outfile.open("output.txt");

    // Create a hash table of size 31 for initial testing
    Hash linear_table(31);
    Hash double_table(31);

    // Linear probing
    while(infile >> temp)
    {
        // Add number of probes to the accumulator
        probes = linear_table.insert(temp, linear_table.LINEAR_PROBE);
        linear_probes.push_back(probes);
    }
    // Find average number of linear probes
    avg_linear = avg_probes(linear_probes);

    infile.close();
    infile.open("infile.txt");

    // Double hashing
    while(infile >> temp)
    {
        // Add number of probes to the accumulator
        probes = double_table.insert(temp, double_table.DOUBLE_PROBE);
        double_probes.push_back(probes);
    }
    // Find average number of probes for double hashing
    avg_double = avg_probes(double_probes);

    // Print the header
    print_header(Hash::LINEAR_PROBE, avg_linear, outfile);
    // Print the table
    linear_table.Print_Table(outfile);

    // Print the header
    print_header(Hash::DOUBLE_PROBE, avg_double, outfile);
    // Print the table
    double_table.Print_Table(outfile);

    // Close files
    infile.close();
    outfile.close();

    return 0;
}

//***************************************************************************
//  function: avg_probes
//  arguments: const vector<int> &
//  returns: float
//  description: The avg_probes function sums the values held in the probe
//  count table and returns the average number of probes as a floating point
//  number.
//***************************************************************************
float avg_probes(const vector<int> &probe_table)
{
    int sum = 0;
    float avg;
    
    for (int i = 0; i < probe_table.size(); i++)
        sum += probe_table[i];

    avg = float(sum) / probe_table.size();

    return avg;
}

//***************************************************************************
//  function: print_header
//  arguments: Hash::CRP, float, ofstream &
//  returns: void
//  description: The print_header function prints the statistics for the
//  appropriate table depending upon the Collision Resolution Policy passed
//  to the function. This information is printed to the output file. The
//  print_header function is intended to be called immediately before
//  invoking the Hash object's internal print function.
//***************************************************************************
void print_header(Hash::CRP policy, float avg_probes, ofstream &outfile)
{
    outfile << fixed << setprecision(3);

    outfile << left << setw(12) << "Hash Table" << setw(5) << "CRP: ";
        // Print header based on Collision Resolution Policy
        if (policy == Hash::LINEAR_PROBE)
            outfile << "Linear Probing\n";
        else if (policy == Hash::DOUBLE_PROBE)
            outfile << "Double Hashing\n";
        else
            outfile << '\n';

        outfile << "Avg Probes: " << avg_probes << '\n';
        outfile << "===============================\n";
}