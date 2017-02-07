//--------------------------------------------------------------------------------------------------
//	Douglas Calmes					CS2010					M/W 6:00-7:15
//	Programming Assignment 4		CalmesD_pgm4			Due: 11:59PM, Fri, Oct. 16, 2015
//	Purpose:	The purpose of this program is to read an Internet usage data from a file and
//				create a report to summarize the data.  This program will then use this data to
//				determine, using loop algorithms, totals, averages, and higest values from the 
//				data that is given.
//	Input:		In this program we will input data about each area of the world's internet usage
//				stored in a file called pgm4.txt.  The program will then read the area's name,
//				the population, number of Internet users in 200 and then the current Internet
//				usage for each of those areas.
//	Processing:	The program will first open the input file (pgm4.txt) and an output file to enable
//				the program to write the findings, while checking to see the success of each of
//				the operations.  Next, a while loop will be used in order to read in the name,
//				population and Internet usage for each area.  It will also find the penetration and
//				growth percentages for each area, print a line showing the area name, population
//				and penetration and growth percentages.  It will then take these numbers and add
//				them to the appropriate totals.  Finally, the loop will determine whether this
//				area has higher values for the population, current Internet users or the
//				percentages.  After all these processes have finished, the program will finally
//				print out the summary data.
//	Output:		The program will output a file that will show the findings of the program
//-------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	ifstream fileName;
	ofstream outputFile;
	fileName.open("pgm4.txt");
	outputFile.open("pgm4rpt.txt");
	string area, highest_population, most_Iusers, highest_Ipenetration, highest_Igrowth;
	int growth_percentage, penetration_percentage, number_users, area_population;
	unsigned long num1 = 0, num2 = 0, num3 = 0;
	double penetration, growth;
	long double total_population, total_2000, total_current, avg_penetration, avg_growth, total_penetration, total_growth;
	int count = 0;
	unsigned long max = 0, max2 = 0;
	long double	max3 = 0, max4 = 0;

	// Checking to see if the input file and the output file will open correctly
	if (!fileName)
		{
			cout << "File is not correctly opened.";
		}
	else
		{
			cout << "File is correctly opened." << endl;
		}

	if (!outputFile)
		{
			cout << "Output file is not correctly opened.";
		}

	// Displaying the header for the data chart we are creating
	outputFile << "					     World Internet Usage Report" << endl;
	outputFile << "					Douglas Calmes, CS2010, M/W 6:00-7:15" << endl << endl;
	outputFile << right << setw(59) << "Internet users" << setw(35) << "Penetration" <<endl;
	outputFile << left << setw(20) << "Area" << setw(20) << "Population" << setw(20) << "2000" << setw(20) << "Current" << setw(20) << "(% Pop)" << setw(20) << "Growth %" << endl;
	outputFile << "---------------------------------------------------------------------------------------------------------------------------" << endl;

	// Perform a while loop of the input file (pgm4.txt)
	while (!fileName.eof())
	{
		fileName >> area >> num1 >> num2 >> num3;											 // Setting the variables to the information in the input file
		penetration = (static_cast<long double>(num3) / static_cast<long double>(num1)) * 100;		 // Calculating the penetration percentage
		growth = (static_cast<long double>(num3 - num2) / static_cast<long double> (num2)) * 100;    // Calculating the growth percentage

		// Displaying the data that is inside the input file (pgm4.txt) onto the output file (pgm4rpt.txt)
		outputFile << setw(20) << area << setw(20) << num1 << setw(20) << num2 << setw(20) << num3 << "%" << setw(20) << penetration << "%" << setw(20) << growth << endl << endl;
		
		// Running counter
		count++;

		// Performing calculations in order to find the following:
		total_population += num1;								// Total population
		total_2000 += num2;										// Total internet usage in 2000
		total_current += num3;									// Total current internet usage
		total_penetration += penetration;						// Total penetration percentage
		total_growth += growth;									// Total growth percentage
		avg_penetration = total_penetration / count;			// Average penetration percentage
		avg_growth = total_growth / count;						// Average growth percentage

		// Determining which area has the highest of the following:
			if (num1 > max)										// Highest Population
			{
				max = num1;
				highest_population = area;
			}

			if (num3 > max2)									// Most internet users
			{
				max2 = num3;
				most_Iusers = area;
			}
			if (penetration > max3)								// Highest internet penetration
			{
				max3 = penetration;
				highest_Ipenetration = area;
			}
			if (growth > max4)									// Highest internet usage growth
			{
				max4 = growth;
				highest_Igrowth = area;
			}
	}

	// Displaying the results we calculated from the input file during the while loop
	outputFile << "----------------------------------------------------------------------------------------------------------------------------" << endl;
	outputFile << "Total/Avg%" << right << setw(22) << total_population << setw(20) << total_2000 << setw(20) << total_current << setw(16) << avg_penetration << "%" << setw(24) << avg_growth << "%" << endl << endl;
	outputFile << "Area with highest population:			" << highest_population << endl;
	outputFile << "                  Population:			" << max << endl;
	outputFile << "Area with most Internet users:			" << most_Iusers << endl;
	outputFile << "                 Number Users:			" << max2 << endl;
	outputFile << "Area with highest internet penetration:		" << highest_Ipenetration << endl;
	outputFile << "                         Penetration %:		" << max3 << "%" << endl;
	outputFile << "Area with highest Internet usage growth:	" << highest_Igrowth << endl;
	outputFile << "                               Growth %:	" << max4 << "%" << endl;

	//close input and output file
	fileName.close();
	outputFile.close();

	system("pause");
	return 0;
}