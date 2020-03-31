#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int cases = 1, n;
    
    cin >> n;
    while (n != 0)
    {
        int temp, diff, given = 0, not_given = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            if(temp > 0)
                not_given++;
            else
                given++;
        }

        diff = not_given - given;

        // Print result
        cout << "Case " << cases << ": " << diff << '\n';

        cases++;
        cin >> n;
    }

    return 0;
}