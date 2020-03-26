#include <iostream>

using namespace std;

int main()
{
    short int cases, temp;
    short int nums[3];

    cin >> cases;

    for(int i = 0; i < cases; i++)
    {
        for(int j = 0; j < 3; j++)
            cin >> nums[j];

        // A bubble sort, which is okay to use for such a small input size n 
        // (which is guaranteed to be 3 for every case in this problem).
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 2 - j; k++)
                if(nums[k] > nums[k + 1])
                {
                    // swap
                    temp = nums[k + 1];
                    nums[k + 1] = nums[k];
                    nums[k] = temp; 
                }

        // Print result, pick the middle element from the sort array of 3 salaries
        cout << "Case " << i + 1 << ": " << nums[1] << '\n';
    }

    return 0;
}