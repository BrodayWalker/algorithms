// ************************************************************************ //
//                             Broday Walker
//                             Binary Search
//   Description:
//
//
// *********************************************************************** //

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int list[] = {1, 5, 12, 13, 22, 43, 55, 67, 89, 90, 93, 95, 99};
    // Start with a sorted vector of integers
    vector<int> ray;
    for (auto x : list)
        ray.push_back(x);

    // Target number we are searching for
    int target = 69;
    bool found = false;

    // Find the beginning, middle, and end elements of the array
    int begin = 0;
    int end = ray.size() - 1;
    int middle = (begin + end) / 2;
    

    // If the number we are looking for is smaller than the value held in
    // the middle element, go low; else, go high. Repeat until the value is
    // found or we until we cannot split the array any further.
    while (!found && begin <= end)
    {
        middle = (begin + end) / 2;
        if (target > ray[middle])
            begin = middle + 1;
        else if (target < ray[middle])
            end = middle - 1;
        else
            found = true;
    }

    // Check to see if the target was found
    if (found)
        cout << "Number " << target << " found at element " << middle << ".\n";
    else
        cout << "Target not found.\n";
    
    return 0;
}