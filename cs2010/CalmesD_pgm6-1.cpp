//-------------------------------------------------------------------------------------------------------
//	Douglas Calmes					CS2010					M/W 6:00-7:15
//	Programming Assignment 6		CalmesD_pgm6			Due: 11:59PM, Fri, Nov. 20, 2015
//	Purpose:	The purpose of this program is to analyze temperature data between March, April,
//				and May in 2014.  With this information, this program will then read the temperatures,
//				display the temperatures, convert them to fharenheit,find the average temperature,
//				show us the days that were above the average, and finally find the highest temperature.
//	Input:		This program will input pgm6.txt which stores all the temperatures of each day in
//				March, April, and May in Celsius.  These temperatures will be read and stored in an
//				array of type double.  This is how we will be able to carry out the program.
//	Processing:	There is a series of processing steps that are needed in order to properly use this
//				program correctly.  First, you must declare the array in which will hold the
//				and the other variables in order to correctly run the program.  The main function will
//				then call a function that will read the daily temperatures from pgm6.txt, which will
//				store each temperature in an element in the array.  After closing the data file, we
//				will then call a function that will display the temperatures of March and display
//				them.  Then the program will convert the temperatures from Celcius to Fahrenheit.
//				the program will repeat these last steps for the months of April and May.  After that
//				the program will call a function that will determine and display the average 
//				temperature for these three months, which the main function will display.  Next the
//				program will call another function to find and display the number of days in which 
//				exceeded the average temperature.  Finally, one last funciton will be called in order
//				to find and display the highest temperature for each month.
//	Output:		The output of this program will be to show the temperatures, convert them to 
//				fharenheit,find the average temperature, show us the days that were above the 
//				average, and finally find the highest temperature of the months of March, 
//				April, and May.
//------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//Prototypes
void readTemps(int&, double[]);
void displayTemps(double[], int, int);
void convertToFahrenheit(double[], int);
double findAvgTemp(double[], int);
void findDaysAboveAvg(double[], int, double);
void findHiTemp(double[], int, int, int);

//Global constants
const int dayMarch = 31;	//When March ends
const int dayApril = 61;	//When April ends
const int dayMay = 92;		//When May ends
const int maxDays = 92;		//Max number of days

int main()
{
	int numTemp = 0;
	double temp[maxDays];
	double averageTemp;

	//Call in readTemps function
	readTemps(numTemp, temp);

	//Call in displayTemps function
	displayTemps(temp, dayMarch, dayApril);

	//Call in convertToFahrenheit function
	convertToFahrenheit(temp, maxDays);

	//Call in displayTemps function
	displayTemps(temp, dayMarch, dayApril);

	//Call in findAvgTemp function; assign it to averageTemp
	averageTemp = findAvgTemp(temp, maxDays);

	//Display the average temperature
	cout << endl << endl;
	cout << "The Average Temperature during this timeframe: " << averageTemp << endl;

	//Call in findDaysAboveAvg function
	findDaysAboveAvg(temp, maxDays, averageTemp);

	//Call in findHiTemp function
	findHiTemp(temp, dayMarch, dayApril, dayMay);


	system("pause");
	return 0;
}

//**********************************************************************
//* Function that reads the daily temperatures from pgm6.txt           *
//* This function stores the temperatures in an element in the array.  *
//**********************************************************************
void readTemps(int &numTemp, double temp[])
{
	ifstream inputFile;

	inputFile.open("pgm6.txt");		//Open input file

	//Display error message if file failed to open
	if (!inputFile)
		cout << "Failed to open file" << endl;

	//While loop to end when it is the end of the file
	while (!inputFile.eof())
	{
		inputFile >> temp[numTemp];
		numTemp++;
	}

	inputFile.close();		// Close input file
}

//*************************************************************
//* Function to display the temperatures in March and April.  *
//*************************************************************
void displayTemps(double temp[], int dayMarch, int dayApril)
{
	if (temp[0] < 73)
	{
		//Display the header for the temperatures for March
		cout << "     Temperatures for March" << endl;
		cout << "	Douglas Calmes" << endl << endl;
		cout << "  Day	       Temperature" << endl;
		cout << "of month       (Celsius)" << endl;
		cout << "------------------------------" << endl;

		//Loop that outputs the temperatures for the days in March
		for (int num = 0; num < dayMarch; num++)
		{
			cout << num + 1 << "\t\t" << temp[num] << endl;
		}
	}
	else
	{
		//Display the header for the temperatures for April
		cout << endl << endl;
		cout << "     Temperatures for April" << endl;
		cout << "	Douglas Calmes" << endl << endl;
		cout << "  Day	       Temperature" << endl;
		cout << "of month      (Fahrenheit)" << endl;
		cout << "------------------------------" << endl;

		//Loop that outputs the temperatures for the days in April
		for (int num = 31; num < dayApril; num++)
		{
			cout << num - 30 << "\t\t" << temp[num] << endl;
		}
	}
}

//****************************************************
//* Function that converts Celsius into Fahrenheit.  *
//****************************************************
void convertToFahrenheit(double temp[], int maxDays)
{
	//Loop that states to convert the entire file into Fahrenheit
	for (int num = 0; num < maxDays; num++)
	{
		temp[num] = ((9.0 / 5.0) * temp[num]) + 32;	//Fahrenheit conversion
	}
}

//**********************************************************
//* Function to find the average temperatures of the data  *
//**********************************************************
double findAvgTemp(double temp[], int maxDays)
{
	int num;
	double averageTemp, sum = 0;

	//Loop that finds the sum of all the temperatures
	for (num = 0; num < maxDays; num++)
	{
		sum += temp[num];
	}

	//Equation to find the average temperature
	averageTemp = sum / maxDays;

	return averageTemp;	//Returen the average temperature
}

//**********************************************************************************
//* Function to find and display the number of days above the average temperature  *
//**********************************************************************************
void findDaysAboveAvg(double temp[], int maxDays, double averageTemp)
{
	int numDays = 0;

	//Loop that determines the number of days above the average temperature
	for (int num = 0; num < maxDays; num++)
	{
		if (temp[num] > averageTemp)
		{
			numDays++;
		}
	}

	//Display the number of days that are above the average temperature
	cout << endl;
	cout << "The number of days that are above the average temperature: " << numDays << endl;
}

//***********************************************************************************
//* Function to find and display the highest temperatures in March, April, and May  *
//***********************************************************************************
void findHiTemp(double temp[], int dayMarch, int dayApril, int dayMay)
{
	int num;
	double marchHigh, aprilHigh, mayHigh;
	
	//Find the highest temperature in March
	for (num = 0; num < dayMarch; num++)
	{
		if (temp[num] > marchHigh)
			marchHigh = temp[num];
	}

	//Display March's highest temperature
	cout << endl << "The highest temperature in March: " << marchHigh << endl;

	//Find the highest temperature in April
	for (num = 31; num < dayApril; num++)
	{
		if (temp[num] > aprilHigh)
			aprilHigh = temp[num];
	}

	//Display April's highest temperature
	cout << "The highest temperature in April: " << aprilHigh << endl;

	//Find the highest temperature in May
	for (num = 61; num < dayMay; num++)
	{
		if (temp[num] > mayHigh)
			mayHigh = temp[num];
	}

	//Display May's highest temperature
	cout << "The highest temperature in May: " << mayHigh << endl;
}