#include "hash.h"
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a hash table of size 31 for initial testing
    Hash test(31);

    test.insert(3);
    test.insert(9);
    test.insert(44);
    test.insert(123);
    test.insert(99);
    
    // Testing wrap
    test.insert(154);
    test.insert(154);
    test.insert(154);
    test.insert(154);


    test.Print_Table();


    return 0;
}