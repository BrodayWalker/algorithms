//***************************************************************************
//  Broday Walker
//  Dr. Halverson
//  CMPS 5243
//  March 24, 2020
//  This program is the final version of the hashing experiment. When the 
//  program is run, four different hash tables are tested with varying load
//  factors. Once all data is inserted into the tables, the average probe
//  count is calculated. These results are used to show the difference in
//  average probe count between hash tables using linear probing and double
//  hashing for their collision resolution policy. The experiment is run two
//  times using two sets of pseudo-random numbers.
//***************************************************************************
//  Compilation: g++ -std=c++11 main.cpp hash.cpp -o main.exe
//  Execution: ./main.exe
//***************************************************************************

#include "hash.h"
#include <iostream>
#include <ios>
#include <istream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

void close_files(ifstream &, ifstream &);
float avg_probes(const vector<int> &);
void insert_data(Hash &, vector<int> &, ifstream &);
void print_header(float, int, CRP, ofstream &);

int main()
{
    // Declarations
    int temp, probes; 
    float avg_linear_66, avg_linear_80, avg_double_66, avg_double_80;
    vector<int> lin_66_probes, lin_80_probes, double_66_probes, 
        double_80_probes;

    ofstream outfile;
    outfile.open("output.txt");
    
    // Create hash objects with tables of size 311
    Hash linear_66(311, LINEAR_PROBE), linear_80(311, LINEAR_PROBE);
    Hash double_66(311, DOUBLE_PROBE), double_80(311, DOUBLE_PROBE);

    // Run the experiment two times with two different sets of input
    for(int i = 0; i < 2; i++)
    {
        ifstream small_input, big_input;
        int position;

        // This controls which input files are used
        if (i == 0)
        {
            small_input.open("loop1_random205.txt");
            big_input.open("loop1_random250.txt");
        }
        else if (i == 1)
        {
            small_input.open("loop2_random205.txt");
            big_input.open("loop2_random250.txt");
        }

        // Linear probing
        insert_data(linear_66, lin_66_probes, small_input);
        insert_data(linear_80, lin_80_probes, big_input);

        /* Note */
        // This is very ugly. I did not want to close the files and reopen
        // them to go back to the start of the file. I tried unsuccessfully
        // for several hours to clear the eof bit using <file>.clear() and 
        // seek to the start of the file using <file>.seekg(0, <file>.beg)

        // Close files then reopen them to start back at the beginning
        small_input.close();
        big_input.close();

        // Use the appropriate input files
        if (i == 0)
        {
            small_input.open("loop1_random205.txt");
            big_input.open("loop1_random250.txt");
        }
        else if (i == 1)
        {
            small_input.open("loop2_random205.txt");
            big_input.open("loop2_random250.txt");
        }

        // Double hashing
        insert_data(double_66, double_66_probes, small_input);
        insert_data(double_80, double_80_probes, big_input);

        // Find average number of linear probes
        avg_linear_66 = avg_probes(lin_66_probes);
        avg_linear_80 = avg_probes(lin_80_probes);
        // Find average number of probes for double hashing
        avg_double_66 = avg_probes(double_66_probes);
        avg_double_80 = avg_probes(double_80_probes);

        // Print experiment number
        outfile << "===============================\n";
        outfile << "Experiment #" << i + 1 << '\n';
        outfile << "===============================\n\n";

        // Print the linear tables
        print_header(avg_linear_66, 66, linear_66.get_policy(), outfile);
        linear_66.Print_Table(outfile);

        print_header(avg_linear_80, 80, linear_80.get_policy(), outfile);
        linear_80.Print_Table(outfile);

        // Print the double hashing tables
        print_header(avg_double_66, 66, double_66.get_policy(), outfile);
        double_66.Print_Table(outfile);

        print_header(avg_double_80, 80, double_80.get_policy(), outfile);
        double_80.Print_Table(outfile);

        // Reset hash objects and probe vectors
        linear_66.make_clean();
        linear_80.make_clean();
        double_66.make_clean();
        double_80.make_clean();

        lin_66_probes.clear();
        lin_80_probes.clear();
        double_66_probes.clear();
        double_80_probes.clear();

        close_files(small_input, big_input);
    }

    outfile.close();
    return 0;
}

//***************************************************************************
//  function: close_files
//  arguments: ifstream &, ifstream &
//  returns: void
//  description: The close_files function closes two ifstream objects.
//***************************************************************************
void close_files(ifstream &small_input, ifstream &big_input)
{
    small_input.close();
    big_input.close();
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
//  arguments: float, int, CRP, ofstream &
//  returns: void
//  description: The print_header function prints the statistics for the
//  appropriate table depending upon the Collision Resolution Policy passed
//  to the function. This information is printed to the output file. The
//  print_header function is intended to be called immediately before
//  invoking the Hash object's internal print function.
//***************************************************************************
void print_header(float avg_probes, int load_factor, CRP policy, ofstream &outfile)
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

        outfile << "Load factor: " << load_factor << "%\n";
        outfile << "Avg Probes: " << avg_probes << '\n';
        outfile << "===============================\n";
}