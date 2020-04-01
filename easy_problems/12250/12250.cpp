#include <iostream>
#include <string>

using namespace std;

const int SIZE = 6;

int main()
{
    string hello[6] = {"HELLO", "HOLA", "HALLO", "BONJOUR", "CIAO", "ZDRAVSTVUJTE"};
    string lang[6] = {"ENGLISH", "SPANISH", "GERMAN", "FRENCH", "ITALIAN", "RUSSIAN"};
    string input;
    int cases = 1;
    bool found = false;

    cin >> input;
    while(input != "#")
    {
        cout << "Case " << cases << ": ";

        // Find the word
        for(int i = 0; i < SIZE; i++)
            if(input == hello[i])
            {
                cout << lang[i];
                found = true;
            }
        
        if (!found)
            cout << "UNKNOWN";
        
        cout << '\n';

        // Reset for next iteration
        found = false;
        cases++;
        cin >> input;
    }

    return 0;
}