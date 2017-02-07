/////////////////////////////////////////////////////////////////////////
//	Program			5
//	Description:	This program will have a user input a temperature.
//					It will take this temperature and print out if
//						certain substances will freeze or boil at
//						the temperature that was input.
//	Programmer:		Douglas G Calmes
//	Class:			CS 2020, Spring 2016
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "prog5.h"

using namespace std;

int main()
{
	Temperature Temp;
	int userTemperature = 0;

	//	Header for the entire program
	cout << "This program will tell you what substances freeze" << endl;
	cout << "or boil at a particular temperature." << endl << endl;

	//	User inputs the temperature
	cout << "Please enter a temperature: ";
	cin >> userTemperature;

	//	Call the setTemp function in order to set the userTemperature
	Temp.setTemp(userTemperature);
	cout << "=======================================================================" << endl;

	//	Header for the freezing substances.  Also, call the functions for each
	//		substance to see if it will freeze.  If so, add it to the list.
	cout << "Substances that freeze at\t" << Temp.getTemp() << ":\t";

	if (Temp.getTemp() <= -362)
	{
		Temp.oxygenFreezes();
	}
	if (Temp.getTemp() <= -173)
	{
		Temp.ethylFreezes();
	}
	if (Temp.getTemp() <= 32)
	{
		Temp.waterFreezes();
	}
	if (Temp.getTemp() <= -346)
	{
		Temp.nitrogenFreezes();
	}

	//	Header for the boiling substances.  Also, call the functions for each
	//		substance to see if it will boil.  If so, add it to the list.
	cout << endl << "Substances that boil at\t \t" << Temp.getTemp() << ":\t";

	if (Temp.getTemp() >= -300)
	{
		Temp.oxygenBoils();
	}
	if (Temp.getTemp() >= 173)
	{
		Temp.ethylBoils();
	}
	if (Temp.getTemp() >= 212)
	{
		Temp.waterBoils();
	}
	if (Temp.getTemp() >= -320)
	{
		Temp.nitrogenBoils();
	}
	cout << endl;

	system("Pause");
	return 0;
}