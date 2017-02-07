// Program 3
// Description: Products program
// Programmer:	Douglas G Calmes
// Class:		CS 2020, Spring 2016


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//	Structures
struct Corp
{
	int Q1_Sales = 0;
	int Q2_Sales = 0;
	int Q3_Sales = 0;
	int Q4_Sales = 0;
	int Number_Divs = 0;
};

struct Division
{
	string Div_Name;
	int Div_salesQ1;
	int Div_salesQ2;
	int Div_salesQ3;
	int Div_salesQ4;
};

//	Prototypes
void getDivision(Division*, ifstream&);
void printDivision(Division*);
void addDivision(Corp*, Division*);
void printCorpSummary(Corp*);

int main()
{
	ifstream infile;
	Corp* pCorp = new Corp;
	Division* pDiv = new Division;

	infile.open("prog3.txt");

	if (!infile)
	cout << "ERROR: The file failed to open" << endl;

	//	Header
	cout << "-------------------------------------------------------------" << endl;
	cout << right << setw(50) << "Stratus Corporation Sales Report*" << endl;
	cout << right << setw(40) << "Douglas G Calmes" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << right << setw(18) << "Division" << setw(10) << "Q1" << setw(10) << "Q2" << setw(10) << "Q3" << setw(10) << "Q4"<< endl;

	//	While loop in order to read in all the sales data for each division from program3.txt
	//	and create a report
	while (!infile.eof())
	{
		getDivision(pDiv, infile);
		printDivision(pDiv);
		addDivision(pCorp, pDiv);
	}

	cout << "-------------------------------------------------------------" << endl;

	printCorpSummary(pCorp);
	
	delete pDiv;
	delete pCorp;

	pDiv = nullptr;
	pCorp = nullptr;

	return 0;
}

// Function:	getDivision
// Description: The purpose of this function is to read in the data for one division
//				and store the data in the Division struct using the pointer variable.
// Programmer:	Douglas G Calmes
// Class:		CS 2020, Spring 2016
// Parameters:	pDiv	- Pointer to Division structure
//				infile	- input file object
// Returns:		This function is void.

void getDivision(Division* pDiv, ifstream &infile)
{
	getline(infile, pDiv->Div_Name);
	infile >> pDiv->Div_salesQ1;
	infile >> pDiv->Div_salesQ2;
	infile >> pDiv->Div_salesQ3;
	infile >> pDiv->Div_salesQ4;

	infile.ignore(1, ' ');
}

// Function:	printDivision
// Description: The purpose of this function is to write out a line of input to display
//				the division name, four quarterly sales amounts and the total sales
//				for the year for that division.
// Programmer:	Douglas G Calmes
// Class:		CS 2020, Spring 2016
// Parameters:	pDiv	- pointer to Division structure
// Returns:		This function is void.

void printDivision(Division* pDiv)
{
	
	cout << right << setw(18) << pDiv->Div_Name << setw(10) << pDiv->Div_salesQ1 << setw(10); 
	cout << pDiv->Div_salesQ2 << setw(10) << pDiv->Div_salesQ3 << setw(10) << pDiv->Div_salesQ4 << endl;

}

// Function:	addDivision
// Description:	The purpose of this function is to add the divisional quarterly sales to
//				the corporation quarterly sales.  We also increment Number_Divs to calculate
//				the total  number of divisions are in the corporation.
// Programmer:	Douglas G Calmes
// Class:		CS 2020, Spring 2016
// Parameters:	pCorp	- Pointer to Corp structure
//				pDiv	- Pointer to Division structure
// Returns:		This function is void.

void addDivision(Corp* pCorp, Division* pDiv)
{
	pCorp->Q1_Sales += pDiv->Div_salesQ1;
	pCorp->Q2_Sales += pDiv->Div_salesQ2;
	pCorp->Q3_Sales += pDiv->Div_salesQ3;
	pCorp->Q4_Sales += pDiv->Div_salesQ4;

	pCorp->Number_Divs++;
}

