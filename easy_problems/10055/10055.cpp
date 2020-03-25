#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    /* Not used in UVA judging
    ifstream infile;
    infile.open("10055.txt");

    ofstream outfile;
    outfile.open("10055_outfile.txt");
    */

    long long int x, y, temp, result;

    while(cin >> x >> y)
    {
        // Swap
        if (y > x)
        {
            temp = x;
            x = y;
            y = temp;
        }

        result = x - y;
        cout << result << '\n';
    }

    /* Not used in UVA judging
    infile.close();
    outfile.close();
    */
    return 0;
}