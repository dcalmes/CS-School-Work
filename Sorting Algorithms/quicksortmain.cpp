#include<iostream>
#include<fstream>
#include<string>
#include<chrono>

using namespace std;

long int comparisons = 0;

int partition(long int[], long int, long int, int &);
void quicksort(long int[], long int, long int);

int main(int argc, char* argv[]) {
	// Variable setup---------------------------------------------------------------------------------------------------
	int element;
	int long i = 0;
	fstream myFile, randomFile;
	string fileName;
	string readFile = argv[1];
	int long totalelements = 0;
	clock_t start, stop;
	double executiontime;
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
	quicksort(array, 0, totalelements - 1);
	auto end_time = chrono::high_resolution_clock::now();
	auto time = end_time - start_time;
	
	cout << totalelements << ", " << comparisons << ", " << chrono::duration_cast<chrono::microseconds>(time).count() << endl;	

	return 0;
}



int partition(long int array[], long int p, long int r) {
	int x = array[r];
	int i = p - 1;
	int n = 0;
	for (int j = p; j <= r - 1; j++) {
		comparisons++;
		if (array[j] <= x) {
			i = i + 1;
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			n++;
		}
	}
	int temp1 = array[i + 1];
	array[i + 1] = array[r];
	array[r] = temp1;
	return i + 1;
}

void quicksort(long int array[], long int p, long int r) {
	if (p < r) {
		int q = partition(array, p, r);
		quicksort(array, p, q - 1);
		quicksort(array, q + 1, r);
	}
}




