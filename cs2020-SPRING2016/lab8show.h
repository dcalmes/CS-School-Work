//////////////////////////////////////////////////////////////////////////////
// Program:             Lab 8
// Purpose:             This Program uses classes and inheritance to display
//						data about Dogs and ShowDogs
// Author:              Douglas Calmes
// Class:               CS 2020-3
// Semester:			Spring 2016
//////////////////////////////////////////////////////////////////////////////

#ifndef SHOWDOG_H
#define SHOWDOG_H
#include "lab8dog.h"
#include <string>
#include <iostream>

class ShowDog : public Dog	//This class has access to Dog class
{
private:
	int numContest;
	int contestWon;
public:
	//	Constructors
	ShowDog() { numContest = 0; contestWon = 0; }	// Defult constructor
	ShowDog(string, string, double, int, int);		// Overloaded constructor

	//	Accessor
	void displayDog();
};

#endif
