//***************************************************************************
//	Broday Walker
//	Dr. Halverson
//	CMPS 5243-201
//	
//***************************************************************************

#include "hash.h"
#include <iostream>

using namespace std;

// Default constructor accepts an integer for the size of the array to be
// dynamically allocated. The default value is 0.
Hash::Hash(int size) 
{
    // Dynamically allocate a hash table of size passed to the constructor
    table = new int[size];

    // Set all values in the table to INT_MIN as default
    for (int i = 0; i < size; i++)
        table[i] = INT_MIN;

    // Save table size for convenience
    table_size = size;
}

// Insert accepts an integer value to insert into the table
void Hash::insert(int key)
{ 
    int lin_probes;
    lin_probes = Lin_Probe(key); 
}

// Lin_Probe inserts a key using linear probing as the collision resolution
// policy
int Hash::Lin_Probe(int key)
{
    // num_probes is not implemented yet
    int loc, num_probes = 1;
    bool inserted = false;

    // Get the location of the key in the table
    loc = Mod_Hash(key, table_size);

    //**********************************************************************************************
    // This is just for testing
    // There is no way to keep track of the number of probes yet
    // The linear probing collision policy does work, though
    //**********************************************************************************************

    // Try to insert the key into the table
    // If true, the element holds a default value (safe to insert)
    if (table[loc] == INT_MIN)
        table[loc] = key;
    else 
    {
        // If num_probes exceeds the table size, it is safe to assume the 
        // table is full
        // The loop stops when the key has been inserted or the table has been
        // found to be full
        while (num_probes <= table_size && inserted == false)
        {
            int next = (loc + num_probes) % table_size;
            // If the element is open, insert the key
            if (table[next] == INT_MIN) 
            {
                table[next] = key;
                inserted = true;
            }
            num_probes++;
        }
    }
    
    return num_probes;
}

// Hash function: key % N where key is an integer value to be 
// inserted into the hash table and N is the size of the hash table
// Returns the location the value hashed to in the table
int Hash::Mod_Hash(int key, int N)
{ return key % N; }

// Prints the table
void Hash::Print_Table()
{
    for (int i = 0; i < table_size; i++)
        cout << "Element " << i << ": " << table[i] << '\n';
}

// Destructor
Hash::~Hash()
{
    // Free the memory allocated for the table
    delete [] table;
}