#include<iostream>
#include<fstream>
#include<string>
#include<chrono>

using namespace std;


void insertionsort(long int array[], long int size) {
	auto start_time = chrono::high_resolution_clock::now();
	long int j, key, i;
	long int count = 1;
	for (j = 1; j < size; j++) {
		key = array[j];
		i = j - 1;
		while (i >= 0 && array[i] > key) {
			array[i + 1] = array[i];
			i = i - 1;
			count++;
		}
		count++;
		array[i + 1] = key;
	}
	auto end_time = chrono::high_resolution_clock::now();
	auto time = end_time - start_time;
	cout << size << ", " << count << ", " << chrono::duration_cast<chrono::microseconds>(time).count() << endl;
}