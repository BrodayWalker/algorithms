#include <iostream>

using namespace std;

int main()
{
    short int temp, nums[3];

    // Read in the numbers
    for(int i = 0; i < 3; i++)
        cin >> nums[i];

    while (nums[0] != 0 && nums[1] != 0 && nums[2] != 0)
    {
        // A short bubble sort (chosen because the input n will always be 3)
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                if(nums[j] > nums[j + 1])
                {
                    temp = nums[j + 1];
                    nums[j + 1] = nums[j];
                    nums[j] = temp;
                }

        // Check for right triangle
        if(((nums[0] * nums[0]) + (nums[1] * nums[1])) == (nums[2] * nums[2]))
            cout << "right\n";
        else
            cout << "wrong\n";
        
        // The last line of input is 0 0 0
        for(int i = 0; i < 3; i++)
            cin >> nums[i];
    }

    return 0;
}