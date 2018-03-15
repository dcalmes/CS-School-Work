#include<iostream>
#include<fstream>
#include<string>
#include<chrono>

using namespace std;

long int comparisons = 0;

void maxheapify(long int[], long int, long int);
void buildmaxheap(long int[], long int);
void heapsort(long int[], long int);

int main(int argc, char* argv[]) {
	// Variable setup---------------------------------------------------------------------------------------------------
	int element;
	long int i = 0;
	fstream myFile, randomFile;
	string fileName;
	string readFile = argv[1];
	long int totalelements = 0;
	//------------------------------------------------------------------------------------------------------------------


	//------------------------------------------------------------------------------------------------------------------
	myFile.open(readFile);
	while (!myFile.eof()) {
		myFile >> element;
		totalelements += 1;
	}

	long int* array = NULL;
	array = new long int[totalelements];

	randomFile.open(readFile);
	while (!randomFile.eof()) {
		randomFile >> element;
		array[i] = element;
		i++;
	}
	
	auto start_time = chrono::high_resolution_clock::now();
	heapsort(array, totalelements);
	auto end_time = chrono::high_resolution_clock::now();
	auto time = end_time - start_time;

	cout << totalelements << ", " << comparisons << ", " << chrono::duration_cast<chrono::microseconds>(time).count() << endl;

	return 0;
}

void maxheapify(long int array[], long int h, long int i) {
	int bigValue = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	
	comparisons++;
	if (l < h && array[l] > array[bigValue]){
		bigValue = l;
	}
	comparisons++;
	if (r < h && array[r] > array[bigValue]){
		bigValue = r;
	}
	comparisons++;
	if (bigValue != i)
	{
		int temp = array[i];
		array[i] = array[bigValue];
		array[bigValue] = temp;
		maxheapify(array, h, bigValue);
	}
}

void buildmaxheap(long int array[], long int size) {
	for (int i = size / 2; i >= 1; i--) {
		maxheapify(array, size, i);
	}
}

void heapsort(long int array[], long int size) {
	buildmaxheap(array, size);
	for (int i = size - 1; i > 0; i--) {
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		maxheapify(array, i, 0);
	}
}


