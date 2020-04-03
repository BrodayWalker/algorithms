#include <iostream>

using namespace std;

int main()
{
    int n, k, butts, total, new_total = 0;

    while(cin >> n >> k)
    {
        // Pete smokes this number of cigarettes off the bat
        total = n;
        // Pete can save his cigarette butts to make more cigarettes
        butts = n;

        while(butts >= k)
        {
            // The new number of cigarettes Pete can make
            new_total = butts / k;
            butts = butts - (new_total * k);
            // He smokes them and adds the butts to the butt pile
            total += new_total;
            butts += new_total;    
        }

        cout << total << '\n';
    }


    return 0;
}