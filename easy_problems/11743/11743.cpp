#include <iostream>

using namespace std;

const int HALF = 8, CARD_SIZE = 16;

int main()
{
    short int cases, temp, sum = 0, nums[4], card_number[CARD_SIZE];

    cin >> cases;

    for(int i = 0; i < cases; i++)
    {
        // Read in the data
        for(int j = 0; j < 4; j++)
            cin >> nums[j];

        // Split the four-digit numbers into single digits
        for(int j = 0; j < 4; j++)
        {
            for(int k = 3; k >= 0; k--)
            {
                card_number[k + j * 4] = nums[j] % 10;
                nums[j] /= 10;
            }
        }

        // 1. double every other digit
        // 2. add the individual digits of the doubled number
        for(int j = 0; j < HALF; j ++)
        {
            // Double
            temp = card_number[j * 2] * 2;
            // Add individual digits
            sum += ((temp % 10) + (temp / 10));
        }

        // Add the unmodified digits to the accumulator
        for(int j = 1; j < CARD_SIZE; j += 2)
            sum += card_number[j];

        // If the sum ends in a 0, the credit card number is valid
        if(sum % 10 == 0)
            cout << "Valid\n";
        else
            cout << "Invalid\n";

        // Reset accumulator
        sum = 0;
    }

    return 0;
}