#include "hash.h"
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    Hash test(30);

    test.insertAux(3);
    test.insertAux(9);
    test.insertAux(44);

    test.Print_Table();


    return 0;
}