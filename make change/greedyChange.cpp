#include<iostream>
#include<string>
#include<chrono>
using namespace std;

// Prototype functions
int greedyCoins(int[], int, int);

// global varaibles
int coinsUsed_greedy = 0;

int main(int argc, char* argv[])
{
	// Variables
	int change = atoi(argv[1]);
	int numCoins = atoi(argv[2]);
	int* coins;
	coins = new int[numCoins];

	// Create array based on arguments
	int j = 0;
	for (int i = 3; i < numCoins + 3; i++) {
		coins[j] = atoi(argv[i]);
		j++;
	}
	
	// Print out results for greedy
	auto greedy_start = chrono::high_resolution_clock::now();
	cout << "The number of coins used (greedy): " << greedyCoins(coins, change, numCoins) << " total. Time: ";
	auto greedy_end = chrono::high_resolution_clock::now();
	auto greedy_time = greedy_end - greedy_start;
	cout << chrono::duration_cast<chrono::nanoseconds>(greedy_time).count() << endl;

	return 0;
}

int greedyCoins(int coins[], int change, int numCoins) {
	int temp = 0;

	// Loop to find out how many of each coin will be used
	// Start at last array element and move down
	for (int i = numCoins - 1; i >= 0; i--) {
		if (coins[i] <= change) {
			temp = change / coins[i];	// find how many of each coin can be used
			change -= temp * coins[i];	// deduct coins used from change left
			coinsUsed_greedy += temp;	// variable to see how many coins are used
			cout << temp << "x" << coins[i] << ", ";	// print out coin and how many used
		}
	}
	return coinsUsed_greedy;
}