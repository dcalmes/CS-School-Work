//////////////////////////////////////////////////////////////////////////////
// Program			6
// Description:		This program will define and demonstrate a Money
//						class.  Dollars and cents will be stored separately
//						so that more money amounts can be represented as
//						precisely as possible
// Programmer:		 Douglas G Calmes
// Class:			 CS 2020, Spring 2016
//////////////////////////////////////////////////////////////////////////////

#ifndef MONEY_H
#define MONEY_H
using namespace std;

class Money
{	
private:
	int dollars;		//	Dollars value
	int cents;			//	Cents value
	void simplify();	//	checks for values in cents that are 100 or greater 
						//	or less than 0, adjusts dollars and cents as needed so
						//	that cents amount is never greater than 99

public:
	//	Constructors
	Money() {dollars = 0 ; cents = 0; }
	Money(int dollars, int cents) { this->dollars = dollars; this->cents = cents; }

	//	Accessors
	int getDollars() const { return dollars; }
	int getCents() const { return cents; }

	//	Mutators
	void setDollars(int dollars) { this->dollars = dollars; }
	void setCents(int cents) {this->cents = cents; }

	//	Overloaded functions
	Money operator+(const Money &) const;
	Money operator-(const Money &) const;
	friend ostream & operator<<(ostream &, const Money &);
	friend istream & operator>>(istream &, Money &);
};

#endif 