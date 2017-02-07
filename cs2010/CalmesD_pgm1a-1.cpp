//----------------------------------------------------------------------------------
//								Program 1a: Hello
// Your name: Douglas Calmes								
// Project name: CalmesD_pgm1a								Due: 11:59pm 09.04/15
//
// Purpose:		This program displays a hello greeting including the user's name
// Input:		Ask the user to enter his/her first and last name.
//Processing:	Get the user's name.
//				Display a greeting and the user's name.
//Output:		Displays a hello greeting and the user's first and last name
//				in a box of asterisks on the screen.
//----------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string firstName, lastName, major;

	// Get user's name
	cout << "Please enter your first name:  ";
	cin >> firstName;
	cout << "Please enter your last name:   ";
	cin >> lastName;

	// Get user's major
	cout << "Please enter your Major:       ";
	cin >> major;

	// Display hello greeting
	cout << endl;
	cout << "*************************************" << endl;
	cout << "**         Hello                   **" << endl;
	cout << "**         " << firstName << " " << lastName
		 << "             **" << endl;
	cout << "**         " << major << "         **" << endl;
	cout << "*************************************" << endl;

	cout << endl;
	system("pause");
	return 0;
}
