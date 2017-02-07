//////////////////////////////////////////////////////////////////////////////
// Program:		Lab 7
// Purpose:		This labs purpose is to tell time, add time, and alter time
// Author:		Douglas Calmes
// Class:		CS 2020-3
// Semester: 	Spring 2016
//////////////////////////////////////////////////////////////////////////////

#include "lab7.h"

//////////////////////////////////////////////////////////////////////////////
// Function:	addOneMinute
// Description: Adds one minute to the time
// Programmer:	Douglas Calmes
// Class:		CS 2020, Spring 2016
// Parameters:	None
// Returns:		None
//////////////////////////////////////////////////////////////////////////////

void Time::addOneMinute()
{
	minute++;
	if (minute == 60)
	{
		hour++;
		minute = 0;
		if (hour == 24)
		{
			hour = 0;
		}
	}

}

//////////////////////////////////////////////////////////////////////////////
// Function:	operator+
// Description: Adds two time objects together
// Programmer:	Douglas Calmes
// Class:		CS 2020, Spring 2016
// Parameters:	ExtraTime-	Time added
// Returns:		Temp-		New Time
//////////////////////////////////////////////////////////////////////////////

Time Time::operator+ (const Time & ExtraTime) const
{
	Time Temp;
	Temp.hour = hour + ExtraTime.hour;
	Temp.minute = minute + ExtraTime.minute;
	return Temp;
}

//////////////////////////////////////////////////////////////////////////////
// Function:	operator==
// Description: Check to see if the times are equal
// Programmer:	Douglas Calmes
// Class:		CS 2020, Spring 2016
// Parameters:	ExtraTime-	Time added
// Returns:		true-		if bool is true
//				false-		if bool is false
//////////////////////////////////////////////////////////////////////////////

bool Time::operator==(const Time & ExtraTime) const
{
	if (hour == ExtraTime.hour && minute == ExtraTime.minute)
	{
		return true;
	}
	else return false;
}

//////////////////////////////////////////////////////////////////////////////
// Function:	display
// Description: Display the time for each Time variable
// Programmer:	Douglas Calmes
// Class:		CS 2020, Spring 2016
// Parameters:	None
// Returns:		None
//////////////////////////////////////////////////////////////////////////////

void Time::display()
{
	if (hour < 10 && minute < 10)
	{
		std::cout << "0" << hour << ":" << "0" << minute << std::endl;
	}
	else if (hour >= 10 && minute < 10)
	{
		std::cout << hour << ":" << "0" << minute << std::endl;
	}
	else if (hour < 10 && minute >= 10)
	{
		std::cout << "0" << hour << ":" << minute << std::endl;
	}
	else
	{
		std::cout << hour << ":" << minute << std::endl;
	}
}

//////////////////////////////////////////////////////////////////////////////
// Function:	setTime
// Description: Set the Time, check to see if they are within legal limits!
// Programmer:	Douglas Calmes
// Class:		CS 2020, Spring 2016
// Parameters:	hour-	the number of hours
//				minute-	the number of minutes
// Returns:		None
//////////////////////////////////////////////////////////////////////////////

void Time::setTime(int hour, int minute)
{
	if (hour <= 23 && hour >= 0 && minute <= 59 && minute >= 0)
	{
		this->hour = hour;
		this->minute = minute;
	}
	else
	{
		this->minute = 0;
		this->hour = 0;
	}
}

//////////////////////////////////////////////////////////////////////////////
// Function:	Time
// Description: This is the overloaded constructor for Time
// Programmer:	Douglas Calmes
// Class:		CS 2020, Spring 2016
// Parameters:	hour-	the number of hours
//				minute-	the number of minutes
// Returns:		None
//////////////////////////////////////////////////////////////////////////////

Time::Time(int hour, int minute)
{
	if (hour <= 23 && hour >= 0 && minute <= 59 && minute >= 0)
	{
		this->hour = hour;
		this->minute = minute;
	}
	else
	{
		this->minute = 0;
		this->hour = 0;
	}
}