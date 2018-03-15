// Programmer: 	Douglas G Calmes
// Class:	CS 3350		6PM
// Program:	Program 7
// Purpose:	The purpose of this is to understand queue operations
	
#include <iostream>
#include <iomanip>
#include "ArrayQueue.h"
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_WAIT = 30;

struct Customer{
	int customerNumber;
	int timeQueued;
	int queueTime;
};

int main(){
	// Creating customer queue
	ArrayQueue<Customer> myQueue;

	// Random seeding
	srand (time(NULL));

	//Variables
	int numberCount = 1;
	int customerCount = 0;		// Total number of customers
	int totalWaitTime = 0;		// Total wait time
	int longestWaitTime = 0;	// Variable used to store longest wait time
	int numCustomersLeft = 0;	// Variable used to store number of customers left

	// Queue looping
	for (int i = 0; i < MAX_WAIT; i++){
		int caseNum = rand() % 3 + 1;	// 1/3 chance of customer getting added
		int waitTime = rand() % 5 + 1;	// Wait time of queued customer

		// If statement adding up customers who were added to queue after max wait is reached
		if (i + waitTime > MAX_WAIT && caseNum == 1){
			numCustomersLeft += 1;
		}

		if (longestWaitTime < waitTime){
			longestWaitTime = waitTime;
		}

		// Calculate total wait time
			totalWaitTime += waitTime;
		// Calculate total number of customers
			if (caseNum == 1){
			customerCount = customerCount + 1;
		}

		cout << "--------------------------------------------------------------" << endl;
		cout << "Minute " << i << ": ";

		switch(caseNum){
			case 1:
			// Create new Customer
				Customer case1Customer;
				case1Customer.customerNumber = customerCount;
				case1Customer.timeQueued = i;
				case1Customer.queueTime = waitTime;
				// Add new customer to the queue
				myQueue.enqueue(case1Customer);
				cout << "Customer " << case1Customer.customerNumber << " was added at minute " << case1Customer.timeQueued << endl;
				break;
			// No customer added to queue for this case
			case 2:
				cout << "There is no new customer to add to the queue!" << endl;
				break;
			// No customer added to queue for this case
			case 3:
				cout << "There is no new customer to add to the queue!" << endl;
				break;
		}
	}
		// Function to calculate the average waiting time
		int averageWaitingTime = totalWaitTime / customerCount;

		// Print out statistic Display
		cout << "--------------------------------------------------------------" << endl;
		cout << "Simulated Time : " << MAX_WAIT << "Minutes" << endl;
		cout << "Total Customers Served: " << customerCount << endl;
		cout << "Customers Still Waiting: " << numCustomersLeft << endl;
		cout << "Average Waiting Time: " << averageWaitingTime << endl;
		cout << "Longest Waiting Time: " << longestWaitTime << endl;
		cout << "--------------------------------------------------------------" << endl;


		return 0;
}
