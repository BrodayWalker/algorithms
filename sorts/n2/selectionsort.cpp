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

void selectionsort(vector<int> &);
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

    selectionsort(ray);

    cout << "Sorted: ";
    printVector(ray);

    return 0;
}

void selectionsort(vector<int> &A)
{
    int smallest, small_index, temp;
    for (int i = 0; i < A.size(); i++)
    {
        smallest = A[i];
        small_index = i;
        for (int j = i; j < A.size(); j++)
        {
            // Find smallest value
            if(A[j] < smallest)
            {
                smallest = A[j];
                small_index = j;
            }
        }
        // Swap smallest value of the sub-vector to its proper place
        temp = A[i];
        A[i] = A[small_index];
        A[small_index] = temp;
    }
}

void printVector(const vector<int> &A)
{
    for (auto x : A)
        cout << x << " ";
    cout << '\n';
}