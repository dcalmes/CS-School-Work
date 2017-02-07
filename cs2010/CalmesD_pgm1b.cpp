//--------------------------------------------------------------------------
//						Program 1b: Hot Chocolate
// Your name: Douglas Calmes
// Project name: CalmesD_pgm1b					Due: 11:59pm 09/04/15
//
// Purpose:		This program finds the average number of cups of hot
//				chocolate sold over a two month period.
// Input:		The user is asked to enter the number of cups of
//				hot chocolate sold for each of the two months.
// Processing:	Add the number of cups sold for the two months.
//				Divide the results by the number of months to find
//					average cups sold per month.
//				Display the average number of cups sold.
// Output:		Displays the average number of cups of hot chocolate sold
//				per month on the screen.
//--------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
	int janCups, febCups, avgCups;
	int months = 0;

	// Introduction
	cout << "Welcome hot chocolate fans!  This program calculates";
	cout << " the average number of cups of hot chocolate sold";
	cout << " last year in January and February." << endl << endl;

	// Get the number of cups of hot chocolate sold for each month
	cout << "Enter the number of cups of hot chocolate sold in January: ";
	cin >> janCups;
	months = months + 1;

	cout << "Enter the number of cups of hot chocolate sold in February: ";
	cin >> febCups;
	months = months + 1;

	// Calculate average number of cups sold
	avgCups = (janCups + febCups) / months;

	// Display average number of cups sold
	cout << endl << "The average number of cups sold was:  "
		 << avgCups << endl << endl;

	cout << endl;
	system("pause");
	return 0;
}