#include <iostream>

using namespace std;

int main()
{
    short int cases, temp, sum = 0, grades[7];
    char final_grade;

    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        // Read in the grades
        for(int j = 0; j < 7; j++)
            cin >> grades[j];
        // Sort last three elements
        for(int k = 4; k < 6; k++)
            for (int m = 4; m < 6; m++)
                if (grades[m] > grades[m + 1])
                {
                    temp = grades[m + 1];
                    grades[m + 1] = grades[m];
                    grades[m] = temp;
                }

        // Add first five grades
        for(int j = 0; j < 4; j++)
            sum += grades[j];

        // Add the average of the two highest test grades
        sum += ((grades[5] + grades[6]) / 2);

        // Print the result
        if(sum >= 90)
            final_grade = 'A';
        else if (sum >= 80)
            final_grade = 'B';
        else if (sum >= 70)
            final_grade = 'C';
        else if (sum >= 60)
            final_grade = 'D';
        else
            final_grade = 'F';
        
        cout << "Case " << i + 1 << ": " << final_grade << '\n';

        // Reset the accumulator
        sum = 0;
    }


    return 0;
}