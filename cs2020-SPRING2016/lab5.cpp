// Lab 5
// Description: 
// Programmer:	Douglas G Calmes
// Class:		CS 2020, Spring 2016

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//	Structures

struct Gift
{
	string desc;
	Gift* pNext;
};
struct Nice
{
	string name;
	Nice* pNext;
	Gift* pGiftHead;
};

//Prototypes

void createList(Nice* &);			//	Create the Nice list
void printNiceList(Nice*);			//	Display the nice list
void printGifts(Nice*, string);
void insertNice(Nice* &, Nice*);
void appendGift(Gift* &, Gift*);
void DeleteList(Nice*, Gift*);
int Menu();							//	Menu function

int main()
{
	int choice = 0;
	string gifts;
	Nice* pNice = nullptr;
	Gift* pGift = nullptr;
	string childName;

	createList(pNice);

	// Do-While look to continually allow the user to execute the menu commands until finished.
	// This loop continues until the user inputs 3 to quit the program.

	do
	{
		choice = Menu();

		if (choice == 1)
		{
			printNiceList(pNice);
		}

		if (choice == 2)
		{
			cout << "Gift for whom? ";
			cin.ignore();
			cin >> childName;

			printGifts(pNice, childName);
		}
		if (choice == 3)
		{
			DeleteList(pNice, pGift);
		}
		if (choice != 1 && choice != 2 && choice != 3)
		{
			cout << "ERROR: invalid choice.  Please re-enter" << endl;
		}
	} while (choice != 3);




	return 0;
	system("Pause");
}

// Function:	createList
// Description: The purpose of this function is to read in the data file and create
//				a linked lists of the children (NOT including their gifts!).
// Programmer:	Douglas G Calmes
// Class:		CS 2020, Spring 2016
// Parameters:	pNice-	pointer to Nice Structure
// Returns:		This function is void.

void createList(Nice* & pNice)
{
	ifstream infile;

	infile.open("lab5.txt");

	Nice* pNew;
	Nice* pTemp;

	if (infile)
	{
		while (!infile.eof())
		{
			pNew = new Nice;
			pNew->pNext = nullptr;

			string s, ss, gift;
			int i, j;

			getline(infile, s);
			i = s.find(" ");
			j = s.find(" ", i + 1);
			ss = s.substr(0, i);
			pNew->name = ss;

			while (j != -1)
			{
				Gift* gTemp = new Gift;
				gTemp->pNext = nullptr;
				gift = s.substr(i + 1, j - i - 1);
				gTemp->desc = gift;



				i = j;
				j = s.find(" ", i + 1);

			}

			if (pNice == nullptr)
				pNice = pNew;
			else
			{
				pTemp = pNice;

				while (pTemp->pNext != nullptr)
				{
					pTemp = pTemp->pNext;
				}
				pTemp->pNext = pNew;
			}
		}
		infile.close();
	}
	else
		cout << "Error: File was not found!";
}

// Function:	appendGift
// Description: The purpose of this function is to append the gifts to a gift linked list.			
// Programmer:	Douglas G Calmes
// Class:		CS 2020, Spring 2016
// Parameters:	pGift-	Head pointer to Gift Structure
//				gTemp-	Temporary pointer to Gift Structure
// Returns:		This function is void.

void appendGift(Gift* & pGift, Gift* gTemp)
{
	
}

// Function:	insertNice
// Description: The purpose of this function is to insert into the nice list.
// Programmer:	Douglas G Calmes
// Class:		CS 2020, Spring 2016
// Parameters:	pNice-	Head pointer for Nice Structure
//				pTemp-	Temporary pointer for Nice Structure
// Returns:		This function is void.

void insertNice(Nice* & pNice, Nice* pTemp)
{

}

// Function:	printGifts
// Description: The purpose of this function is to ask the user to input a child.
//				This fuction will the search for the child and print out his/her gift list.
// Programmer:	Douglas G Calmes
// Class:		CS 2020, Spring 2016
// Parameters:	pNice-	Head pointer to Nice Structure
//				childName-	Name of child they want the gifts to be output
// Returns:		This function is void.

void printGifts(Nice* pNice, string childName)
{
	Nice* pTemp = pNice;

	while (pTemp->pNext != nullptr && pTemp->name != childName)
	{
		pTemp = pTemp->pNext;
	}

	if (pTemp->pNext == nullptr)
	{
		cout << childName << " not on the list" << endl;
	}
	
	if (pTemp->name == childName)
	{
		cout << childName << pNice->pGiftHead << endl;
	}

}


// Function:	printNiceList
// Description: The purpose of this function is to print out the list of children on the nice list.
// Programmer:	Douglas G Calmes
// Class:		CS 2020, Spring 2016
// Parameters:	pNice-	Head pointer to the Nice Structure
// Returns:		This function is void.

void printNiceList(Nice* pNice)
{
	Nice* pTemp = pNice;
	int count = 1;

	while (pTemp != nullptr)
	{
		cout << right << setw(3) << count << left << ": " << pTemp->name << endl;

		count++;
		pTemp = pTemp->pNext;
	}
}

// Function:	Menu
// Description: This program is used to show the user the options to choose from and asks them to input their choice
// Programmer:	Douglas G Calmes
// Class:		CS 2020, Spring 2016
// Parameters:	
// Returns:		option- this allows the program to use the option that the user has chosen inside the loop

int Menu()
{
	int option;

	cout << "---------------" << endl;
	cout << "1.Print Nice" << endl;
	cout << "2.Print Gifts" << endl;
	cout << "3.Quit" << endl;
	cout << "Choice ";
	cin >> option;
	cout << "---------------" << endl;

	return option;
}



void DeleteList(Nice* pNice, Gift* pGift)
{
	Nice* pTemp;
	Gift* gTemp;

	pTemp = pNice;
	gTemp = pGift;

	while (pTemp != nullptr && gTemp != nullptr)
	{
		// save pointer to next node in the list 
		pNice = pTemp->pNext;
		pGift = gTemp->pNext;

		delete pTemp;
		delete gTemp;

		// start traversing at next node 
		pTemp = pNice;
		gTemp = pGift;
	}
}
