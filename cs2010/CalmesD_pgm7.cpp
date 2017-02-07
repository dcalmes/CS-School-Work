//-------------------------------------------------------------------------------------------------------
//	Douglas Calmes					CS2010					M/W 6:00-7:15
//	Programming Assignment 7		CalmesD_pgm7			Due: 11:59PM, Wed, Dec. 9, 2015
//	Purpose:	The purpose of this program is to report about storm activity in the Atlantic in 2014.
//	Input:		This program will input pgm7.txt which stores the storm data.  This data is the storm
//				name and wind velocity.
//	Processing:	There is a series of processing steps that are needed in order to properly use this
//				program correctly.  First, you must call a function to read pgm7.txt, store this data
//				into two arrays, and close the file.  Next you will call a function to print the storm
//				data.  Then the program will call functions in order to find the average wind velocity
//				and another to find the storm with the highest wind velocity.  Finally the program will
//				organize the the arrays in decending order by wind velocity, and rewrite the chart.
//	Output:		The output of this program will be to dispay a chart in which displays the storm name,
//				the wind velocity, and the storm category each falls in.  It also displays the average
//				velocity and the storm that has the highest wind velocity.
//------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Prototypes
int read_storm_info(string[], int[]);
void print_sotrm_info(string[], int[], string, int);
double find_average_velocity(int[], int);
void highest_velocity(int[], string[], int, int&, string&);
void sort_velocity(int[], string[], int);

// Global Constant
const int MAX_VALUE = 15;

int main()
{
	string storm_name[MAX_VALUE];
	int velocity[MAX_VALUE];
	string storm_category;
	int storm_count = 0;
	double average_velocity = 0;
	string highest_velocity_name;
	int highest_velo;

	//Call in read_storm_info function
	storm_count = read_storm_info(storm_name, velocity);

	//Header for storm activity chart
	cout << right << setw(40) << "Atlantic Storm Activity for 2014" << endl;
	cout << right << setw(30) << "Douglas G Calmes" << endl << endl;
	cout << "Name" << setw(25) << "Wind Velocity" << setw(20) << " Storm Category" << endl;
	cout << "----------------------------------------------------------" << endl;

	//Call in print_storm_info function
	print_sotrm_info(storm_name, velocity, storm_category, storm_count);

	//Call in average_velocity function
	average_velocity = find_average_velocity(velocity, storm_count);

	//Display average wind velocity
	cout << endl << endl;
	cout << "The Average Velocity: " << average_velocity << endl;

	//Call in highest_velocity function
	highest_velocity(velocity, storm_name, storm_count, highest_velo,  highest_velocity_name);

	//Display the storm in which had the highest wind velocity
	cout << endl << "Storm " << highest_velocity_name << " had the highest wind velocity of " << highest_velo << " miles per hour" << endl << endl;

	//Call in sort_velocity function
	sort_velocity(velocity, storm_name, storm_count);

	//Header for storm activity chart
	cout << right << setw(40) << "Atlantic Storm Activity for 2014" << endl;
	cout << right << setw(30) << "Douglas G Calmes" << endl << endl;
	cout << "Name" << setw(25) << "Wind Velocity" << setw(20) << " Storm Category" << endl;
	cout << "----------------------------------------------------------" << endl;

	//Recall in print_storm_info function
	print_sotrm_info(storm_name, velocity, storm_category, storm_count);

	system("pause");
	return 0;
}

//*****************************************************************
//* Function that reads the information from pgm6.txt             *
//* This function stores the data in an element in the 2 arrays.  *
//*****************************************************************
int read_storm_info(string storm_name[], int velocity[])
{
	ifstream inFile;

	inFile.open("pgm7.txt");	//Open input file
	int i = 0;					//Count number of storms

	//Display error message if file failed to open
	if (!inFile)
		cout << "Failed to open file" << endl;

	//While loop till end of file
	while (!inFile.eof())
	{
		inFile >> storm_name[i] >> velocity[i];
		i++;
	}


	inFile.close();	//Close input file

	return i;		//Return the storm count
}

//********************************************************************
//* Function that prints the storm data & discovers storm category.  *
//********************************************************************
void print_sotrm_info(string storm_name[], int velocity[], string storm_category, int storm_count)
{
	//Loop that outputs the collected data
	for (int num = 0; num < storm_count ; num++)
	{
		//Determine what category the storms fall into
		if (velocity[num] < 39)
		{
			storm_category = "Tropical Depression";
		}
		if (velocity[num] < 73 && velocity[num] > 39)
		{
			storm_category = "Tropical Storm";
		}
		if (velocity[num] < 95 && velocity[num] > 75)
		{
			storm_category = "Hurricane 1";
		}
		if (velocity[num] < 110 && velocity[num] > 96)
		{
			storm_category = "Hurricane 2";
		}
		if (velocity[num] < 129 && velocity[num] > 111)
		{
			storm_category = "Hurricane 3";
		}
		if (velocity[num] < 156 && velocity[num] > 130)
		{
			storm_category = "Hurricane 4";
		}
		if (velocity[num] > 156)
		{
			storm_category = "Hurricane 5";
		}

		//Output the data collected
		cout << left << setw(20) << storm_name[num] << setw(20) << velocity[num] << setw(20) << storm_category << endl;
	}
}

//****************************************************************
//* Function that discovers the average velocity of the storms.  *
//****************************************************************
double find_average_velocity(int velocity[], int storm_count)
{
	int num;
	double average_velocity, sum = 0;

	//Loop that finds the sum of all wind velocities
	for (num = 0; num < storm_count; num++)
	{
		sum += velocity[num];
	}

	//Equation to find average wind velocity
	average_velocity = sum / 9;

	//Return the average wind velocity
	return average_velocity;
}

//***************************************************
//* Function that finds the highest wind velocity.  *
//***************************************************
void highest_velocity(int velocity[], string storm_name[], int storm_count, int &highest_velo, string &highest_velocity_name)
{
	int num;
	highest_velo = 0;

	//Loop to find the highest wind velocity and the name that corresponds to it
	for (num = 0; num < storm_count; num++)
	{
		if (velocity[num] > highest_velo)
		{
			highest_velo = velocity[num];
			highest_velocity_name = storm_name[num];
		}

	}

}

//**********************************************************************
//* Function that sorts the data by wind velocity, in decending order. *
//**********************************************************************
void sort_velocity(int velocity[], string storm_name[], int storm_count)
{
	bool swap;
	int temp;
	string temp1;

	//Bubble sort the data in decending order of wind velocity
	do
	{
		swap = false;
		for (int count = 0; count < (storm_count - 1); count++)
		{
			if (velocity[count + 1]>velocity[count])
			{
				temp = velocity[count];
				velocity[count] = velocity[count + 1];
				velocity[count + 1] = temp;

				temp1 = storm_name[count];
				storm_name[count] = storm_name[count + 1];
				storm_name[count + 1] = temp1;
				
				swap = true;
			}
		}
	} while (swap);
}
