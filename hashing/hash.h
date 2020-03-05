#pragma once
#include <iostream>

using namespace std;

class Hash {
    private:
        int table_size = 0;
        int *table = nullptr;
        int Lin_Probe(int);
        int Mod_Hash(int, int);

    public:
        Hash(int = 0);
        void insert(int);
        void Print_Table();


        ~Hash();
};