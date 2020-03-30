//*************************************************************************** //
//						Project 1 1D STL Vector
//						Name: Broday Walker
//						Advanced Structures and Algorithms - CMPS 3013
//						Date: January 28, 2019						
//*************************************************************************** //
//	This program reads input from stdin and stores it in three vectors for
//	friends 1, 2, and 3. Each vector contains a set of integers. All vectors are
//	compared and the unique numbers for each friend are stored in a new vector.
//	The vector sets of unique numbers are then sorted and compared to see which
//	friend solved the most problems that the others did not. The result is
//	printed to show which friend solved the most problems, how many they solved,
//	and the unique number for each problem solved.
//*************************************************************************** //
//
//	I have written the entire program as turned in and have not copied this
//	code, or parts of this code from the internet or another student.
//
//
//	Signature ______________________________________________________________
// 
//*************************************************************************** //
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void readIn(vector<int> &);
void sortVector(vector<int> &);
void printWinner(vector<int> &, vector<int> &, vector<int> &);

int main() {
	// Declarations
	int tCases; // Total number of test cases
	int s1, s2, s3; // Number of problems solved by each friend
	vector<int> friend1, friend2, friend3; // Initial input for each friend
	vector<int> f1unique, f2unique, f3unique; // Answer vector

	//	Read in the number of cases
	cin >> tCases;

	for (int i = 0; i < tCases; i++) {
		//	Read in data and store in vectors
		readIn(friend1);
		readIn(friend2);
		readIn(friend3);

		// Sort each vector in ascending order. The sort algorithm used is
		// included in std:: and is O(N log(N)) complexity.
		sortVector(friend1);
		sortVector(friend2);
		sortVector(friend3);

		//	Compare all vectors and find the unique problems not solved by the
		//	other two friends. The unique numbers are then stored in the 
		//	friendXunique vector. I believe the search is n^3 as it compares
		//	all elements in the vector with the other two vectors.

		//	friend1 comparisons with friend2 and friend3
		for (int j = 0; j < friend1.size(); j++) {
			//	Only do the check if the problem number is not a duplicate.
			//	This step assumes a sorted vector.
			if (j == 0) {
				auto iter1 = find(friend2.begin(), friend2.end(), friend1[j]);
				auto iter2 = find(friend3.begin(), friend3.end(), friend1[j]);

				if (iter1 == friend2.end() && iter2 == friend3.end())
					f1unique.push_back(friend1[j]);
			}
			
			if (j > 0) {
				if (friend1[j] != friend1[j - 1]) {
					auto iter1 = find(friend2.begin(), friend2.end(), 
						friend1[j]);
					auto iter2 = find(friend3.begin(), friend3.end(), 
						friend1[j]);

					if (iter1 == friend2.end() && iter2 == friend3.end())
						f1unique.push_back(friend1[j]);
				}
			}	
		}

		//	friend2 comparisons with friend1 and friend3
		for (int j = 0; j < friend2.size(); j++) {
			if (j == 0) {
				auto iter1 = find(friend1.begin(), friend1.end(), friend2[j]);
				auto iter2 = find(friend3.begin(), friend3.end(), friend2[j]);

				if (iter1 == friend1.end() && iter2 == friend3.end())
					f2unique.push_back(friend2[j]);
			}
			
			if (j > 0) {
				if (friend2[j] != friend2[j - 1]) {
					auto iter1 = find(friend1.begin(), friend1.end(), 
						friend2[j]);
					auto iter2 = find(friend3.begin(), friend3.end(), 
						friend2[j]);

					if (iter1 == friend1.end() && iter2 == friend3.end())
						f2unique.push_back(friend2[j]);
				}
			}
		}

		//	friend3 comparisons with friend1 and friend2
		for (int j = 0; j < friend3.size(); j++) {
			if (j == 0) {
				auto iter1 = find(friend1.begin(), friend1.end(), friend3[j]);
				auto iter2 = find(friend2.begin(), friend2.end(), friend3[j]);

				if (iter1 == friend1.end() && iter2 == friend2.end())
					f3unique.push_back(friend3[j]);
			}

			if (j > 0) {
				if (friend3[j] != friend3[j - 1]) {
					auto iter1 = find(friend1.begin(), friend1.end(), 
						friend3[j]);
					auto iter2 = find(friend2.begin(), friend2.end(), 
						friend3[j]);

					if (iter1 == friend1.end() && iter2 == friend2.end())
						f3unique.push_back(friend3[j]);
				}
			}
		}

		//	Print the results
		cout << "Case #" << i + 1 << ":\n";
		printWinner(f1unique, f2unique, f3unique);

		//	Reset vectors that hold the unique problems solved
		f1unique.resize(0);
		f2unique.resize(0);
		f3unique.resize(0);
	}

	return 0;
}

//*************************************************************************** //
//							readIn()
//							Input: vector<int> &
//	This function reads integer values into the vector for each friend.
//
//*************************************************************************** //
void readIn(vector<int> &friendX)
{
	int size; // Used to control the resize

	cin >> size;
	friendX.resize(size);

	//	Read in the data
	for (int i = 0; i < size; i++)
		cin >> friendX[i];
}


//*************************************************************************** //
//							sortVector()
//							Input: vector<int> &
//							Complexity: O(N log(N)) in C++ or newer
//	This function sorts a vector of integers in ascending order.
//
//*************************************************************************** //
void sortVector(vector<int> &friendX)
{ 
	sort(friendX.begin(), friendX.end()); 
}


//*************************************************************************** //
//							printWinner()
//							Input: vector<int> &
//	This function compares the size of each answer vector. If there is a tie,
//	all vectors equal to the size held in the temp variable will be printed.	
//
//*************************************************************************** //
void printWinner(vector<int> &f1unique, vector<int> &f2unique, 
	vector<int> &f3unique)
{
	int temp = 0;

	//	Compare the sizes of the answer vectors and print the winner. If there
	//	is a tie, print each friend that tied.
	//	Do the comparison
	if (f1unique.size() > temp)
		temp = f1unique.size();
	if (f2unique.size() > temp)
		temp = f2unique.size();
	if (f3unique.size() > temp)
		temp = f3unique.size();

	if (f1unique.size() == temp) {
		cout << "1 ";
		if (f1unique.size() > 0)
		{
			cout << f1unique.size() << " ";
			for (int j = 0; j < f1unique.size(); j++)
			{
				if (j != f1unique.size() - 1)
					cout << f1unique[j] << " ";
				else
					cout << f1unique[j] << '\n';
			}
		}
		else
			cout << "0\n";
	}
	
	if (f2unique.size() == temp) {
		cout << "2 ";
		if (f2unique.size() > 0)
		{
			cout << f2unique.size() << " ";
			for (int j = 0; j < f2unique.size(); j++)
			{
				if (j != f2unique.size() - 1)
					cout << f2unique[j] << " ";
				else
					cout << f2unique[j] << '\n';
			}
		}
		else
			cout << "0\n";
	}

	if (f3unique.size() == temp) {
		cout << "3 ";
		if (f3unique.size() > 0)
		{
			cout << f3unique.size() << " ";
			for (int j = 0; j < f3unique.size(); j++)
			{
				if (j != f3unique.size() - 1)
					cout << f3unique[j] << " ";
				else
					cout << f3unique[j] << '\n';
			}
		}
		else
			cout << "0\n";
	}
}