#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
int main()
{
	ifstream fileName; //input file
	ofstream outputFile; //output file
	fileName.open("lab7.txt"); //open input file
	outputFile.open("lab7rpt.txt"); //open output file
	string university,location,highest_school; //names of string
	int num1=0, num2=0,total_num2=0; //names of enrollment, tuition and total tuition
	int count=0; //count for the while loop and thus the total schools
	int avg; //average tuition
	int max = INT_MIN; //max tuition

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

	//Display header
	outputFile << "\t\t\tOhio Universities Report\n\t\t\tWiebe Vossen Douglas Calmes\n\n";
	outputFile << left << setw(25) << "School name" << setw(20) << "Location" << setw(20) << "Enrollment" << setw(20) << "Tuition" << endl;
	while (!fileName.eof())
	{
		fileName >> university >> location >> num1 >> num2; //process file data
		outputFile << setw(25) << university << setw(20) << location << setw(20) << num1 << setw(20) << num2 << endl << endl;
		count++; //count amount of loops
		total_num2 += num2; //add tuition to total tuition

		//Determine max value of tuition and connect with the right university
		if (num2 > max)
		{
			max = num2;
			highest_school = university;
		}
	}
	
	avg = total_num2 / count; //calculate average tuition 

	//Display and align values as written in the text
	outputFile << setw(40) << "Number of schools:" << setw(25) << right << count << endl;
	outputFile << setw(40) << left << "Average Tuition:" << setw(25) << right << avg << endl;
	outputFile << setw(40) << left << "School with the highest tuition:" << setw(25) << right << highest_school << endl;
	outputFile << setw(40) << left << "The tuition there is: " << setw(25) << right << max << endl;
	
	//close input and output file
	fileName.close();
	outputFile.close();

	system("pause");
	return 0;
}