//**************************************************************************
// Program: Charge Account Numbers
//
// Purpose: This program checks whether a number entered by the user is a
//   		valid charge account number.
// 
// Input: 	The user is asked to enter a three-digit number to be checked.
//
// Processing:  
//          The main function uses an initialization list to initialize
//   		an array with charge account numbers. Then it calls a function
//		    to display the list. The user is asked to enter a charge
//		    number. The main function calls another function to check the
//		    validity of this number and then it displays a message 
//		    reporting the results. 
//
// Output: 	The program displays the list of account numbers and a message
//   		indicating whether the number entered by the user is valid 
//		    or not.
//
// Author: 	Douglas Calmes
// Class:	CS 2020
// Semester:Spring/Fall 2015
//**************************************************************************
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void displayAcctNos(int[], int);
int searchList(int[], int, int);
void BSort(int[], int);

int main()
{
	const int ARY_SIZE = 9;

	// Array of account numbers
	int accounts[ARY_SIZE] =
	{ 565,  452,  789,
		877,  845,  130,
		808,  456,  555 };

	int accountNumber;
	int position;
	//********************************************************
	// Bubble sort into ascending order
	//********************************************************
	BSort(accounts, ARY_SIZE);
	//********************************************************
	// Display account numbers
	//********************************************************
	displayAcctNos(accounts, ARY_SIZE);

	//********************************************************
	// Get an account number from the user.
	//********************************************************
	cout << endl << "Please enter a 3-digit account number:  ";
	cin >> accountNumber;

	while (accountNumber != -1)
	{
		//********************************************************
		// Search the array for the number and indicate whether it
		// is valid or not.
		//********************************************************
		position = searchList(accounts, accountNumber, ARY_SIZE);
		cout << endl;
		if (position == -1)
			cout << accountNumber << " is an invalid charge account number."
			<< endl;
		else
			cout << accountNumber << " is a valid charge account number."
			<< endl;

		// Give user a chance to enter -1 and end the lookup
		//
		cout << endl << "Please enter a 3-digit account number:  ";
		cin >> accountNumber;
	}

	cout << endl;
	return 0;
}

//*********************************************************************
// Function:	displayAcctNos
// Description:	Displays the list of charge numbers. 
// Returns:	void
//*********************************************************************
void displayAcctNos(int acctNos[], int ARY_SIZE)
{
	cout << endl << "Charge Account Numbers" << endl;
	cout << "Element  Charge Number " << endl;
	for (int k = 0; k < ARY_SIZE; k++)
		cout << setw(4) << k << setw(14) << acctNos[k] << endl;
}


//*********************************************************************
// Function:	searchList                             
// Description: This function searches the array of charge numbers for the
//		number passed into value using the linear search algorithm. 
//		If the number is found the function returns the position of
//		the value in the array.
// Return:	If the number is not found it returns -1.
//*********************************************************************
int searchList(int accounts[], int value, int ARY_SIZE)
{
	int first = 0;       // Used as subscript to search array
	int position = -1;   // To record position of search value
	bool found = false;  // Flag to indicate if value found
	int last = ARY_SIZE - 1;
	int  middle;

	// Step through the array as long as the value is not found
	while (first <= last && !found)
	{
		middle = (first + last) / 2;
	if (accounts[middle] == value)
		{
			found = true;           // The value is found
			position = middle;       // Record the value's position
		}
		else if (accounts[middle] > value)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return position;
}

////////////////////////////////////////////////
//Bubble sort:
////////////////////////////////////////////////

void BSort(int accounts[], int ARY_SIZE)
{
	bool sorted = false;
	int num = ARY_SIZE - 1;
	int tempValue;
	do
	{
		sorted = true;
		for (int i = 0; i < num; i++)
		{
			if (accounts[i] > accounts[i + 1])
			{
				tempValue = accounts[i];
				accounts[i] = accounts[i + 1];
				accounts[i + 1] = tempValue;
				sorted = false;
			}
		}
	} while (sorted == false);
}
