#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int cases;
    long long int a, b;

    cin >> cases;

    for(int i = 0; i < cases; i++)
    {
        cin >> a >> b;
        if(a < b)
            cout << "<\n";
        else if (a > b)
            cout << ">\n";
        else
            cout << "=\n";
    }

    return 0;
}