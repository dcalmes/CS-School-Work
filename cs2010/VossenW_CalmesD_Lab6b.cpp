/*-------------------------------------------------------------
Authors: Wiebe Vossen & Douglas Calmes
Purpose: Calculate total points, average per game and total games.
Input: points per game
Processing: calculate total points, average per game and total games.
Output: points per game, total points, average
*/

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int points;
	int total_points;
	int total_games; 
	double average_points;

	cout << "Enter points for first game (-1 to end): ";
	cin >> points;
	while (points !=- 1)
	{
		total_points += points;
		total_games++;
		cout << "Enter points for next game (-1 to end): ";
		cin >> points;
		
		
	}
	average_points = total_points / total_games;
	cout << endl << "Total points scored: " <<total_points << endl;
	cout << "Number of games: " <<total_games << endl;
	cout << "Average points per game: " << average_points << " (Total points scored divided by Number of games)"<<endl;

	system("pause");
	return 0;
}