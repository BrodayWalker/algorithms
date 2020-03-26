#include <iostream>

using namespace std;

int main()
{
    int cases;
    long long int n;

    cin >> cases;

    for(int i = 0; i < cases; i++)
    {
        cin >> n;

        n *= 63;
        n += 7492;
        n *= 5;
        n -= 498;

        // Get tens digit;
        n /= 10;

        if (n < 0)
            n = -n;

        n %= 10;
            
        cout << n << '\n';
    }

    return 0;
}