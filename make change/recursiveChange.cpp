#include<iostream>
#include<string>
#include<chrono>
using namespace std;

// Prototype functions
int recursiveCoins(int[], int, int);

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

	// Print out results for recursive
	auto recursive_start = chrono::high_resolution_clock::now();
	cout << "The number of coins used (recursive): " << recursiveCoins(coins, change, numCoins) << "  Time: ";
	auto recursive_end = chrono::high_resolution_clock::now();
	auto recursive_time = recursive_end - recursive_start;
	cout << chrono::duration_cast<chrono::nanoseconds>(recursive_time).count() << endl;

	return 0;
}

int recursiveCoins(int coins[], int change, int numCoins)
{
	// Base Case
	if (change == 0){
		return 0;
	}

	int coinsUsed_recursive = 999999999;
	
	// Loop to find recursive call of make change
	for (int i = 0; i < numCoins; i++) {
		if (coins[i] <= change) {
			// Recursive call with change being deducted by coin used
			int temp_coinsUsed = recursiveCoins(coins, change - coins[i], numCoins);
			// Coin counter for best case
			if (temp_coinsUsed != 999999999 && temp_coinsUsed + 1 < coinsUsed_recursive) {
				coinsUsed_recursive = temp_coinsUsed + 1;
			}
		}
	}
	// Return best case for recursive call
	return coinsUsed_recursive;
}
