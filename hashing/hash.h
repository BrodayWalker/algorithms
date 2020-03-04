#pragma once
#include <iostream>

using namespace std;

class Hash {
    private:
        int *table = nullptr;
        int insert(int);

    public:
        Hash(int = 0);
        void insertAux(int);


        ~Hash();
};