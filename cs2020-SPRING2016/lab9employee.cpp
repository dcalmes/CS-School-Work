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
using namespace std;

//////////////////////////////////////////////////////////////////////////////
// Function:    Pay
// Description: This function determines how much the Manager has earned
//					wither he/she is paid by salary or hourly rates.
// Programmer:  Douglas Calmes
// Class:       CS 2020, Spring 2016
// Parameters:  hoursWorked-	number of hours worked
// Returns:     payRate*hoursWorked	- Salary
//////////////////////////////////////////////////////////////////////////////

double Employee::Pay(double hoursWorked) const
{
	return payRate*hoursWorked;
}