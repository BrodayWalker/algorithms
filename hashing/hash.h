#pragma once
#include <iostream>

using namespace std;

class Hash {
    private:
        int table_size;
        int *table;
        int Lin_Probe(int);
        int Double_Probe(int);
        int Mod_Hash(int, int);

    public:
        enum CRP {LINEAR_PROBE, DOUBLE_PROBE};
        
        Hash(int = 0);
        int insert(int, CRP);
        void Print_Table();
        void make_clean();

        ~Hash();
};