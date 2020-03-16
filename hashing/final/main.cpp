//***************************************************************************
//  Broday Walker
//  Dr. Halverson
//  CMPS 5243
//  March 24, 2020
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

void open_files(ifstream &, ifstream &, ofstream &);
void close_files(ifstream &, ifstream &, ofstream &);
float avg_probes(const vector<int> &);
void insert_data(Hash &, vector<int> &, ifstream &);
void print_header(float, CRP, ofstream &);

int main()
{
    // Declarations
    int temp, probes; 
    float avg_linear_66, avg_linear_80, avg_double_66, avg_double_80;
    vector<int> lin_66_probes, lin_80_probes, double_66_probes, double_80_probes;

    // Open files
    ifstream small_input, big_input;
    ofstream outfile;
    open_files(small_input, big_input, outfile);

    // Create hash tables of size 311
    Hash linear_66(311, LINEAR_PROBE);
    Hash linear_80(311, LINEAR_PROBE);
    Hash double_66(311, DOUBLE_PROBE);
    Hash double_80(311, DOUBLE_PROBE);

    insert_data(linear_66, lin_66_probes, small_input);
    insert_data(linear_80, lin_80_probes, big_input);
    insert_data(double_66, double_66_probes, small_input);
    insert_data(double_80, double_80_probes, big_input);

    // Find average number of linear probes
    avg_linear_66 = avg_probes(lin_66_probes);
    avg_linear_80 = avg_probes(lin_80_probes);
    // Find average number of probes for double hashing
    avg_double_66 = avg_probes(double_66_probes);
    avg_double_80 = avg_probes(double_80_probes);

    // Print the header
    print_header(avg_linear_66, linear_66.get_policy(), outfile);
    // Print the table
    linear_66.Print_Table(outfile);

    // Print the header
    print_header(avg_double_66, double_66.get_policy(), outfile);
    // Print the table
    double_66.Print_Table(outfile);

    close_files(small_input, big_input, outfile);

    return 0;
}

void open_files(ifstream &small_input, ifstream &big_input, ofstream &outfile)
{
    small_input.open("loop1_random205.txt");
    big_input.open("loop1_random250.txt");
    outfile.open("output.txt");
}

void close_files(ifstream &small_input, ifstream &big_input, 
    ofstream &outfile)
{
    small_input.close();
    big_input.close();
    outfile.close();
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
//  function: insert_data
//  arguments: Hash &, vector<int> &, ifstream &
//  returns: void
//  description: The insert_data function inserts integer keys into a hash
//  table using random data taken from the input file.
//***************************************************************************
void insert_data(Hash &table, vector<int> &probe_table, ifstream &input)
{
    int temp, probes;

    while(input >> temp)
    {
        // Insert key and count probes
        probes = table.insert(temp);
        // Add number of probes to the probe table
        probe_table.push_back(probes);
    }
}

//***************************************************************************
//  function: print_header
//  arguments: float, CRP, ofstream &
//  returns: void
//  description: The print_header function prints the statistics for the
//  appropriate table depending upon the Collision Resolution Policy passed
//  to the function. This information is printed to the output file. The
//  print_header function is intended to be called immediately before
//  invoking the Hash object's internal print function.
//***************************************************************************
void print_header(float avg_probes, CRP policy, ofstream &outfile)
{
    outfile << fixed << setprecision(3);

    outfile << left << setw(12) << "Hash Table" << setw(5) << "CRP: ";
        // Print header based on Collision Resolution Policy
        if (policy == LINEAR_PROBE)
            outfile << "Linear Probing\n";
        else if (policy == DOUBLE_PROBE)
            outfile << "Double Hashing\n";
        else
            outfile << '\n';

        outfile << "Avg Probes: " << avg_probes << '\n';
        outfile << "===============================\n";
}