// Function:	printCorpSummary
// Description: The purpose of this function is to print the total corporate sales for each quarter,
//				the total sales for all quarters for the year, the average quarterly sales for each
//				quarter, and the highest and lowest quarters for the corporation.
// Programmer:	Douglas G Calmes
// Class:		CS 2020, Spring 2016
// Parameters:	pCorp	- Pointer to Corp structure
// Returns:		This function is void.

void printCorpSummary(Corp* pCorp)
{


	cout << right << setw(18) << "Corp Totals:" << setw(10) << pCorp->Q1_Sales << setw(10) << pCorp->Q2_Sales;
	cout << setw(10) << pCorp->Q3_Sales << setw(10) << pCorp->Q4_Sales << endl;
	cout << right << setw(18) << "Avg Qtr Sales:" << setw(10) << pCorp->Q1_Sales / pCorp->Number_Divs << setw(10);
	cout << pCorp->Q2_Sales / pCorp->Number_Divs << setw(10) << pCorp->Q3_Sales / pCorp->Number_Divs << setw(10);
	cout << pCorp->Q4_Sales / pCorp->Number_Divs << endl << endl;
	cout << right << setw(17) << "Total Sales: " << pCorp->Q1_Sales + pCorp->Q2_Sales + pCorp->Q3_Sales + pCorp->Q4_Sales << endl;

	if (pCorp->Q1_Sales > pCorp->Q2_Sales && pCorp->Q1_Sales > pCorp->Q3_Sales && pCorp->Q1_Sales > pCorp->Q4_Sales)
	{
		cout << right << setw(17) << "Corp High Qtr: " << pCorp->Q1_Sales << endl;
	}
	else if (pCorp->Q2_Sales > pCorp->Q1_Sales && pCorp->Q2_Sales > pCorp->Q3_Sales && pCorp->Q2_Sales > pCorp->Q4_Sales)
	{
		cout << right << setw(17) << "Corp High Qtr: " << pCorp->Q2_Sales << endl;
	}
	else if (pCorp->Q3_Sales > pCorp->Q1_Sales && pCorp->Q3_Sales > pCorp->Q2_Sales && pCorp->Q3_Sales > pCorp->Q4_Sales)
	{
		cout << right << setw(17) << "Corp High Qtr: " << pCorp->Q3_Sales << endl;
	}
	else if (pCorp->Q4_Sales > pCorp->Q1_Sales && pCorp->Q4_Sales > pCorp->Q2_Sales && pCorp->Q4_Sales > pCorp->Q3_Sales)
	{
		cout << right << setw(17) << "Corp High Qtr: " << pCorp->Q4_Sales << endl;
	}
	
	if (pCorp->Q1_Sales < pCorp->Q2_Sales && pCorp->Q1_Sales < pCorp->Q3_Sales && pCorp->Q1_Sales < pCorp->Q4_Sales)
	{
		cout << right << setw(17) << "Corp Low Qtr: " << pCorp->Q1_Sales << setw(33) << "* $ in thousands" << endl;
	}
	else if (pCorp->Q2_Sales < pCorp->Q1_Sales && pCorp->Q2_Sales < pCorp->Q3_Sales && pCorp->Q2_Sales < pCorp->Q4_Sales)
	{
		cout << right << setw(17) << "Corp Low Qtr: " << pCorp->Q2_Sales << setw(33) << "* $ in thousands" << endl;
	}
	else if (pCorp->Q3_Sales < pCorp->Q1_Sales && pCorp->Q3_Sales < pCorp->Q2_Sales && pCorp->Q3_Sales < pCorp->Q4_Sales)
	{
		cout << right << setw(17) << "Corp Low Qtr: " << pCorp->Q3_Sales << setw(33) << "* $ in thousands" << endl;
	}
	else if (pCorp->Q4_Sales < pCorp->Q1_Sales && pCorp->Q4_Sales < pCorp->Q2_Sales && pCorp->Q4_Sales < pCorp->Q3_Sales)
	{
		cout << right << setw(17) << "Corp Low Qtr: " << pCorp->Q4_Sales << setw(33) << "* $ in thousands" << endl;
	}
	//cout << right << setw(17) << "Corp Low Qtr: " << pCorp->Q1_Sales << setw(33) << "* $ in thousands" << endl;
}