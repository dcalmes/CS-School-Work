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
// Function:    ShowDog
// Description: This function calls in the Dog overloaded constructor to
//				set the name, color, and weight of the ShowDog.  It then
//				sets the number of contests entered and won by the ShowDog.
// Programmer:  Douglas Calmes
// Class:       CS 2020, Spring 2016
// Parameters:  None
// Returns:     None
//////////////////////////////////////////////////////////////////////////////

ShowDog::ShowDog(string name, string color, double weight, int numContest, int contestWon) :Dog(name, color, weight)
{

	this->numContest = numContest;
	this->contestWon = contestWon;
}

//////////////////////////////////////////////////////////////////////////////
// Function:    displayDog
// Description: This is function calls in the Dog::displayDog function to 
//				display the name, color, and weight.  It then displays the
//				ShowDog number of contests entered and won
// Programmer:  Douglas Calmes
// Class:       CS 2020, Spring 2016
// Parameters:  None
// Returns:     None
//////////////////////////////////////////////////////////////////////////////

void ShowDog::displayDog()
{
	Dog::displayDog();
	cout << name << " was entered in " << numContest << " contests," << endl;
	cout << name << " won " << contestWon << " of the contests." << endl;
}