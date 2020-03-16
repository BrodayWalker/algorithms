//***************************************************************************
//	Broday Walker
//	Dr. Halverson
//	CMPS 5243-201
//	March 24, 2020
//***************************************************************************
#pragma once
#include <fstream>
#include <vector>

using namespace std;

enum CRP {LINEAR_PROBE, DOUBLE_PROBE};

class Hash {
    private:
        CRP policy;
        int table_size;
        int *table;
        int Lin_Probe(int);
        int Double_Probe(int);
        int Mod_Hash(int, int);

    public:
        Hash(int = 0, CRP = LINEAR_PROBE);
        CRP get_policy();
        int insert(int);
        void Print_Table(ofstream &);
        void make_clean();
        ~Hash();
};