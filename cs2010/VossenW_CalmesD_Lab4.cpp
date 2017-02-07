/*--------------------------------------------------------------
Author:		Douglas Calmes and Wiebe Vossen
Class:		CS2010 MonWed 6.00-7.15pm
Purpose:	Display the correct credit hour fee, credit hours
			and tuition for a student.
Input:		Undergraduate or graduate, total number of credit hours
Process:	Calculate tuition based on student type and credit hours
Display:	Student type, credit hours, fee per credit hour and
			total tuition
----------------------------------------------------------------
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	char U, A, G, I, O;
	string stuType;
	string residentType;
	double creditHourFee;
	double total_tuition;
	double total_credits;
	double adj_credithourFee;

	//Get student type from user
	cout << "Enter your student type - (U)ndergraduate, (G)raduate, (A)udit: ";
	cin >> stuType;

	//Get number of credit hours from user
	cout << "Enter the number of credit hours you are registered for: ";
	cin >> total_credits;
	cout << endl;

	//Get in-state or out-of-state resident status
	cout << "Enter your resident status - (I)n-state or (O)ut-of-state: ";
	cin >> residentType;
	cout << endl;


	//Determine the credit hour fee
	if (stuType == "U")
		creditHourFee = 100;
	else
		if (stuType == "A")
			creditHourFee = 75;
		else
			if(stuType=="G")
				creditHourFee = 150;
			else
			{
				cout << "You typed the wrong letter.";
				return 0;
			}

	//Determine the adjusted credit hour fee
	if (residentType == "O" && stuType == "G")
		adj_credithourFee = 2 * creditHourFee;
	else
		if (residentType == "O"&& stuType == "U")
			adj_credithourFee = 2 * creditHourFee;
		else
			if (residentType == "O"&& stuType == "A")
				adj_credithourFee = 1.5 * creditHourFee;
			else
				adj_credithourFee = creditHourFee;


	//Calculate tuition
	total_tuition = adj_credithourFee*total_credits;

	//Display fee per credit hour and total tuition
	cout << "Your fee per credit hour is $" << adj_credithourFee << ". Your tuition for " << total_credits << " credit hours is $" << total_tuition << ".";

	cout << endl;
	system("pause");
	return 0;


}