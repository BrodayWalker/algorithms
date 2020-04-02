#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    int cases, num_grades, above_average = 0;
    float average, percent_above, sum = 0;

    // Set output to three decimal places
    cout << fixed << setprecision(3);

    cin >> cases;
    
    for(int i = 0; i < cases; i++)
    {
        vector<int> grades;

        cin >> num_grades;

        grades.resize(num_grades);

        // Sum the grades
        for(int j = 0; j < num_grades; j++)
        {
            cin >> grades[j];
            sum += grades[j];
        }

        // Find the average
        average = sum / num_grades;

        // Count the number of grades above the average
        for(int j = 0; j < num_grades; j++)
            if(float(grades[j]) > average)
                above_average++;

        // Calculate the number of grades above average as a percentage
        percent_above = float(above_average) / num_grades;
        percent_above *= 100;

        cout << percent_above << "%\n";
        
        // Reset the accumulators
        above_average = 0;
        sum = 0;
    }

    return 0;
}