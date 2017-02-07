//////////////////////////////////////////////////////////////////////////////
// Program:		Lab 9
// Purpose:     The purpose of this program is to create an object oriented
//					program that enables polymorphism, uses inheritance, 
//					encapsulation and virtual functions.  This is used in
//					order to find and display the monthly income for employees
//					and managers besed on salary or hourly pay.
// Author:      Douglas Calmes
// Class:       CS 2020-3
// Semester:    Spring 2016
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "lab9employee.h"
#include "lab9manager.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////////
// Function:    Manager : Employee
// Description: This function calls the Manager overloaded constructor.  It
//					sets salaried variable.  It gets name and payRate from
//					Employee();
// Programmer:  Douglas Calmes
// Class:       CS 2020, Spring 2016
// Parameters:  name-		name of the employee
//				payRate-	rate at which employee is paid
//				salaried-	determines if employee is salaried or hourly paid
// Returns:     None
//////////////////////////////////////////////////////////////////////////////

Manager::Manager(string name, double payRate, bool salaried) : Employee(name, payRate)
{
	this->salaried = salaried;
}

//////////////////////////////////////////////////////////////////////////////
// Function:    Pay
// Description: This function determines how much the Manager has earned
//					wither he/she is paid by salary or hourly rates.
// Programmer:  Douglas Calmes
// Class:       CS 2020, Spring 2016
// Parameters:  hoursWorked-	number of hours worked
// Returns:     payRate if they are on salary
//				payRate*hoursWorked if they are on hourly pay
//////////////////////////////////////////////////////////////////////////////

double Manager::Pay(double hoursWorked) const
{
	if (salaried == true)
	{
		return payRate;
	}
	else 
		return payRate * hoursWorked;
}