#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    struct person 
    {
        string name = "";
        int money = 0;
    };
    int group_size, starting_money, money_per, num_receivers, spacing = 0;
    string giver, receiver;

    // Read in the data
    while(cin >> group_size)
    {
        if(spacing != 0)
            cout << '\n';
        spacing++;

        vector<person> friends(group_size);
        // Read in friend names
        for(int i = 0; i < group_size; i++)
            cin >> friends[i].name;
         
        // Allocate money
        for(int i = 0; i < group_size; i++)
        {
            int giver_index;
            // Give money to other friends
            cin >> giver >> starting_money >> num_receivers;
            // Find the giver
            for(int j = 0; j < group_size; j++)
                if(friends[j].name == giver)
                    giver_index = j;
                
            
            // The amount of money each person receives from the giver
            if(num_receivers > 0)
                money_per = starting_money / num_receivers;
            else
                money_per = 0;
            
            // Decrement the amount to be given from the giver
            // This calculation is done in this manner to take into account
            // the money lost to truncation during integer division. The
            // rules state only integer amounts may be given and the giver
            // keeps the left over money that cannot be evenly distributed.
            friends[giver_index].money -= starting_money;
            friends[giver_index].money += (starting_money - (money_per * num_receivers));

            // Find the receiver and give them money
            for(int j = 0; j < num_receivers; j++)
            {
                cin >> receiver;
                for(int k = 0; k < group_size; k++)
                    // Give away the money
                    if(friends[k].name == receiver)
                        friends[k].money += money_per;
            }

        }

        // Output the results
        for(int i = 0; i < group_size; i++)
            cout << friends[i].name << " " << friends[i].money << '\n';
    }

    return 0;
}