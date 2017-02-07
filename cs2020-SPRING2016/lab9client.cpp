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
#include <fstream>
#include <iomanip>
using namespace std;

//	Prototype
void PrintPay(Employee*, double);

const int SIZE = 25;	//	Max size of array
int main()
{
	//	Name input file and open lab9.txt
	ifstream infile;
	infile.open("lab9.txt");

	//	Creating employee array and naming the variables used from input file
	Employee* employeeList[SIZE];
	int type, i = 0;
	string firstName, lastName;
	double payRate = 0, hoursWorked = 40.00;
	bool salaried;

	//	While loop to read input file and store the data in the respected dynamically
	//		allocated employee types based in "type" variable
	while (!infile.eof())
	{
		infile >> type;

		//	Create new Employee if type is 1
		if (type == 1)
		{
			infile >> firstName;
			infile >> lastName;
			infile >> payRate;

			employeeList[i] = new Employee(firstName + " " + lastName, payRate);

		}
		//	Create new Manager if type is 2
		else if (type == 2)
		{
			infile >> firstName;
			infile >> lastName;
			infile >> payRate;
			infile >> salaried;

			employeeList[i] = new Manager(firstName + " " + lastName, payRate, salaried);

		}
		i++;
	}

	//	Header for employee/manager income output
	cout << left <<setw(20) << "Employee" << setw(10) << "Monthly Income" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	for (int num = 0; num < i; num++)
	{
		PrintPay(employeeList[num], hoursWorked);
	}

	//	Close input file
	infile.close();

	system("Pause");
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
// Function:    PrintPay
// Description: This function prints out the list of the pointer of arrays
// Programmer:  Douglas Calmes
// Class:       CS 2020, Spring 2016
// Parameters:  employeeList-	list of employees
//				hoursWorked-	number of hours employee worked
// Returns:     None
//////////////////////////////////////////////////////////////////////////////

void PrintPay(Employee* employeeList, double hoursWorked)
{
	cout << left << fixed << setprecision(2) << setw(20) << employeeList->getName() << setw(10) << "earned" << "$ " << right << employeeList->Pay(hoursWorked) << endl;
}
