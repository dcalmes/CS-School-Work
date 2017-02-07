//////////////////////////////////////////////////////////////////////////////
// Program			6
// Description:		This program will define and demonstrate a Money
//						class.  Dollars and cents will be stored separately
//						so that more money amounts can be represented as
//						precisely as possible
// Programmer:		 Douglas G Calmes
// Class:			 CS 2020, Spring 2016
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "prog6.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
// Function:        simplify
// Description:     This function checks for values in cents that are 
//						100 or greater or less than 0, adjusts dollars and 
//						cents as needed so that cents amount is never greater
//						than 99
// Programmer:      Douglas G Calmes
// Class:           CS 2020, Spring 2016
// Parameters:		None
// Returns:			Nothing
//////////////////////////////////////////////////////////////////////////

void Money::simplify()
{
	while (cents > 99)
	{
			dollars++;
			cents = cents - 100;
	}

}

//////////////////////////////////////////////////////////////////////////
// Function:        operator+
// Description:     Adds two Money objects together
// Programmer:      Douglas G Calmes
// Class:           CS 2020, Spring 2016
// Parameters:		addMoney-	The money you woulld like to add
// Returns:			temp-		The sum of addMoney
//////////////////////////////////////////////////////////////////////////

Money Money::operator+(const Money &addMoney) const
{
	Money temp;
	temp.dollars = this->dollars + addMoney.dollars;
	temp.cents = this->cents + addMoney.cents;

	temp.simplify();
	
	return temp;
}

//////////////////////////////////////////////////////////////////////////
// Function:        operator-
// Description:     Subtracts two Money objects
// Programmer:      Douglas G Calmes
// Class:           CS 2020, Spring 2016
// Parameters:		subMoney-	The money you woulld like to subtract
// Returns:			temp-		The sum of addMoney
//////////////////////////////////////////////////////////////////////////

Money Money::operator-(const Money &subMoney) const
{
	Money temp;
	temp.dollars = this->dollars - subMoney.dollars;
	temp.cents = this->cents - subMoney.cents;

	temp.simplify();

	return temp;
}

//////////////////////////////////////////////////////////////////////////
// Function:        operator<<
// Description:     Displays a Money object in the form $dd.cc
// Programmer:      Douglas G Calmes
// Class:           CS 2020, Spring 2016
// Parameters:		osObject-	ostream variable
//					outMoney-	Money object you chose to output
// Returns:			osObject-	ostream variable
//////////////////////////////////////////////////////////////////////////

ostream &operator<<(ostream &osObject, const Money &outMoney)
{
	if (outMoney.cents < 10)
	{
		osObject << "$" << outMoney.dollars << ".0" << outMoney.cents;
	}
	else
	osObject << "$" << outMoney.dollars << "." << outMoney.cents;

	return osObject;
}

//////////////////////////////////////////////////////////////////////////
// Function:        operator>>
// Description:     Input a new dollars and cents
// Programmer:      Douglas G Calmes
// Class:           CS 2020, Spring 2016
// Parameters:		inObject-	istream variable
//					inMoney-	Money object you chose to output
// Returns:			inObject-	istream variable
//////////////////////////////////////////////////////////////////////////

istream & operator>>(istream &isObject, Money &inMoney)
{
	isObject >> inMoney.dollars >> inMoney.cents;

	return isObject;
}