/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Program:     Program 1
// Purpose: 	Create a program plan and then convert it into C++ statements.  Dealing with Warehouse stocks and Average.
// Input: 		prog1.txt
// Processing:  Different functions to perform:
//				Function:		ReadData                                                 
//				Description:	This function reads the data and populates the arrays    
//				Function:		Bsort                                                    
//				Description:	This function sorts the arrays 
//				Function:		PrintArrays                                              
//				Description:	This function prints out the arrays into a chart   
//				Function:		Restock                                                  
//				Description:	This function prints out low stocked items             
//				Function:		HighPrice                                                
//				Description:	This function finds out the high price    
//				Function:		AvgWarehouse                                             
//				Description:	This function finds the average of each warehouse        
// Output:		This program prints out the data and statistics, as well as the average per warehouse, and the high, and 
//				items that need restocked		
// Programmer:	Douglas Calmes
// Class:		CS 2020 Spring 2016
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

//	Prototypes
int ReadData(int[], string[], string[], double[]);
void BSort(int[], string[], string[], double[], int);
void PrintArrays(int[], string[], string[], double[], int);
void Restock(int[], string[], double[], int);
int HighPrice(string[], string[], double[], int);
void AvgWarehouse(string[], double[], int, double&, double&, double&);

//	Constant Size of Arrays
const int SIZE = 30;


int main()
{
	int quantity[SIZE];
	int highPrice = 0;
	int count = 0;
	string item[SIZE];
	string location[SIZE];
	double price[SIZE];
	double average_WarehouseC = 0;
	double average_WarehouseJ = 0;
	double average_WarehouseM = 0;
	
	count = ReadData(quantity, item, location, price);
	
	BSort(quantity, item, location, price, count);

	PrintArrays(quantity, item, location, price, count);
	cout << endl;

	Restock(quantity, item, price, count);
	cout << endl;

	highPrice = HighPrice(item, location, price, count);

	cout << "The highest priced item is the " << item[highPrice] << ", located in " << location[highPrice] << " with a price of $" << price[highPrice] << endl << endl;

	AvgWarehouse(location, price, count, average_WarehouseC, average_WarehouseJ, average_WarehouseM);
	
	cout << setprecision(2) << fixed;
	cout << "Warehouse C average: $" << average_WarehouseC << endl;
	cout << "Warehouse J average: $" << average_WarehouseJ << endl;
	cout << "Warehouse M average: $" << average_WarehouseM << endl;
	
	system("pause"); 
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
// Program 1																 /
// Description:																 /	
// Programmer:		Douglas Calmes											 /
// Class:			CS 2020, Spring 2016                                     /
//                                                                           /
// Function:		ReadData                                                 /
// Description:		This function reads the data and populates the arrays    /
// Parameters:		quantity[]- quantity data                                /
//					item[]- item name data                                   /
//					location[]- location of item data                        /
//					price[]- price of item data                              /
// Returns:			Returns I                                                /
//////////////////////////////////////////////////////////////////////////////

int ReadData(int quantity[], string item[], string location[], double price[])
{
	ifstream inFile;
	inFile.open("prog1.txt");

	int i = 0;

	while (!inFile.eof())
	{
		getline(inFile, item[i]);
		inFile >> quantity[i];
		inFile.ignore(1, ' ');
		getline(inFile, location[i]);
		inFile >> price[i];
		
		i++;

		inFile.ignore(1, ' ');
	}
	return i;
}

//////////////////////////////////////////////////////////////////////////////
// Program 1																 /
// Description:																 /	
// Programmer:		Douglas Calmes											 /
// Class:			CS 2020, Spring 2016                                     /
//                                                                           /
// Function:		Bsort                                                    /
// Description:		This function sorts the arrays                           /
// Parameters:		quantity[]- quantity data                                /
//					item[]- item name data                                   /
//					location[]- location of item data                        /
//					price[]- price of item data                              /
//					count- count                                             /
// Returns:			Nothing                                                  /
//////////////////////////////////////////////////////////////////////////////

void BSort(int quantity[], string item[], string location[], double price[], int count)
{
	bool swapped = true;
    int num = 0;
	int temp;
	string temp2;
	string temp3;
	double temp4;


	  do
	  {
		  swapped = false;
		  num++;

		  for (int i = 0; i < count - num; i++) 
		  {
			  if (quantity[i] < quantity[i + 1]) 
			  {
				  temp = quantity[i];
				  quantity[i] = quantity[i + 1];
				  quantity[i + 1] = temp;
				  swapped = true;

				  temp2 = item[i];
				  item[i] = item[i + 1];
				  item[i + 1] = temp2;

				  temp3 = location[i];
				  location[i] = location[i + 1];
				  location[i + 1] = temp3;

				  temp4 = price[i];
				  price[i] = price[i + 1];
				  price[i + 1] = temp4;

			  }
		  }
	  } while (swapped);
}

//////////////////////////////////////////////////////////////////////////////
// Program 1																 /
// Description:																 /	
// Programmer:		Douglas Calmes											 /
// Class:			CS 2020, Spring 2016                                     /
//                                                                           /
// Function:		PrintArrays                                              /
// Description:		This function prints out the arrays into a chart         /
// Parameters:		quantity[]- quantity data                                /
//					item[]- item name data                                   /
//					location[]- location of item data                        /
//					price[]- price of item data                              /
//					cout- count			                                     /
// Returns:			Nothing                                                  /
//////////////////////////////////////////////////////////////////////////////

void PrintArrays(int quantity[], string item[], string location[], double price[], int count)
{
	cout << left << setw(15) << "Item" << setw(10) << "Qty" << setw(15) << "Location" << setw(10) << "Price" << endl;
	cout << setw(15) << "-----" << setw(10) << "---" << setw(15) << "--------" << setw(10) << "-----" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << left << setw(15) << item[i] << setw(10) <<  quantity[i] << setw(15) << location[i] << setw(10) << price[i] << endl;
	}
}

