//////////////////////////////////////////////////////////////////////////////
// Program:		Lab 7
// Purpose:		This labs purpose is to tell time, add time, and alter time
// Author:		Douglas Calmes
// Class:		CS 2020-3
// Semester: 	Spring 2016
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "lab7.h"
#include <iomanip>

using namespace std;

int main()
{
	Time FreeTime;
	Time WrongTime(25, 45);
	Time BGTime(7, 30);
	int minute;
	int hour;

	//	Display the different times
	cout << setw(20) << "Free time: ";
	FreeTime.display();
	cout << endl;
	cout << setw(20) << "Wrong time: ";
	WrongTime.display();
	cout << endl;
	cout << setw(20) << "BG time: ";
	BGTime.display();
	cout << endl;

	//	Have user enter their free time in HH MM
	cout << "Enter your free time as HH and MM: ";
	cin >> hour >> minute;
	cout << endl;

	//	Set free time and display
	FreeTime.setTime(hour, minute);
	cout << setw(20) << "Free time: ";
	FreeTime.display();
	cout << endl;

	//	Loop to add on to free time
	for (int i = 0; i < 150; i++)
	{
		FreeTime.addOneMinute();
	}

	//	Re display free time
	cout << setw(20) << "Free time: ";
	FreeTime.display();
	cout << endl;

	//	Set and display extra time
	Time ExtraTime(1, 15);
	FreeTime = FreeTime + ExtraTime;
	cout << setw(20) << "Free time: ";
	FreeTime.display();
	cout << endl;

	cout << "Is FreeTime equal to ExtraTime? 1(Yes) 0 (No): " << (FreeTime == ExtraTime) << endl;

	system("pause");
	return 0;

}