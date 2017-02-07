//------------------------------------------------------------------------------------
//	Name:		Douglas Calmes		Course: CS2010		Time: M/W 6:00-7:15
//	Purpose:	The purpose of this program is to calculate a local movie theater's
//				profit from ticket sales.
//	Input:		The inputs for this program are movie name, how many adult ticket's
//				were sold, and how many child ticket's were sold.
//	Processing:	Within this program we will find the sum of the total movie ticket's
//				sold.  With this gross income we can determine how much the movie
//				theater makes, as well as, how much the distributor makes.  In order
//				to do this we will take the gross ticket sales and multiply that
//				total by the percentage each ones makes off the sales.
//	Output:		The outputs for this program are the gross ticket sales, theater
//				net profit, and the amound paid to the distributor.
//------------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int		adultTicket, childTicket;
	double	grossSale, theaterNet, distributor;
	string	movieTitle;

	// During this step you get the title of the movie

	cout << "Enter the movie name: ";
	cin >> movieTitle;

	// Enter the ticket sales for adult and children

	cout << "How many adult tickets were sold: ";
	cin >> adultTicket;
	cout << "How many children's tickets were sold: ";
	cin >> childTicket;
	cout << endl;

	// Perform calculations for the ticket sales

	grossSale = (adultTicket * 10.00) + (childTicket * 6.00);
	theaterNet = grossSale * .20;
	distributor = grossSale * .80;

	// Display the outputs of gross ticket sales, theater net profit, and
	// the amount paid to the distributor

	cout << "Gross Ticket Sales: $" << grossSale << endl;
	cout << "Theater Net Profit: $" << theaterNet << endl;
	cout << "Amount Paid to Distributor: $" << distributor << endl;

	cout << endl;
	system("pause");
	return 0;

}