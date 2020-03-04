#include "hash.h"
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    Hash test(31);

    test.insertAux(3);
    test.insertAux(9);
    test.insertAux(44);
    test.insertAux(123);
    test.insertAux(99);
    
    // Testing wrap
    test.insertAux(154);
    test.insertAux(154);
    test.insertAux(154);
    test.insertAux(154);


    test.Print_Table();


    return 0;
}