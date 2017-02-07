//////////////////////////////////////////////////////////////////////////////
// Program:             Lab 8
// Purpose:             This Program uses classes and inheritance to display
//						data about Dogs and ShowDogs
// Author:              Douglas Calmes
// Class:               CS 2020-3
// Semester:			Spring 2016
//////////////////////////////////////////////////////////////////////////////

#include "lab8dog.h"
#include "lab8show.h"
#include <iomanip>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////////////////
// Function:    displayDog
// Description: This is function displays the Dog name, color, and weight
// Programmer:  Douglas Calmes
// Class:       CS 2020, Spring 2016
// Parameters:  None
// Returns:     None
//////////////////////////////////////////////////////////////////////////////
void Dog::displayDog()
{
	cout << left << setw(15) << "Dog's name: " << name << endl;
	cout << setw(15) << "Dog's color: " << color << endl;
	cout << setw(15) << "Dog's weight: " << setprecision(2) << weight << endl;
	cout << fixed;
}
