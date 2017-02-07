// File Name	:	prog1_02_calmes.cpp
// Discription	:	This program creates a child process to perform different computations as the parent process.
// Author	:	Douglas G Calmes
// Date		:	09/19/2016

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <unistd.h>
using namespace std;


// Functions
bool primeCheck(int);
int primeAssemble(int, int* &);

int main(int argc, char *argv[])
{
	int argNum = 1;
	int* pPrimeArray = nullptr;
	int index;
	int parentSum = 0;
	int childSum = 0;
	
	// Display last name
	cout << "Last name is " << argv[argNum] << endl;

	// Loop to find and display the "th" prime number that is input as argument
	for (argNum = 2; argNum < argc; argNum++)
	{
		cout << argv[argNum];
		index = atoi(argv[argNum]) - 1;
		cout << "th prime number is " << primeAssemble(index, pPrimeArray) << endl;
	}

	pid_t pid = fork();
	
	// This checks the pid and then will display the information for either the parent or child process
	if (pid == 0)
	{
		cout << endl << "In Child process," << endl;
		cout << "I am the child; my ID = " << getpid() << endl;
		cout << "I am the child; my Numbers = ";

		// Loop that find the sum of the childs numbers as well as display the numbers
		for (argNum = 2; argNum < argc; argNum++)
		{
			index = atoi(argv[argNum]) - 1;
			cout << index + primeAssemble(index, pPrimeArray) + 1 << ", ";
			childSum += (index + primeAssemble(index, pPrimeArray) + 1);
		}

		cout << endl << "I am the child; Sum = " << childSum << endl;
	}
	else if (pid > 0)
	{
		cout << endl << "In Parent process," << endl;
		cout << "I am the parent; my ID = " << getpid() << endl;
		cout << "I am the parent; my child ID = " << getpid() + 1 << endl;
		cout << "I am the parent; Prime numbers = ";
		
		// Loop to find the sum of the parents numbers as well as display the numbers
		for (argNum = 2; argNum < argc; argNum++)
		{
			index = atoi(argv[argNum]) - 1;
			cout << primeAssemble(index, pPrimeArray) << ", ";
			parentSum += primeAssemble(index, pPrimeArray);
		}

		cout << endl << "I am the parent; Sum = " << parentSum <<endl;
	}
}

// Discription	:	This function is used to check to see what numbers are and are not prime numbers
// Author	:	Douglas G Calmes
// Date		:	09/19/2016
bool primeCheck(int testPrime)
{
	// Shows that 1 and 0 are not prime
	if (testPrime == 1 || testPrime % 2 == 0)
		return false;
	// Shows that 2 is a prime number
	else if (testPrime == 2)
		return true;
	// Loop that tests every other number to see if it is prime or not
	else
	{
		for (int num = 3; num <= sqrt(testPrime); num += 2)
		{
			if (testPrime % num == 0)
				return false;
		}
	}
	// Return the prime number
	return true;
}

// Discription	:	This function will create an array of the prime numbers based on the argument(s)
// Author	:	Douglas G Calmes
// Date		:	09/19/2016
int primeAssemble(int aIndex, int* & primeNumArray)
{
	int index = 0;
	int num = 0;
	
	// Dynamically allocate primeNumArray
	primeNumArray = new int[aIndex];

		// While loop to build array
		while (index < aIndex)
		{
			if (primeCheck(num) == true)
			{
				primeNumArray[index] = num;
				index++;
			}
			num++;
		}
		
	// Return the prime number array
	return primeNumArray[aIndex - 1];
}

