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
Hash::Hash(int size = 0) 
{
    // Dynamically allocate a hash table of size passed to the constructor
    table = new int[size];
}

// Insert accepts an integer value to insert into the table
void Hash::insertAux(int val)
{
    
}




// Destructor
Hash::~Hash()
{
    // Free the memory allocated for the table
    delete [] table;
}