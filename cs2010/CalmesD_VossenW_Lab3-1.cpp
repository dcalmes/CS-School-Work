/*--------------------------------------------------------------------------------
Programname: Lab assignement 3
Filename: CalmesD_VossenW_lab3.cpp
Authors: Wiebe Vossen, Douglas Calmes
Purpose: With this program you can calculate the amount of quarters, dimes, nickles and
		pennies when a given amount of change is given.




*/

#include <iostream>
using namespace std;

int main()
{
	int changeTotal, quarter, dime, nickle, penny, dimeMod, nickleMod, quarterMod;

	// Ask user to enter amount of change between 1-99
	cout << "Enter amount of change between 1 and 99 cents: ";
	cin >> changeTotal;

	// Perform calculations on amount of change
	quarter = changeTotal / 25;
	quarterMod = changeTotal % 25;
	dime = quarterMod / 10;
	dimeMod = quarterMod % 10;
	nickle = dimeMod / 5;
	nickleMod = dimeMod % 5;
	penny = nickleMod;

	// Display amount of quarters, dimes, nickles, and pennies
	cout << endl;
	cout << "Amount of quarters: " << quarter << endl;
	cout << "Amount of dimes: " << dime << endl;
	cout << "Amount of nickles: " << nickle << endl;
	cout << "Amount of pennies: " << penny << endl;

	cout << endl;
	system("pause");
	return 0;
}