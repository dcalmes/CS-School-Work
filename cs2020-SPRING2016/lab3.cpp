///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Program:     Lab 3
// Purpose:     This programs purpose is to show gold, silver, and bronze memberships and their statistics overall.
// Input:		The input file of this program is lab3.txt.  User inputs the numbers they want to see.
// Processing:  Different functions to perform:
//						void menu();
//								-This function take the data and shows the data of what type of shares they want to see.
//									It shows each member of each membership along side the amount of shares they have.
//									Finally, it shows the member with the most shares, and how many they have.
//						void value();
//								-This function takes the input data and prints out the amount of shares each membership
//									has and also the value of all the stocks based on their individual value.
// Output:		This program outputs the shareholders for either gold, silver, and bronze memberships.  It also outputs
//				the quantity of each shares along side their value.
// Programmer:  Douglas Calmes
// Class:       CS 2020 Spring 2016
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream> 
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// Shareholder Structure
struct Shareholder
{
	string name;
	string shareType;
	double numberShares;
};

// Prototypes
void menu(Shareholder[], int, string);
void value(Shareholder[], int);

// Max elements
const int MAXSTUD = 50;


int main()
{
	Shareholder ClientList[MAXSTUD];

	string choice;
	int numClients = 0;
	ifstream inputFile;
	string Share;

//	This is where we open the lab3.txt and read its contents, putting them into an array.

	inputFile.open("lab3.txt");

	if (inputFile)
	{
		while (!inputFile.eof())
		{
			getline(inputFile, ClientList[numClients].name);
			inputFile >> ClientList[numClients].shareType;
			inputFile >> ClientList[numClients].numberShares;
			inputFile.ignore();
			numClients++;
		}
		inputFile.close();
	}
	else
	{
		cout << "ERROR: File not found" << endl;
	}

//	Do-While loop until the user inputs "Done"

		do
		{	
			cout << "Share type [Gold : Silver : Bronze : Done]: ";
			cin >> Share;

			if (Share == "Gold")
			{
				menu(ClientList, numClients, Share);
			}
			if (Share == "Bronze")
			{
				menu(ClientList, numClients, Share);
			}
			if (Share == "Silver" )
			{
				menu(ClientList, numClients, Share);
			}
			if (Share != "Gold" && Share != "Silver" && Share != "Bronze" && Share != "Done")
			{
				cout << "Invalid tyle!" << endl;
			}
		} while (Share != "Done");

		value(ClientList, numClients);

	system("Pause");
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
// Lab 3                                                                                                                                                                                                                                            /      
// Programmer:		Douglas Calmes                                                                                   
// Class:           CS 2020, Spring 2016                                     
//                                                                           
// Function:        menu                                                   
// Description:     This function take the data and prints out the data.
//						It takes the share that the user inputs to see the
//						members and the shares they hold.  Also printing out
//						the member with the most shares and their count.
// Parameters:		ClientList[]- The array for the Shareholder structure
//					numClients-	  The number of clients in the array.
//					Share-		  The share that the user inputs in the main
// Returns:			Nothing              
//////////////////////////////////////////////////////////////////////////////

void menu(Shareholder ClientList[], int numClients, string Share)
{
	int i = 0;
	int high = 0;
	string highClient;

	cout << "============================================================" << endl;
	cout << right << setw(20) << Share << " Clients" << endl;
	cout << "============================================================" << endl;

//	Finds all the members of the share that is wanted and prints out the members and their amount of shares

	while (i < numClients)
	{
		if (ClientList[i].shareType == Share)
		{
			cout << left << setw(30) << ClientList[i].name << setw(20) << ClientList[i].numberShares << endl;

			if (ClientList[i].numberShares > high)
			{
				high = ClientList[i].numberShares;
				highClient = ClientList[i].name;
			}
		}
		i++;
	}

	cout << ">>>> " << highClient << " has the most shares with " << high << endl << endl;
}

//////////////////////////////////////////////////////////////////////////////
// Lab 3                                                                                                                                                                                                                                            /      
// Programmer:		Douglas Calmes                                                                                   
// Class:           CS 2020, Spring 2016                                     
//                                                                           
// Function:        value                                                   
// Description:     This function prints out the quantity and value of
//						each shareholder type.  It calculates the quantity
//						and value based on the share cost.
// Parameters:		ClientList[]- The array for the Shareholder structure
//					numClients-	  The number of clients in the array.
// Returns:			Nothing              
//////////////////////////////////////////////////////////////////////////////

void value(Shareholder ClientList[], int numClients)
{
	int i = 0;
	double goldQty, silverQty, bronzeQty;
	double goldValue, silverValue, bronzeValue;
	double goldShare = 9.65, silverShare = 4.75, bronzeShare = 1.85;

//	While loop that takes the total shares of each membership and calculates the
//	the total quantity and value of each type of share

	while (i < numClients)
	{
		if (ClientList[i].shareType == "Gold")
		{
			goldQty += ClientList[i].numberShares;
			goldValue = goldQty * goldShare;
		}
		if (ClientList[i].shareType == "Silver")
		{
			silverQty += ClientList[i].numberShares;
			silverValue = silverQty * silverShare;
		}
		if (ClientList[i].shareType == "Bronze")
		{
			bronzeQty += ClientList[i].numberShares;
			bronzeValue = bronzeQty * bronzeShare;
		}
		i++;
	}

	cout << "=============================================" << endl;
	cout << left << setw(20) << "Share Type" << setw(20) << "Quantity" << setw(10) << "Value" << endl;
	cout << "=============================================" << endl;
	cout << left << setw(20) << "Gold" << setw(20) << goldQty << setw(10) << goldValue << endl;
	cout << left << setw(20) << "Silver" << setw(20) << silverQty << setw(10) << silverValue << endl;
	cout << left << setw(20) << "Bronze" << setw(20) << bronzeQty << setw(10) << bronzeValue << endl;

}

