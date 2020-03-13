//***************************************************************************
//	Broday Walker
//	Dr. Halverson
//	CMPS 5243-201
//	March 24, 2020
//  hash.cpp includes all methods implemented and used by the hash class.
//***************************************************************************

#include "hash.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

//***************************************************************************
//  method: Hash
//  arguments: none or an integer 
//  returns: none
//  description: This default constructor dynamically allocates a new hash 
//  table. The value passed to the constructor is used as the size of the new
//  hash table if that value is greater than 0. If no value is passed to the
//  constructor, it defaults to 0, in which case a table is not created.
//***************************************************************************
Hash::Hash(int size) 
{
    // Dynamically allocate a hash table of size passed to the constructor
    if (size > 0)
    {
        table = new int[size];
        // Set all values in the table to INT_MIN as default
        for (int i = 0; i < size; i++)
            table[i] = INT32_MIN;
    } 
    else
        table = nullptr;

    // Save table size for convenience
    table_size = size;
}

//***************************************************************************
//  method: insert
//  arguments: int, CRP
//  returns: integer number of probes
//  description: The insert method accepts a key to insert into the hash
//  table and a Collision Resolution Policy (CRP). The CRP is used to
//  to invoke the proper auxiliary insertion method. The insert method will
//  either invoke Lin_Probe when LINEAR_PROBE is passed or Double_Probe when
//  DOUBLE_PROBE is passed.
//***************************************************************************
int Hash::insert(int key, CRP policy)
{ 
    int probes;
    
    if (policy == LINEAR_PROBE)
        probes = Lin_Probe(key); 
    else if (policy == DOUBLE_PROBE)
        probes = Double_Probe(key);

    return probes;
}

//***************************************************************************
//  method: Lin_Probe
//  arguments: int
//  returns: integer number of probes
//  description: The Lin_Probe method accepts an integer key passed from the
//  insert method. Lin_Probe inserts the key into the hash table using linear
//  probing as a collision resolution policy.
//***************************************************************************
int Hash::Lin_Probe(int key)
{
    int loc, num_probes = 1;
    bool inserted = false;

    // Get the location of the key in the table
    loc = Mod_Hash(key, table_size);

    // Try to insert the key into the table
    // If true, the element holds a default value (safe to insert)
    if (table[loc] == INT32_MIN)
        table[loc] = key;
    else 
    {
        // If num_probes exceeds the table size, it is safe to assume the 
        // table is full
        // The loop stops when the key has been inserted or the table has 
        // been found to be full
        while (num_probes <= table_size && inserted == false)
        {
            int next = (loc + num_probes) % table_size;
            // If the element is open, insert the key
            if (table[next] == INT32_MIN) 
            {
                table[next] = key;
                inserted = true;
            }
            num_probes++;
        }
    }
    
    return num_probes;
}

//***************************************************************************
//  method: Double_Probe
//  arguments: int
//  returns: integer number of probes
//  description: The Double_Probe method accepts an integer key from the
//  insert method. Double_Probe inserts the key into the hash table using
//  double hashing as the collision resolution policy.
//***************************************************************************
int Hash::Double_Probe(int key)
{
    int loc, num_probes = 1;
    bool inserted = false;

    // Get the location of the key in the table
    loc = Mod_Hash(key, table_size);

    // Try to insert the key into the table
    // If true, the element holds a default value (safe to insert)
    if (table[loc] == INT32_MIN)
        table[loc] = key;
    else 
    {
        // If num_probes exceeds the table size, it is safe to assume the 
        // table is full
        // The loop stops when the key has been inserted or the table has 
        // been found to be full

        // Find the increment (last digit of the key + 1)
        int inc = (key % 10) + 1;
        int next = (loc + inc) % table_size;
        while (num_probes <= table_size && inserted == false)
        {
            // If the element is open, insert the key
            if (table[next] == INT32_MIN) 
            {
                table[next] = key;
                inserted = true;
            }
            // Find next location to try to insert in
            next = (next + inc) % table_size;
            num_probes++;
        }
    }
    
    return num_probes;
}

//***************************************************************************
//  method: Mod_Hash
//  arguments: int, int
//  returns: integer value representing a location in the hash table
//  description: The Mod_Hash method implements a simple hashing algorithm
//  by performing a modulus operation on the integer key value using the size
//  of the table. The result of this calculation represents the location to
//  which the key maps to in the table if no collision occurs upon insertion.
//***************************************************************************
int Hash::Mod_Hash(int key, int N)
{ return key % N; }

//***************************************************************************
//  method: Print_Table
//  arguments: ofstream &
//  returns: void
//  description: The Print_Table method accepts an ofstream object passed by
//  reference. The method prints the contents of the table to the output
//  file.
//***************************************************************************
void Hash::Print_Table(ofstream &outfile)
{
    // Print Headings
    outfile << setw(12) << "Location" << setw(13) << "Value" << '\n';
    outfile << "===============================\n";

    // Print body
    for (int i = 0; i < table_size; i++)
        outfile << setw(12) << i << setw(13) << table[i] << '\n';
    outfile << "===============================\n\n\n";
}

//***************************************************************************
//  method: make_clean
//  arguments: none
//  returns: void
//  description: The make_clean method traverses the hash table resetting
//  all values to INT32_MIN. When the method has completed, the hash table
//  will be in the same state as a new Hash object of size table_size.
//***************************************************************************
void Hash::make_clean()
{
    // Reset all values
    for (int i = 0; i < table_size; i++)
        table[i] = INT32_MIN;
}

//***************************************************************************
//  method: ~Hash
//  arguments: none
//  returns: none
//  description: The Hash class destructor frees the memory allocated to the
//  hash table upon destruction of the class.
//***************************************************************************
Hash::~Hash()
{
    // Free the memory allocated for the table
    delete [] table;
}