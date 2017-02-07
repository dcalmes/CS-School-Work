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

#ifndef MANAGER_H
#define MANAGER_H

class Manager : public Employee	//	Using Employee class
{
private:
	bool salaried;
public:
	//	Constructors
	Manager() { salaried = false; }
	Manager(string, double, bool);

	//	Accessor
	bool getSalaried() { return salaried; }


	double Pay(double) const;
};


#endif