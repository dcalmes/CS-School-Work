// Programmer: Douglas G Calmes
// Program: Program 9
// Purpose:  Show the difference between different hash functions and linear probing vs double hashing
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <iomanip>
#include "hashTable.h"
using namespace std;

struct Inventory{
	int key;
	string description;
};

const int MAX_VALUE = 53;
int main() {
	hashTable<Inventory> hashInventory;
	Inventory newCostomer;
	int loops = 0, findHash = 0, collisions, totalCollisions, mostCollisions, findKey;
	bool found = false;

	cout << "How many records would you like to add to the hash table? ";
	cin >> loops;

	// Add new records to hash table
	for (int i = 0; i < loops; i++) {
		int randomKey = rand() % 9000 + 1000;
		newCostomer.key = randomKey;
		newCostomer.description = "Inv " + to_string(i);
		collisions = hashInventory.add(newCostomer);
		if (collisions > mostCollisions) {
			mostCollisions = collisions;
		}
		totalCollisions += collisions;
	}

	hashInventory.displayTable(loops);

	// Calculate the average number of collisions
	double averageCollisions = 0.0;
	averageCollisions = static_cast<double>(totalCollisions / loops);

	// Print out statistics
	cout << endl << "New Hash With Double Hashing" << endl;
	cout << "Hash Table Length: " << MAX_VALUE << endl;
	cout << "Numbe of Records Added: " << loops << endl;
	cout << "Most Collisions for Record: " << mostCollisions << endl;
	cout << "Average Collisions per Record: " << setprecision(3) << averageCollisions << endl;
	cout << "Total Number of Collisions: " << totalCollisions << endl;

	cout << "What item would you like to find? ";
	cin >> findKey;

	// Check to see if the key is found, then report proper information
	if (hashInventory.is_present(findKey) == true) {
		found = true;
		hashInventory.getItem(findKey, found, newCostomer);
		cout << newCostomer.key << "     " << newCostomer.description << endl;
	}
	else {
		cout << "Item does not exist" << endl;
	}


	system("Pause");
	return 0;
}