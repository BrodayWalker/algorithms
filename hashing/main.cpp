#include "hash.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <time.h>

using namespace std;

float avg_probes(const vector<int> &);
void print_probes(int);

int main()
{
    // Declarations
    int temp, probe_count;
    vector<int> linear_probes, double_probes;

    // Open input file that holds data for Tuesday's example
    ifstream infile;
    infile.open("infile.txt");

    // Seed the random number generator
    srand(time(NULL));

    // Only print 3 decimal places
    cout << fixed << setprecision(3);

    // Create a hash table of size 31 for initial testing
    Hash linear_table(31);
    Hash double_table(31);

    // Insert 20 values from the input file
    // alpha = 64.5%

    // Linear probing
    while(infile >> temp)
    {
        probe_count = linear_table.insert(temp, linear_table.LINEAR_PROBE);
        linear_probes.push_back(probe_count);
    }

    infile.close();
    infile.open("infile.txt");

    // Double hashing
    while(infile >> temp)
    {
        probe_count = double_table.insert(temp, double_table.DOUBLE_PROBE);
        double_probes.push_back(probe_count);
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

    double_table.make_clean();
    double_table.Print_Table();

    float tempo = avg_probes(linear_probes);
    cout << "Average number of probes: " << tempo << '\n';
    tempo = avg_probes(double_probes);
    cout << "Average number of probes: " << tempo << '\n';

    infile.close();
    return 0;
}

float avg_probes(const vector<int> &probe_table)
{
    int sum = 0;
    float avg;
    
    for (int i = 0; i < probe_table.size(); i++)
        sum += probe_table[i];

    avg = float(sum) / probe_table.size();

    return avg;
}


void print_probes(int avg)
{


}