//////////////////////////////////////////////////////////////////////////////
// Program 1																 /
// Description:																 /	
// Programmer:		Douglas Calmes											 /
// Class:			CS 2020, Spring 2016                                     /
//                                                                           /
// Function:		Restock                                                  /
// Description:		This function prints out low stocked items               /
// Parameters:		quantity[]- quantity data                                /
//					item[]- item name data                                   /
//					price[]- price of item data                              /
//					cout- count			                                     /
// Returns:			Nothing                                                  /
//////////////////////////////////////////////////////////////////////////////

void Restock(int quantity[], string item[], double price[], int count)
{
	cout << "The low stock items are:" << endl;
	cout << setw(13) << "Item" << setw(10) << "Qty" << endl;
	cout << setw(13) << "----" << setw(10) << "---" << endl;

	for (int i = 0; i < count; i++)
	{
		if (quantity[i] < 100)
		{
			cout << setw(13) << item[i] << setw(10) << quantity[i] << endl;
		}
	}

}

//////////////////////////////////////////////////////////////////////////////
// Program 1																 /
// Description:																 /	
// Programmer:		Douglas Calmes											 /
// Class:			CS 2020, Spring 2016                                     /
//                                                                           /
// Function:		HighPrice                                                /
// Description:		This function finds out the high price                   /
// Parameters:                                                               /
//					item[]- item name data                                   /
//					location[]- location of item data                        /
//					price[]- price of item data                              /
//					cout- count			                                     /
// Returns:			Nothing                                                  /
//////////////////////////////////////////////////////////////////////////////

int HighPrice(string item[], string location[], double price[], int count)
{
	int highposition = 0;
	double  high;

	for (int i = 0; i < count; i++)
	{
		if (price[i] > high)
		{
			highposition = i;
			high = price[i];
		}
	}
	return highposition;
}

//////////////////////////////////////////////////////////////////////////////
// Program 1																 /
// Description:																 /	
// Programmer:		Douglas Calmes											 /
// Class:			CS 2020, Spring 2016                                     /
//                                                                           /
// Function:		AvgWarehouse                                             /
// Description:		This function finds the average of each warehouse        /
// Parameters:		                                                         /
//					location[]- location of item data                        /
//					price[]- price of item data                              /
//					cout- count			                                     /
//					average_WarehouseC- WarehouseC average                   /
//					average_WarehouseJ- WarehouseJ average                   /
//					average_WarehouseM- WarehouseM average                   /
// Returns:			Nothing                                                  /
//////////////////////////////////////////////////////////////////////////////

void AvgWarehouse(string location[], double price[], int count, double &average_WarehouseC, double &average_WarehouseJ, double &average_WarehouseM)
{
	double countC;
	double countJ;
	double countM;
	double priceC;
	double priceJ;
	double priceM;

	for (int i = 0; i < count; i++)
	{
		if (location[i] == "Warehouse C")
		{
			countC++;
			priceC += price[i];
		}
		else if (location[i] == "Warehouse J")
		{
			countJ++;
			priceJ += price[i];
		}
		else if (location[i] == "Warehouse M")
		{
			countM++;
			priceM += price[i];
		}
	}
	
	average_WarehouseC = priceC / countC;
	average_WarehouseJ = priceJ / countJ;
	average_WarehouseM = priceM / countM;

}