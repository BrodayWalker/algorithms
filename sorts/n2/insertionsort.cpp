// ************************************************************************ //
//                             Broday Walker
//                             Insertionsort
//                                O(n^2)
//   Description:
//
//
// *********************************************************************** //

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

void insertionsort(vector<int> &);
void printVector(const vector<int> &);

const int N = 10;

int main()
{
    // Seed the random number generator
    srand(time(NULL));
    // Start with an unsorted vector of integers
    vector<int> ray;
    for (int i = 0; i < N; i++)
        ray.push_back(rand() % 1000);
    
    cout << "Original: ";
    printVector(ray);

    insertionsort(ray);

    cout << "Sorted: ";
    printVector(ray);

    return 0;
}

void insertionsort(vector<int> &A)
{
    int i, j, key;

    for(j = 1; j < A.size(); j++)
    {
        key = A[j];
        i = j - 1;

        // Sort in ascending order
        while(i >= 0 && A[i] > key)
        {
            A[i + 1] = A[i];
            i--;
        }

        A[i + 1] = key;
    }
}

void printVector(const vector<int> &A)
{
    for (auto x : A)
        cout << x << " ";
    cout << '\n';
}