// ************************************************************************ //
//                             Broday Walker
//                               Quicksort
//                               O(n logn)
//   Description:
//
//
// *********************************************************************** //

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

const int N = 10;

void quicksort(vector<int> &, int, int);
int partition(vector<int> &, int, int);
void printVector(const vector<int> &);

int main()
{
    // Seed random number generator
    srand(time(NULL));

    // Start with an unsorted vector of integers
    vector<int> ray;
    for (int i = 0; i < N; i++)
        ray.push_back(rand() % 1000);
    
    cout << "Original: ";
    printVector(ray);

    quicksort(ray, 0, ray.size() - 1);

    cout << "Sorted: ";
    printVector(ray);

    return 0;
}

void quicksort(vector<int> &A, int left, int right)
{
    if (left < right)
    {
        // Get partition index
        int p_index = partition(A, left, right);

        // Split on partition
        quicksort(A, left, p_index - 1); // left side
        quicksort(A, p_index + 1, right); // right side
    }
}

int partition(vector<int> &A, int left, int right)
{
    int pivot = A[right];
    int temp = 0;
    int i = left - 1;

    for(int j = left; j <= right - 1; j++)
    {
        if (A[j] <= pivot)
        {
            // Swap
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    // Now that all swaps are complete, swap the pivot into its place
    temp = A[i + 1];
    A[i + 1] = A[right];
    A[right] = temp;

    // Return the location of the pivot
    return i + 1;
}

void printVector(const vector<int> &A)
{
    for (auto x : A)
        cout << x << " ";
    cout << '\n';
}