/*
Authors:	Douglas Calmes & Wiebe Vossen
Filename:	VossenW_CalmesD_Lab8.cpp
Class:		CS2010 MoWe 6.00pm-7.15pm
*/

#include <iostream>
#include <string>

using namespace std;

//Prototypes
int calcMAP(int,int);
string checkMAP(int, string);
string checkRisk(int, string);

int main()
{
	int systolic; //integer for systolic pressure
	int diastolic; //integer for diastolic pressure
	int MAP=0; //integer for mean arterial pressure
	string inter_message; //string for interpretation message
	string risk_message; //string for risk indicator message

	//Ask user for systolic and diastolic pressures
	cout << "Please enter systolic pressure: ";
	cin >> systolic;
	cout << "Please enter diastolic pressure: ";
	cin >> diastolic;

	//Call calcMAP
	MAP=calcMAP(systolic, diastolic);
	cout << "MAP: " << MAP << endl; //display results

	//Call checkMAP
	inter_message=checkMAP(MAP,inter_message);
	cout << "Interpretation message: " << inter_message << endl; //display results

	//Call checkRisk
	risk_message=checkRisk(MAP, risk_message);
	cout << "Risk indicator message: " << risk_message << endl; //display results

	system("pause");
	return 0;
}

//************************************************************************
//Calculate the value of MAP and return the value to the main function.  *
//************************************************************************

int calcMAP(int systolic, int diastolic)
{
	int MAP;
	MAP = diastolic + ((systolic - diastolic) / 3);
	return MAP;
}

//************************************************************************
//Determine the interpretation message based on the value of MAP the     *
//value of MAP and return the value to the main function.                *
//************************************************************************
string checkMAP(int MAP, string inter_message)
{
	if (MAP < 70)
		inter_message = "Hypotension";
	else if (MAP < 100)
		inter_message = "Normal";
	else if (MAP < 120)
		inter_message = "Stage 1 hypertension";
	else if (MAP < 135)
		inter_message = "Stage 2 hypertension";
	else
		inter_message = "Stage 3 hypertension";
	return inter_message;
}

//************************************************************************
//Determine the risk indicator message based on the value of MAP the     *
//value of MAP and return the value to the main function.                *
//************************************************************************
string checkRisk(int MAP, string risk_message)
{
	if (MAP < 70)
		risk_message = "Moderate";
	else if (MAP < 110)
		risk_message = "Low";
	else
		risk_message = "High";
	return risk_message;
}