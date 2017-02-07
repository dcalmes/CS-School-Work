/*-------------------------------------------------
Authors: Wiebe Vossen & Douglas Calmes
Purpose: Calculating calories on a treadmill
Input: minutes
Processing: calculating calories
Output: number of calories
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double const CALORIES_MINUTE = 3.9; //constant for calories per minute
	int minutes; //total minutes entered by user
	double calories; //total calculated calories
	int num; //loop control variable
	int inc_minutes=0; //incremented minutes in the while loop

	cout << setprecision(1)<<fixed;

	//Ask user to enter total minutes on treadmill
	cout << "How many minutes do you want to be on the treadmill? ";
	cin >> minutes;
	cout << endl;

	minutes = minutes - (minutes % 5); //Round the total minutes to a number that is dividable by 5

	
	cout << "Calories Burned on Treadmill" << endl
		<< "Minutes \t Calories Burned" << endl;

	while (num < minutes) //While loop, if num < minutes =true
	{
		calories += 5 * CALORIES_MINUTE;//calculate calories per 5 minutes
		inc_minutes += 5; //incremented minutes
		cout << inc_minutes << "\t\t\t" << calories<<endl; //output of minutes and calories
		num += 5; //increment for the whileloop control variable
	}
	system("pause");
	return 0;
}