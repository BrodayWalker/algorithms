#include <iostream>

using namespace std;

int main()
{
    long long int x, y, result;

    while(cin >> x >> y)
    {
        result = x^y;
        cout << result << '\n';
    }

    return 0;
}