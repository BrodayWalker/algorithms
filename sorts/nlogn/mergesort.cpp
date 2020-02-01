// ************************************************************************ //
//                             Broday Walker
//                               Mergesort
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

void mergeSort(vector<int> &, int, int);
void merge(vector<int> &, int, int, int);
void printVector(const vector<int> &);

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Build a vector of random integers between 0 and 99
    vector<int> ray;
    for (int i = 0; i < N; i++)
        ray.push_back(rand() % 100);

    cout << "Original: ";
    printVector(ray);

    mergeSort(ray, 0, ray.size() - 1);

    cout << "Sorted vector: ";
    printVector(ray);

    return 0;
}

void mergeSort(vector<int> &A, int left, int right)
{
    int middle;

    if (left < right)
    {
        // Find the middle of the vector
        middle = (left + right) / 2;

        // Split the vector
        mergeSort(A, left, middle); // Left side
        mergeSort(A, middle + 1, right); // Right side

        // Once the recursive splitting is done, start merge
        merge(A, left, middle, right);
    }
}

void merge(vector<int> &A, int left, int middle, int right)
{
    int i = left; // index for left half of vector
    int j = middle + 1; // index for right half of vector
    int k = 0; // index for temp vector
    vector<int> temp;
    temp.resize(right - left + 1);

    // Compare elements and place smaller of the two in the temp vector
    while (i <= middle && j <= right)
    {
        if(A[i] < A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }

    // If any elements are left over, copy them into the temp vector
    while (i <= middle)
        temp[k++] = A[i++];
    
    while (j <= right)
        temp[k++] = A[j++];

    // Copy the sorted temp vector into the original vector
    for (int i = left; i <= right; i++)
        A[i] = temp[i - left];
    
}

void printVector(const vector<int> &A)
{
    for (auto x : A)
        cout << x << " ";
    cout << '\n';
}