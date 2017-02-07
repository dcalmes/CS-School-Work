//----------------------------------------------------------------------------------------------------
//	Douglas Calmes					CS2010					M/W 6:00-7:15
//	Programming Assignment 5		CalmesD_pgm5			Due: 11:59PM, Wed, Nov. 04, 2015
//	Purpose:	The purpose of this program is to create a modified version of Candly Land, a
//				children's game.  This game will be fully playable and will be played on an 85
//				square board through C++.
//	Input:		There is no input required for this program.  It requires neither keyboard or file
//				input in order to run the game.  Instead the program will use the function "rand" 
//				to automatically generage a random number to represent the cards the kids would
//				draw in real life (between 1-5).
//	Processing:	There is a series of processing steps that are needed in order to properly use this
//				program correctly.  First, you must declare all needed variables and seting the
//				players to the first square.  Next we will call a function in order to display the
//				heading for each players moves each turn.  Finally a loop will be created in
//				order to take a turn for each player until a player reaches the 85th square exactly.
//				The drawCard function in the loop draws each player a card and returns the value.
//				Then the movePlayer function will calculate the players movements and move them to
//				the corresponding square.  Finally, the displayMove function will display a line
//				showing the players currents position, squares moved, card number, new position,
//				and any candy bonus name.
//	Output:		The output of this program will show each players turns.  The values displayed for
//				each turn is the current position, card value, new position, and any candy bonus
//				that might of been earned.
//---------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime> 

using namespace std;

// Prototypes
int drawCard();
void displayHeading();
void displayMove(int, int &, int, int, int, string);
void movePlayer(int &, int &, int &, string &);

int main()
{
	int		moveNumber = 1, currentPosition = 1, cardNumber, newPosition = 0, num = 1;
	string	candyBonus;

	// Get a different series of random numbers each run
	srand(time(NULL));

	// Displaying the Header for the game results
	displayHeading();

	// Performing a while loop to continue the game until a player lands on exactly 85
	while (newPosition != 85)
	{
		moveNumber = num;			// Display the players current Move # based on num.
		cardNumber = drawCard();	// Displaying that card # is determined by drawCard function.
		
		// Call movePlayer function
		movePlayer(currentPosition, cardNumber, newPosition, candyBonus);

		// Call displayMove function
		displayMove(moveNumber, currentPosition, cardNumber, num, newPosition, candyBonus);
		
		currentPosition = newPosition;	// Determine current position.
		num++;	//counter
	}

	system("pause");
	return 0;
}

//*********************************************
//* Random Number Calculation for cardNumber. *
//*********************************************
int drawCard()
{
	return rand() % 5 + 1;
}

//**********************************************************************
//* Function to display the heading to the game in the main function.  *
//**********************************************************************
void displayHeading()
{
	cout << setw(30) << "Candy Land Game" << endl;
	cout << setw(28) << "Doug Calmes" << endl;
	cout << setw(33) << "CS2010, M/W 6:00-7:15" << endl << endl;
	cout << "Move #" << setw(20) << "Current Position" << setw(11) << "Card" << setw(15) << "New Position";
	cout << setw(15) << "Candy Bonus" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
}

//*********************************************************************************
//* Function that sends the players movement to the main function.                *
//* This includes: Move #, Current Position, Card, New Position, and Candy Bonus. *
//*********************************************************************************
void displayMove(int moveNumber, int &currentPosition, int cardNumber, int num, int newPosition, string candyBonus)
{
	cout << moveNumber << setw(20) << currentPosition << setw(11) << cardNumber << setw(15);
	cout << newPosition << setw (22) << right << candyBonus << endl;
	cout << "-------------------------------------------------------------------------" << endl;
}

//********************************************************************************
//* Calculate the square on which the player will move to, given the card value  *
//* given by the function drawCard.  The function will also pass back a players  *
//* new location and display the name of the Candy Bonus if the player has       *
//* landed on one of these locations.                                            *
//********************************************************************************
void movePlayer(int &currentPosition, int &cardNumber, int &newPosition, string &candyBonus)
{
	newPosition = currentPosition + cardNumber;  // Calculate players new position
	if (newPosition <= 85)
	{

		if (newPosition == 6)
		{
			newPosition = 40;
			candyBonus = "Rainbow Trail";
		}
		else if (newPosition == 9)
		{
			newPosition = 24;
			candyBonus = "Lord Licorice";
		}
		else if (newPosition == 32)
		{
			newPosition = 43;
			candyBonus = "Gumdrop Pass";
		}
		else if (newPosition == 46)
		{
			newPosition = 58;
			candyBonus = "Mr. Mint";
		}
		else if (newPosition == 62)
		{
			newPosition = 73;
			candyBonus = "Queen Frostine";
		}
		else
		{
			candyBonus = " ";
		}
	}
	
	else if (newPosition > 85)		// Reset current position if you move over square 85.
	{
		newPosition -= cardNumber;
	}
}