// ************************************************************************ //
//                             Broday Walker
//                               Bubblesort
//                                 O(n^2)
//   Description: This is a bubblesort in ascending order performed on a
//  vector of integers.
//
// *********************************************************************** //

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

const int N = 10; // Amount of numbers to be put into the vector of integers

int main()
{
    // Seed random number generator
    srand(time(NULL));
    int temp;
    bool swapped = true;

    // Start with an unsorted vector of integers
    vector<int> ray;
    // Insert pseudo-random numbers into the vector
    for (int i = 0; i < N; i++)
        ray.push_back(rand() % 100);

    // Show original vector
    cout << "Original vector: ";
    // Print the vector for testing
    for (auto x : ray)
        cout << x << " ";
    cout << '\n';
    
   
    for(int i = 0; i < ray.size(); i++)
    {
        if(swapped)
        {
            // Reset flag
            swapped = false;
            for (int j = 1; j < ray.size() - i; j++)
            {
                // Do a swap if true
                if (ray[j - 1] > ray[j])
                {
                    temp = ray[j];
                    ray[j] = ray[j - 1];
                    ray[j - 1] = temp;
                    swapped = true;
                }
            }
        }

        if (!swapped)
            break;
        else
        {
            cout << "Iteration " << i + 1 << ": ";
            // Print the vector to show updates
            for (auto x : ray)
                cout << x << " ";
            cout << '\n';
        }

    }
    

    return 0;
}