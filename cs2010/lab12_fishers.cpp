/*Filename	:	lab12_fishers.cpp
Description	:	Lab12- THis prgram tracks fishers
Author		:	Wiebe Vossen & Douglas Calmes
Date		:	11/18/2015
*/

#include <iostream>
#include <fstream>

using namespace std;

void get_fish(int&,int[]);
void show_fish(int[],int);
void find_best_fisher(int[],int);

const int maxfishers = 25;
int main()
{
	int numfishers = 0;
	int fish[maxfishers];

	get_fish(numfishers, fish);
	show_fish(fish, numfishers);
	find_best_fisher(fish, numfishers);
	
	system("pause");
	return 0;
}

void get_fish(int &numfishers, int fish[])
{
	ifstream inputFile;

	inputFile.open("fish.txt");
	if (!inputFile)
		cout << "Failed to open file" << endl;

	while (!inputFile.eof())
	{
		inputFile >> fish[numfishers];
		numfishers++;
	}

	inputFile.close();
}

void show_fish(int fish[], int numfishers)
{
	for (int i = 0; i < numfishers; i++)
	{
		cout << "Fisher\t\t" << i+1 << "\tcaught\t\t" << fish[i] << "\tfish" << endl;
	}
}

void find_best_fisher(int fish[], int numfishers)
{
	int highest = fish[0];
	int best_fisher = 1;
	for (int i = 0; i < numfishers; i++)
	{
		if (fish[i] > highest)
		{
			highest = fish[i];
			best_fisher = i+1;
		}
		
	}
	cout << endl << "The winner is Fisher " << best_fisher << " by catching " << highest <<" fish" << endl;
}