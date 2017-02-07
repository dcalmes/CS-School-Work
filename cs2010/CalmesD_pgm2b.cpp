//------------------------------------------------------------------------------------
//	Name:		Douglas Calmes		Course: CS2010		Time: M/W 6:00-7:15
//	Purpose:	The purpose of this program is to calculate a local car rental
//				agency's rental charges.
//	Input:		The inputs for this program are the number of days rented, the
//				beginning odometer reading, and the ending odometer reading.
//	Processing:	Within this program we will find out how much the daily rental charges
//				are by multiplying the price per day by the number of days the car
//				was rented.  Then we will find out the mileage charges by multiplying
//				the number of miles by the price charged per mile.  After that we will
//				find out the taxes and fees for the rental car.  Finally we will find
//				the sum of these charges to display the total bill.
//	Output:		The outputs for this program are the daily rental charges, mileage
//				charges, taxes and fees, and the total bill.
//------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
	int		daysRented;
	double	begOdom, endOdom, rentCharge, mileCharge, taxFee, totalBill;

	// Get the number of days rented, the beginning odometer reading, and the ending
	// odometer reading.

	cout << "Enter the number of days rented: ";
	cin >> daysRented;
	cout << "Enter the beginning odometer reading: ";
	cin >> begOdom;
	cout << "Enter the ending odometer reading: ";
	cin >> endOdom;
	cout << endl;

	// Calculations to determine the total bill of the rental car.

	rentCharge = daysRented * 15.00;
	mileCharge = (endOdom - begOdom) * 0.12;
	taxFee = (rentCharge + mileCharge) * 0.25;
	totalBill = rentCharge + mileCharge + taxFee;

	// Display the calculations of the Daily Rental Charge, Mileage Charges, Taxes
	// and fees, and the Total Bill.

	cout << "Daily rental charges: $" << rentCharge << endl;
	cout << "Mileage charges: $" << mileCharge << endl;
	cout << "Taxes and Fees: $" << taxFee << endl;
	cout << "Total bill: $" << totalBill << endl;

	cout << endl;
	system("pause");
	return 0;

}