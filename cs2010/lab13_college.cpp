//File name: lab13_college.cpp
//Description: Lab 13 - This program...
//Author: Wiebe Vossen and Douglas Calmes
//Date: 12/02/2015

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int read_college_info(string[],string[],int[],int[]);
void bubbleSort_parallel(string[], string[], int[], int[],int,int);
void write_sorted_college_info(string[], string[], int[], int[]);
const int MAX_VALUE = 100;

int main()
{
	int number_schools = 0;
	string university_name[MAX_VALUE];
	string location[MAX_VALUE];
	int num_students[MAX_VALUE];
	int tuition[MAX_VALUE];
	int choice = 0;
	number_schools = read_college_info(university_name, location, num_students, tuition);
	cout << "There are "<< number_schools<< " college information"<<endl;
	cout << "Do you want to sort by enrollment (1) or by tuition (2)? ";
	cin >> choice;

	if (choice == 1||choice==2)
		bubbleSort_parallel(university_name, location, num_students, tuition, choice,number_schools);
	else
	{
		cout << "Incorrect choice, you should choose between 1 or 2.";
		system("pause");
		return 0;
	}

	write_sorted_college_info(university_name, location, num_students, tuition);
	



	system("pause");
	return 0;
}

int read_college_info(string university_name[], string location[], int num_students[],int tuition[])
{
	ifstream inFile;
	inFile.open("OH-in.dat");
	int i = 0;

	string SENTINEL = "***";

	inFile >> university_name[i];
	while (university_name[i] != SENTINEL)
	{
		inFile >> location[i] >> num_students[i] >> tuition[i];
		i++;
		inFile >> university_name[i];
	} 
	

	inFile.close();

	return i;
}

void bubbleSort_parallel(string university_name[], string location[], int num_students[], int tuition[], int choice, int number_schools)
{
	bool swap;
	int temp;

	if (choice == 1)
	{
		do
		{
			swap = false;
			for (int count = 0; count < (number_schools - 1); count++)
			{
				if (num_students[count+1]>num_students[count])
				{
					temp = num_students[count];
					num_students[count] = num_students[count + 1];
					num_students[count + 1] = temp;
					swap = true;
				}
			}
		} while (swap);
	}

	else if (choice == 2)
	{
		do
		{
			swap = false;
			for (int count = 0; count < (number_schools - 1); count++)
			{
				if (tuition[count+1]>tuition[count])
				{
					temp = tuition[count];
					tuition[count] = tuition[count + 1];
					tuition[count + 1] = temp;
					swap = true;
				}
			}
		} while (swap);
	}
}
void write_sorted_college_info(string university_name[], string location[], int num_students[], int tuition[])
{
	ofstream outFile;
	outFile.open("Sorted-OH.dat");
	int i = 0;

	string SENTINEL = "***";
	outFile << "--------------------------------------------------------------------------------------------------------------------------"<<endl;
	outFile << setw(40) << "College Name" << setw(30) << "College Location" << "\t\tNumber of Students\tTuitions"<<endl;
	outFile<< "--------------------------------------------------------------------------------------------------------------------------"<<endl;
	outFile << setw(40)<<university_name[i];
	while (university_name[i] != SENTINEL)
	{
		outFile <<setw(30)<< location[i]<<"\t\t\t" << num_students[i]<<"\t\t"  << tuition[i]<<endl;
		i++;
		outFile << setw(40) << university_name[i];
	}


	outFile.close();
}