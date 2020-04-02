#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int cases, num_players, captain, current_case = 1;

    cin >> cases;

    for(int i = 0; i < cases; i++)
    {
        vector<int> players;

        cin >> num_players;

        players.resize(num_players);

        for(int j = 0; j < num_players; j++)
            cin >> players[j];

        captain = players[(num_players / 2)];
        
        cout << "Case " << current_case << ": " << captain << '\n';

        current_case++;
    }


    return 0;
}