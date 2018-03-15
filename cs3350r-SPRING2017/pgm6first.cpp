//	Programmer:	Douglas G Calmes		Program 6		CS 3350		6PM
//	Purpose:	This program shows the difference between pivot positions for quicksort
//	Due:		Wednesday, March 22, 2017 at 6PM

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//*********************  prototypes  *********************
template<class 
ItemType>
void quickSort(ItemType ary[], int first, int last, int &count);

template<class ItemType>
int partition(ItemType ary[], int first, int last, int &count);

template<class ItemType>
int sortFirstMiddleLast(ItemType ary[], int first, int last);

template<class ItemType>
void order(ItemType ary[], int i, int j);

template<class ItemType>
void insertionSort(ItemType ary[], int first, int last);

void arrayFill(int ary[], int arySize);

void arrayDisplay(int ary[], int arySize, int &count);

// Smallest size array quicksort will sort 
static const int MIN_SIZE  = 10;

//************************ main *************************
int main()
{
	int arySize;
	int count = 0;

	cout << "What would you like the size of the array to be?" << endl;
	cin >> arySize;
	if (arySize < MIN_SIZE) {
		cout << "The size that you wanted the array to be is too small, please try again!" << endl;
		cin >> arySize;
	}

	int ary[arySize];

	arrayFill(ary, arySize);

	int firstPos = 0;
	int lastPos = arySize;

	cout << "Array before sorting: " << endl;
	arrayDisplay(ary, arySize, count);

	quickSort(ary, firstPos, lastPos, count);

	cout << "Array after sorting: " << endl;
	arrayDisplay(ary, arySize, count);

   return 0;
}

//**********************  quickSort *************************
// Sorts an array into ascending order. Uses quick sort with
// median-of-three pivot selection for arrays of at least
// MIN_SIZE entries, uses insertion sort for other arrays.
//***********************************************************
template<class ItemType>
void quickSort(ItemType ary[], int first, int last, int &count)
{
   if (last - first + 1 < MIN_SIZE)
   {
      insertionSort(ary, first, last);
   }
   else
   {
      // Create the partition: S1 | Pivot | S2
      int pivotIndex = partition(ary, first, last, count);
 
     
      // Sort subarrays S1 and S2
      quickSort(ary, first, pivotIndex - 1, count);
      quickSort(ary, pivotIndex + 1, last, count);
   } 
}

//**********************  partition *************************
// Partitions entries in an array about a pivot entry
//***********************************************************
template<class ItemType>
int partition(ItemType ary[], int first, int last, int &count)
{
   // Choose pivot using median-of-three selection
   int pivotIndex = sortFirstMiddleLast(ary, first, last);
   
   // Reposition pivot so it is last in the array
   swap(ary[pivotIndex], ary[last - 1]);
   pivotIndex = first;	// Switched to first position in array
   ItemType pivot = ary[pivotIndex];
   
   // Determine the regions S1 and S2
   int indexFromLeft = first + 1;
   int indexFromRight = last - 2;
   
   bool done = false;
   while (!done)
   {
      // Locate first entry on left that is >= pivot
	   while (ary[indexFromLeft] < pivot) {
		   indexFromLeft = indexFromLeft + 1;
		   count++;
	  }

      // Locate first entry on right that is <= pivot
	   while (ary[indexFromRight] > pivot) {
		   indexFromRight = indexFromRight - 1;
		   count++;
	  }
      
      if (indexFromLeft < indexFromRight)
      {
         std::swap(ary[indexFromLeft], ary[indexFromRight]);
         indexFromLeft = indexFromLeft + 1;
         indexFromRight = indexFromRight - 1;
      }
      else
         done = true;
   }
   
   // Place pivot in proper position between S1 and S2, and 
   // mark its new location
   swap(ary[pivotIndex], ary[indexFromLeft]);
   pivotIndex = indexFromLeft;
   
   return pivotIndex;
} 
//****************  sortFirstMiddleLast ********************
// Arranges first, middle, last entry in sorted order.
//***********************************************************
template<class ItemType>
int sortFirstMiddleLast(ItemType ary[], int first, int last)
{
   int mid = first + (last - first) / 2;
   order(ary, first, mid); // Make ary[first] <= ary[mid]
   order(ary, mid, last);  // Make ary[mid] <= ary[last]
   order(ary, first, mid); // Make ary[first] <= ary[mid]
   
   return mid;
}

//************************  order  **************************
// Arranges two specified array entries into sorted order by
// exchanging them, if necessary.
//***********************************************************
template<class ItemType>
void order(ItemType ary[], int i, int j)
{
   if (ary[i] > ary[j])
      swap(ary[i], ary[j]); // Exchange entries
}

//********************** insertionSort **********************
// Sorts the items in an array into ascending order.
// Initially, sorted region is ary[0], unsorted region is 
// ary[1..n-1]. In general, sorted region is 
// ary[0..unsorted-1], unsorted region ary[unsorted..n-1]
//***********************************************************
template<class ItemType>
void insertionSort(ItemType ary[], int first, int last)
{
   int unsorted;      // first index of the unsorted region,
   int loc;           // index of insertion in sorted region
   ItemType nextItem; // next item in the unsorted region

   for (unsorted = first + 1; unsorted <= last; unsorted++)
   {
      // ary[0..unsorted-1] sorted. Find right position
      // (loc) in ary[0..unsorted] for ary[unsorted],
      // first entry in unsorted region;
      // shift, if necessary, to make room
      nextItem = ary[unsorted];
      loc = unsorted;
      while ((loc > first) && (ary[loc - 1] > nextItem))
      {
         // Shift ary[loc - 1] to the right
         ary[loc] = ary[loc - 1];
         loc--;
      } 
      
      // Insert nextItem in sorted region at ary[loc]
      ary[loc] = nextItem; 
   } 
} 

//**********************  arrayFill  ************************
// Fill in the array
//***********************************************************
void arrayFill(int ary[], int arySize) {
	for (int i = 0; i < arySize; i++) {
		ary[i] = rand() % 1000 + 1;
	}
 }

//********************  arrayDisplay  ***********************
// Display the array
//***********************************************************
void arrayDisplay(int ary[], int arySize, int &count) {
	cout << "Current state of your array: " << endl;
	for (int j = 0; j < arySize; j++) {
		cout << ary[j] << " ";
	}
	cout << "The total number of comparisons: " << count << endl;
}
