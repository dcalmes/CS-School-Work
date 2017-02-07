// File Name	:	Prog4_calmes.cpp
// Discription	:	This program reads in an input file and uses the banker's 
//			algorithm to determine if the system is in a safe state.  It
//			also allows user input to end the program and/or change/add
//			a process to the system.
// Author	:	Douglas G Calmes
// Date		:	11/02/2016

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void	printState(int, int, int[], int[], int[], int[], int[]);
string	cancelCheck(string);

const int MAX_SIZE = 100;
int main()
{
	//	List of objects/variables
	ifstream	inputFile;
	int			numProcesses;
	int			numResources;
	int*		resource;
	int*		allocationMatrix;
	int*		claimMatrix;
	int*		availableMatrix;
	int*		needMatrix;
	int			stateChecker;
	bool		safe = true;
	string		potentialProcess;
	int			newProcess;
	string		cancelCode;
	int			newResource;

	//	Dynamically allocating matrix arrays
	resource = new int[MAX_SIZE];
	allocationMatrix = new int[MAX_SIZE];
	claimMatrix = new int[MAX_SIZE];
	availableMatrix = new int[MAX_SIZE];
	needMatrix = new int[MAX_SIZE];


	//	Open the input File
	inputFile.open("system.txt");

	//	Get the number of processes and resources and print it out
	inputFile >> numProcesses;
	inputFile >> numResources;
	cout << "The total number of Processes: " << numProcesses << endl;
	cout << "The total number of Resources: " << numResources << endl << endl;

	//	Read in the Matrices
	int matrixResource = numProcesses * numResources;

	for (int i = 0; i < matrixResource; i++)
	{
		inputFile >> allocationMatrix[i];
	}
	for (int i = 0; i < matrixResource; i++)
	{
		inputFile >> claimMatrix[i];
	}
	for (int i = 0; i < matrixResource; i++)
	{
		inputFile >> availableMatrix[i];
	}

	//	Call function to see if user would like to cancel
	cancelCode = cancelCheck(cancelCode);
	if (cancelCode == "yes")
	{
		return 0;
	}

	//	Check to see if user would like to input a new process request
	cout << "Would you like to enter a process request? (If yes, type yes): ";
	cin >> potentialProcess;
	if (potentialProcess == "yes")
	{
		cout << "What process would you like to change/add? Process ";
		cin >> newProcess;
		if (newProcess > numProcesses)
		{
			cout << "Sorry, we cannot process this request at this point in time!";
			return 0;
		}
		else
		{
			int changeResource;
			changeResource = numResources * newProcess;

			for (int i = 0; i < numResources; i++)
			{
				cout << "Enter Resource " << i << " : ";
				cin >> newResource;
				if (newResource < allocationMatrix[changeResource])
				{
					cout << "Sorry, we cannot process that request." << endl;
					cout << "Enter New Resource " << i << " (greater than " << allocationMatrix[changeResource] << "): ";
					cin >> newResource;
				}
				else
					claimMatrix[changeResource] = newResource;
					changeResource++;
			}
		}
	}

	//	Set the Need Matrix
	for (int i = 0; i < matrixResource; i++)
	{
		needMatrix[i] = claimMatrix[i] - allocationMatrix[i];
	}

	//	Call function to set and display the initial system state
	printState(numProcesses, numResources, resource, allocationMatrix, claimMatrix, availableMatrix, needMatrix);

	//	Check to see if you can allocate resources to a process
	int totalResources;
	totalResources = numResources * numProcesses;
	int k = 0, j = 0;
	int currentResource = 0;
	int loopResources = numResources;

	for (int i = 0; i < totalResources; i++)
	{
		if (i < totalResources)
		{
			while (k < numProcesses)
			{
				k++;
				if (needMatrix[i] <= availableMatrix[i])
				{
					if (i % numResources == 0)
					{
						for (int l = 0; l < numResources; l++)
						{
							availableMatrix[l] += allocationMatrix[j];
							claimMatrix[j] = 0;
							allocationMatrix[j] = 0;
							needMatrix[j] = 0;
							j++;
						}
						printState(numProcesses, numResources, resource, allocationMatrix, claimMatrix, availableMatrix, needMatrix);
						loopResources += numResources;
					}
				}
			}
		}
	}

	//	Determine if the state is safe or not
	int safeCheck = 0;

	for (int i = 0; i < matrixResource; i++)
	{
		if (needMatrix[i] == 0)
		{
			safeCheck++;
		}
	}

	if (safeCheck == matrixResource)
	{
		cout << "///////////////////////////////////" << endl;
		cout << "//This System is in a Safe State!//" << endl;
		cout << "///////////////////////////////////" << endl;
	}
	else
	{
		cout << "///////////////////////////////////////" << endl;
		cout << "//This System is in a Not Safe State!//" << endl;
		cout << "///////////////////////////////////////" << endl;
	}

	system("pause");
	return 0;
}

/////////////////////////////////////////////////////////////
// This program prints out the current state of the system //
/////////////////////////////////////////////////////////////
void printState(int numProcesses, int numResources, int resource[], int allocationMatrix[], int claimMatrix[], int availableMatrix[], int needMatrix[])
{
	//	Print out the initial system's state
	cout << endl << right << setw(40) << "System's State" << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << right << "| Claim Matrix    |     Allocation Matrix    |         Need         |" << endl;
	cout << "---------------------------------------------------------------------" << endl;

	//	Loop to print out the initial system's state
	for (int i = 0; i < numProcesses; i++)
	{
		//	The first loop prints out the first row of resources for each matrix
		if (i == 0)
		{
			cout << "| ";
			for (int j = 0; j < numResources; j++)
			{
				cout << claimMatrix[j] << "   ";
			}
			cout << "|       ";
			for (int j = 0; j < numResources; j++)
			{
				cout << allocationMatrix[j] << "   ";
			}
			cout << "   |     ";
			for (int j = 0; j < numResources; j++)
			{
				cout << needMatrix[j] << "   ";
			}
			cout << " |" << endl;
			cout << "---------------------------------------------------------------------" << endl;
		}
		//	After the first loop, it will print out the next line of each matrix
		if (i != 0)
		{
			//	Used to find the next process
			int k = 0;
			int nextResource = 0;
			k = i * numResources;
			nextResource = k + numResources;

			cout << "| ";
			for (k; k < nextResource; k++)
			{
				cout << claimMatrix[k] << "   ";
			}
			cout << "|       ";

			//	Used to find the next process
			k = 0;
			nextResource = 0;
			k = i * numResources;
			nextResource = k + numResources;

			for (k; k < nextResource; k++)
			{
				cout << allocationMatrix[k] << "   ";
			}
			cout << "   |     ";

			//	Used to find the next process
			k = 0;
			nextResource = 0;
			k = i * numResources;
			nextResource = k + numResources;

			for (k; k < nextResource; k++)
			{
				cout << needMatrix[k] << "   ";
			}
			cout << " |" << endl;
			cout << "---------------------------------------------------------------------" << endl;
		}
	}
	//	Print out the available resources
	cout << endl << "Available Resources: ";
	for (int i = 0; i < numResources; i++)
	{
		cout << availableMatrix[i] << "   ";
	} cout << endl << endl;
}

/////////////////////////////////////////////////////////////
// This function asks if the user wants to end the program //
/////////////////////////////////////////////////////////////
string cancelCheck(string cancelCode)
{
	//	Check to see if the user would like to end the program
	cout << "Would you like to end this program now? (If yes, type yes): ";
	cin >> cancelCode;

	return cancelCode;
}

