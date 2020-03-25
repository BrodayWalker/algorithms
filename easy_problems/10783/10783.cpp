#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int low, high, cases;
    long long int sum = 0;

    cin >> cases;

    for (int i = 1; i <= cases; i++)
    {
        cin >> low >> high;

        // If the starting number is even, skip it because we are only
        // interested in summing the odd numbers
        if (low % 2 == 0)
            low += 1;

        // Add all odd numbers to the accumulator
        for (int j = low; j <= high; j += 2)
            sum += j;

        cout << "Case " << i << ": " << sum << '\n';
        sum = 0; // Reset accumulator
    }

    return 0;
}