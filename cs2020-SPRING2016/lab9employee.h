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
using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
protected:
	string name;
	double payRate;
public:
	//	Constructors
	Employee() { name = ""; payRate = 0; }
	Employee(string name, double payRate) { this->name = name; this->payRate = payRate; }

	//	Accessors
	string getName() { return name; }
	double getPayRate() { return payRate; }


	virtual double Pay(double) const;
};


#endif

