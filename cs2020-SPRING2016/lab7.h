//////////////////////////////////////////////////////////////////////////////
// Program:		Lab 7
// Purpose:		This labs purpose is to tell time, add time, and alter time
// Author:		Douglas Calmes
// Class:		CS 2020-3
// Semester: 	Spring 2016
//////////////////////////////////////////////////////////////////////////////

#ifndef TIME_H
#define TIME_H
#include <iostream>

class Time
{
private:
	int hour;
	int minute;

public:
	//	Constructors
	Time() { hour = 0; minute = 0; }	//	Default constructor
	Time(int hour, int minute);

	//	Mutators
	void setTime(int hour, int minute);
	void addOneMinute();

	//	Accessors
	int getHour(){ return hour; }		//	Get the hour
	void display();

	//overloaded operators
	Time operator+ (const Time &) const;
	bool operator==(const Time &) const;
};

#endif