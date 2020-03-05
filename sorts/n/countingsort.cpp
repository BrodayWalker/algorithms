// ************************************************************************ //
//                             Broday Walker
//                             Counting Sort
//                                 O(n)
//   Description:
//
//
// *********************************************************************** //

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

// Change N to desired vector size
const int N = 10;
// The value of BIGGEST is the largest integer
// that will be generated by rand()
const int BIGGEST = 10;


void countingsort(vector<int> &, vector<int> &);
void printVector(const vector<int> &);

int main()
{
    // Seed random number generator
    srand(time(NULL));

    // Start with an unsorted vector of integers
    vector<int> ray;
    for(int i = 0; i < N; i++)
        ray.push_back(rand() % BIGGEST);
    
    vector<int> counts = {0};
    counts.resize(BIGGEST);
    
    cout << "Original: ";
    printVector(ray);

    /***********************************************************************
     * 
     * Call sorting algorithm here
     * 
     ***********************************************************************/
    countingsort(ray, counts);
    
    cout << "Counts: ";
    printVector(counts);
    cout << "Sorted: ";
    printVector(ray);

    return 0;
}

void countingsort(vector<int> &A, vector<int> &counts)
{
    // Count the frequency of each number
    for(int i = 0; i < A.size(); i++)
        counts[A[i]]++;

    int k = 0;
    // Transfer numbers in ascending order
    for(int i = 0; i < counts.size(); i++)
        for (int j = 0; j < counts[i]; j++)
            A[k++] = i;
}

void printVector(const vector<int> &A)
{
    for (auto x : A)
        cout << x << " ";
    cout << '\n';
}