/*-------------------------------------------------------
File name	:	VossenW_CalmesD_lab5.cpp
Description	:	Lab 5 - Determine your text message bill.
Authors		:	Wiebe Vossen and Douglas Calmes
Date		:	09/23/2015
---------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	//Declaring all the values
	char checkPackage = 'Y'; //character to check if the loop has to be runned again
	string packageType; //package type
	char A, B, C; //package type
	int nTexts; //amount of texts in the package
	double bill; //bill without taxes and fee
	double total_bill;//total bill incl. taxes and fees.
	const double tax = 1.07; //states sales tax
	const double fee = 1.99; //fixed monthly "connection fee"


	//while loop
	while (checkPackage == 'Y')
	{
		//ask users input
		cout << "What package did you purchase (A, B, C)? ";
		cin >> packageType;
		cout << "How many messages did you send this month? ";
		cin >> nTexts;

		//calculate bill without taxes and fees
		if (packageType == "A")
		{
			bill = 9.95;
			if (nTexts > 100) //determine if the text limit was exceeded, if so add the additional charge
				bill = 9.95 + (nTexts - 100)*0.15;
		}
		else if (packageType == "B")
		{
			bill = 14.95;
			if (nTexts > 200)//determine if the text limit was exceeded, if so add the additional charge
				bill = 14.95 + (nTexts - 200)*0.10;
		}
		else if (packageType == "C")
			bill = 19.95;

		else
		{
			//Show error message if an incorrect value has been displayed
			cout << "Invalid package.\n"
				<< "Do you want to check another package (Y,N)? ";
			cin >> checkPackage;
		}
		//Calculate total bill including tax and fee
		total_bill = bill*tax + fee;

		//Display packagetype and bill
		cout << setprecision(2) << fixed; //set significant digits
		cout << "Your bill is: $" << total_bill<<endl; //display total bill
		cout << "Do you want to check another package (Y,N)? "; //ask if they want to check another package
		cin >> checkPackage;
		cout << endl<<endl; // add a blank line
	}
	return 0;

}