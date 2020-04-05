#include <iostream>

using namespace std;

int main()
{
    int input, speed, t, n, cases = 1;

    // Read in number of test cases
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        // Read in number of runners
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> input;

            if(input > speed)
                speed = input;
        }

        cout << "Case " << cases << ": " << speed << '\n';

        // Reset speed
        speed = -1;
        cases++;
    }

    return 0;
}