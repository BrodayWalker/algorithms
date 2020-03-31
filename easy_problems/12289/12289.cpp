#include <iostream>
#include <string>

using namespace std;

int main()
{
    int cases, one_sum = 0, two_sum = 0;
    string input, one = "one", two = "two";

    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        cin >> input;

        if(input.size() == 5)
            cout << 3 << '\n';
        else
        {
            // The problem states only one letter will be incorrect, so it is easy
            // to test which one is wrong by comparing to the target string
            for(int j = 0; j < 3; j++)
            {
                if(input[j] == one[j])
                    one_sum++;

                if(input[j] == two[j])
                    two_sum++;
            }

            // Guess which word was intended (two of the three letters should be correct)
            if(one_sum > two_sum)
                cout << "1\n";
            else
                cout << "2\n";
        }

        one_sum = 0;
        two_sum = 0;
    }

    return 0;
}