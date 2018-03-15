#include <iostream>
#include<string>
#include<chrono>

using namespace std;

// Prototype function
int dynamicChange(int, int [], int , int [], int []);

int main(int argc, char* argv[])
{
	// argument 1 set to change amount
	int change = atoi(argv[1]);
	// argument 2 set to number of coins
	int numCoins = atoi(argv[2]);
	// create array for coin values
	int* coins;
	coins = new int[numCoins];
	// create array for total coins
    int *totalCoins;
    totalCoins = new int[change+1];
    // create array for largest coin amount
    int *amount;
    amount = new int[change+1];
    int coinDisplay = change;

	// Create array based on arguments
	int j = 0;
	for (int i = 3; i < numCoins + 3; i++) {
		coins[j] = atoi(argv[i]);
		j++;
	}

	// time how long algorithm takes
	auto dynamic_start = chrono::high_resolution_clock::now();
    int coinsUsed = dynamicChange(change, coins, numCoins, totalCoins, amount);
    auto dynamic_end = chrono::high_resolution_clock::now();
	auto dynamic_time = dynamic_end - dynamic_start;

    cout << "The number of coins used (dynamic): " << "(" << coinsUsed << " total)  ";
    // loop to display every coin used
    while(coinDisplay != 0) {
	cout << coins[amount[coinDisplay]] << " ";
	coinDisplay = coinDisplay - coins[amount[coinDisplay]];
    }

    cout << endl << "Time Elapsed: " << chrono::duration_cast<chrono::nanoseconds>(dynamic_time).count() << endl;
	
    delete[] totalCoins;
    delete[] amount;

    return 0;
}

int dynamicChange(int change, int coins[], int numCoins, int totalCoins[], int amount[]){  
	// initialize the 0 element in the totalCoins array to 0
    totalCoins[0] = 0;

    // this outer for loop initialized each element in the totalCoins array to infinite amount
    for(int changeAmount = 1; changeAmount <= change; changeAmount++) {
	totalCoins[changeAmount] = 999999999;
		// this inner for loop is used to perform the bottom up dynamic function for the change function
		for(int usedCoin = 0; usedCoin < numCoins; usedCoin++) {
			// call this if still coins available for use in each change amount.  it will not be called if the coin
			//		you are trying to use greater than the amount of change left
	   		if(totalCoins[changeAmount-coins[usedCoin]] + 1 < totalCoins[changeAmount] && changeAmount >= coins[usedCoin]) {
	   		// update the total coins used for the change amount you are on
			totalCoins[changeAmount] = totalCoins[changeAmount-coins[usedCoin]] + 1;
			// set the biggest coin used for each change amount in the amount array to help with display in main
			amount[changeAmount] = usedCoin;  
	    	}
		}
    }
    return totalCoins[change];
}