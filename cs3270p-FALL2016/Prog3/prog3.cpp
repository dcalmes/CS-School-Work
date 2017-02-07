// File Name	:	prog3.cpp
// Discription	:	This program will create multiple processes
//					and simulate CPU scheduling
// Author		:	Douglas G Calmes
// Date			:	10/11/2016
#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <cmath>
#include <fstream>
#include <stdio.h>
using namespace std;

// Set max programs
const int MAX_PROGS = 100;
int main(int argc, const char * argv[])
{
	// Declared Variables
	int numProgs;
	int arival[MAX_PROGS];
	int burst[MAX_PROGS];
	int program[MAX_PROGS];
	ifstream inputFile(argv[1]);

	// Read in the Input File
	inputFile >> numProgs;
	for (int i = 0; i < numProgs; i++)
	{
		program[i] = i;
		inputFile >> arival[i] >> burst[i];
	}

	int pid, pid2;
	
	// Create the fork
	pid = fork();
	if (pid == 0)
	{
		pid2 = fork();
		if (pid2 == 0)
		{
			// Find the order of SJF
			for (int i = 0; i < numProgs; i++)
			{
				for (int j = 0; j < numProgs - i - 1; j++)
				{
					if (burst[j] > burst[j + 1])
					{
						int temp = arival[j];
						arival[j] = arival[j + 1];
						arival[j + 1] = temp;

						int temp1 = burst[j];
						burst[j] = burst[j + 1];
						burst[j + 1] = temp1;

						int temp2 = program[j];
						program[j] = program[j + 1];
						program[j + 1] = temp2;
					}
				}

			}

			int wait[MAX_PROGS];
			wait[0] = 0;
			double avgWait = 0;
			// Determine average wait
			for (int i = 1; i < numProgs; i++)
			{
				wait[i] = 0;
				for (int j = 0; j < i; j++)
				{
					wait[i] += burst[j];
				}
				avgWait += wait[i];
			}

			avgWait /= numProgs;

			// Display SJF
			cout << "-------------------------------------------------------------------------" << endl;
			cout << "Shortest Job First Process Schedule" << endl;

			for (int i = 0; i < numProgs; i++)
			{
				cout << program[i] << "  ";
			}

			cout << endl << "Child Process 2 ID: " << getpid() << endl;
			cout << "Average SJF Wait Time: " << avgWait << endl;
			cout << "-------------------------------------------------------------------------" << endl << endl;

			return 0;
		}
	
		else
		{
			int timeQuant = 6;
			int totalTime = 0;
			int k = 0;

			// Find the total amount of time 
			for (int i = 0; i < numProgs; i++)
			{
				totalTime += burst[i];
			}

			// Display RR scheduling
			cout << "-------------------------------------------------------------------------" << endl;
			cout << "Round Robin Process Schedule" << endl;

			// Loop to find the order of the RR schedule
				for (int j = 0; j < totalTime; j++)
				{
				for (k = 0; k < numProgs; k++)
					{
						if (burst[k] > 0)
						{
							burst[k] -= timeQuant;
							cout << program[k] << "  ";
						}
					}
				}

			cout << endl << "Child Process 1 ID: " << getpid() << endl;
			cout << "Average Wait Time: " << endl;
			cout << "-------------------------------------------------------------------------" << endl << endl;
		}
}
	if (pid > 0)
	{
		double avgWait = 0;

		// Find order for FCFS
		for (int i = 0; i < numProgs; i++)
		{
			for (int j = 0; j < numProgs - i - 1; j++)
				if (arival[j] > arival[j + 1])
				{
					int temp = arival[j];
					arival[j] = arival[j + 1];
					arival[j + 1] = temp;

					int temp1 = burst[j];
					burst[j] = burst[j + 1];
					burst[j + 1] = temp1;

					int temp2 = program[j];
					program[j] = program[j + 1];
					program[j + 1] = temp2;
				}
		}

		// Calculate the avg wait for FCFS
		int wait[MAX_PROGS];
		wait[0] = 0;

		for (int i = 1; i < numProgs; i++)
		{
			wait[i] = 0;
			for (int j = 0; j < i; j++)
			{
				wait[i] += burst[j];
			}
			avgWait += wait[i];
		}

		avgWait /= numProgs;

		// Display FCFS
		cout << "-------------------------------------------------------------------------" << endl;
		cout << "First Come First Serve Process Schedule" << endl;

		for (int i = 0; i < numProgs; i++)
		{

			cout << program[i] << "  ";
		}

		cout << endl << "Parent Process ID: " << getpid() << endl;
		cout << "Average FCFS Wait Time: " << avgWait << endl;
		cout << "-------------------------------------------------------------------------" << endl << endl;
	}
}
