#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    long long int cuts, result;

    while(cin >> cuts)
    {
        if (cuts != -1)
        {
            result = ((cuts * (cuts + 1)) / 2) + 1;
            cout << result << '\n';
        }
    }

    return 0;
}

