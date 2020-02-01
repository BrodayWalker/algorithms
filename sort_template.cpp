// ************************************************************************ //
//                             Broday Walker
//                               Algorithm
//                            Time Complexity
//   Description:
//
//
// *********************************************************************** //

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

const int N = 10;

void printVector(const vector<int> &);

int main()
{
    // Seed random number generator
    srand(time(NULL));
    // Start with an unsorted vector of integers
    vector<int> ray;
    for(int i = 0; i < N; i++)
        ray.push_back(rand() % 1000);
    
    cout << "Original: ";
    printVector(ray);



    return 0;
}

void printVector(const vector<int> &A)
{
    for (auto x : A)
        cout << x << " ";
    cout << '\n';
}