#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x, x_test, cases = 1;
    float test;

    cin >> x;
    while(x > -1)
    {
        x = ceil(log2(x));
        
        cout << "Case " << cases << ": " << x << '\n';

        cases++;
        cin >> x;
    }


    return 0;
}