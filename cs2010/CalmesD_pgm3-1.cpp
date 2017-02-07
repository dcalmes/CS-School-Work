//--------------------------------------------------------------------------------------------------
//	Douglas Calmes					CS2010					M/W 6:00-7:15
//	Programming Assignment 3		CalmesD_pgm3			Due: 11:59PM, Wed, Sept. 30, 2015
//	Purpose:	The purpose of this program is to show the Adventure Campus Rewards credit
//				cardholder how many points that they have earned by using the Adventure
//				Campus Rewards credit card.  With this information the program will be able
//				to show the user what rewards they are able to redeem based on their choice
//				reward.
//	Input:		The program will ask the user to enter how much they have spent on
//				intertainment, food, and all other purchases while using the Adventure
//				Campus Rewards credit card.  Also, at the end of the calculations the program
//				will ask the user to input what their first choice in rewards.  These choices
//				will be "M"ovie rental, "P"izzas, or "I"tunes downloads.
//	Processing:	The program will first caclulate the total points the cardholder has earned
//				based on the amount spent on each type of purchase.  It will then look
//				at the cardholders prefered reward choice.  After the user inputs his/her
//				choice reward, it will then calculate how many of each reward the cardholder
//				gets, as well as, the left over points.
//	Output:		The program will output the total number of points earned, how many of each
//				reward they will recieve, and the leftover points they will have.
//-------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int		pizzas, movie_rentals, itunes_downloads, points_leftover; // Rewards
	int		pizza_mod, movie_mod, itunes_mod; // Points left over after each specific reward
	int		entertainment_purchases, food_purchases, other_purchases, total_points; // Total amount spent on each category.  Total points.
	string	reward_choice; // The cardholders first choice of rewards
	char	M, P, I; // Corresponding character the cardholder inputs for their first choice of rewards

	//	Have user enter the total dollar amount for each type of purchase

	cout << "Enter dollar amount of your Entertainment purchases:	$";
	cin >> entertainment_purchases;
	cout << "Enter dollar amount of your Food purchases:		$";
	cin >> food_purchases;
	cout << "Enter dollar amount of any other purchases:		$";
	cin >> other_purchases;
	cout << endl;

	//	Calculate and display the total number of points earned

	total_points = (5 * entertainment_purchases) + (2 * food_purchases) + other_purchases; // Calculation for total points

	cout << "Total number of points earned: " << total_points << endl << endl;

	//	Ask cardholder to enter their first choice for rewards

	cout << "Enter your first choice for rewards - (M)ovies, (P)izzas or (I)tunes: ";
	cin >> reward_choice;
	cout << endl;

	//	Calculate how many of each reward will be given to the cardholder

	if (reward_choice == "P")  // Calculations based on the user chosing Pizzas as their first choice
	{
		pizzas = total_points / 300;
		pizza_mod = total_points % 300;
		movie_rentals = pizza_mod / 150;
		movie_mod = pizza_mod % 150;
		itunes_downloads = movie_mod / 60;
		itunes_mod = movie_mod % 60;
		points_leftover = itunes_mod;
	}
	else if (reward_choice == "M") // Caclulations based on the user chosing Movie Rentals as their first choice
	{
		movie_rentals = total_points / 150;
		movie_mod = total_points % 150;
		itunes_downloads = movie_mod / 60;
		itunes_mod = movie_mod % 60;
		points_leftover = itunes_mod;
	}
	else if (reward_choice == "I") // Calculations based on the user chosing iTunes Downloads as their first choice
	{
		itunes_downloads = total_points / 60;
		itunes_mod = total_points % 60;
		points_leftover = itunes_mod;
	}
	else
	{
		cout << "Invalid Reward Choice!!!"; // Let cardholder know they have entered an invalid choice
		cout << endl << endl;
		system("pause");
		return 0; // End program promptly if they entered an invalid choice
	}

	//	Display the cardholders number of each reward

	cout << "You have earned the following rewards for your credit card purchases!";
	cout << endl;
	cout << "	" << pizzas << "	Pizzas (300 points each)"; // Display the number of pizzas
	cout << endl;
	cout << "	" << movie_rentals << "	Movie rentals (150 points each)"; // Display the number of movie rentals
	cout << endl;
	cout << "	" << itunes_downloads << "	iTunes downloads (60 points each)"; // Display the number of iTunes downloads
	cout << endl;
	cout << "	" << points_leftover << "	points leftover"; // Display the leftover points
	cout << endl << endl;

	system("pause");
	return 0;
}