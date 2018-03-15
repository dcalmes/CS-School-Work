// Douglas G Calmes	Program 2	CS3350r
#include <iostream>
#include "pgm2bag.h"
using namespace std;

int main()
{
// Bag variables
int bagChoice1, bagChoice2, bagsize1, bagsize2, bagsize3, bagsize4;
ArrayBag<int> firstBag;
ArrayBag<int> secondBag;
ArrayBag<int> thirdBag;
ArrayBag<int> fourthBag;

// As user to input two bags he would like to hold values too
cout << "Please input the two bags you would like to hold values, between 1 and 4: " << endl;
cin >> bagChoice1;
cin >> bagChoice2;

// Error message if user inputs wrong numbers
// Set the values of the bags chosen
if (bagChoice1 < 1 || bagChoice1 > 4 || bagChoice2 < 1 || bagChoice2 > 4)
	{
		cout << "ERROR: YOU MUST CHOOSE A NUMBER BETWEEN 1 AND 4!" << endl;
		cin >> bagChoice1;
		cin >> bagChoice2;
	}
if (bagChoice1 == 1)
	{
		firstBag.add(8);
		firstBag.add(15);
		firstBag.add(12);
		firstBag.add(5);
		firstBag.add(9);
	}
else if (bagChoice1 == 2)
	{
		secondBag.add(8);
		secondBag.add(15);
		secondBag.add(12);
		secondBag.add(5);
		secondBag.add(9);
	}
else if (bagChoice1 == 3)
        {
                thirdBag.add(8);
                thirdBag.add(15);
                thirdBag.add(12);
                thirdBag.add(5);
                thirdBag.add(9);
        }
else if (bagChoice1 == 4)
	{
		fourthBag.add(8);
		fourthBag.add(15);
		fourthBag.add(12);
		fourthBag.add(5);
		fourthBag.add(9);
	}
if (bagChoice2 == 1)
	{
		firstBag.add(9);
		firstBag.add(5);
		firstBag.add(9);
		firstBag.add(9);
	}
else if (bagChoice2 == 2)
	{
		secondBag.add(9);
		secondBag.add(5);
		secondBag.add(9);
		secondBag.add(9);
	}
else if (bagChoice2 == 3)
	{
		thirdBag.add(9);
		thirdBag.add(5);
		thirdBag.add(9);
		thirdBag.add(9);
	}
else if (bagChoice2 == 4)
	{
		fourthBag.add(9);
		fourthBag.add(5);
		fourthBag.add(9);
		fourthBag.add(9);
	}

bagsize1 = firstBag.getCurrentSize();
bagsize2 = secondBag.getCurrentSize();
bagsize3 = thirdBag.getCurrentSize();
bagsize4 = fourthBag.getCurrentSize();

cout << "First Bag: " << endl;
firstBag.displayBag(bagsize1);
cout << "Second Bag: " << endl;
secondBag.displayBag(bagsize2);
cout << "Third Bag: " << endl;
thirdBag.displayBag(bagsize3);
cout << "Fourth Bag: " << endl;
fourthBag.displayBag(bagsize4);

if(secondBag.contains(9) == true || secondBag.contains(8) == true)
{
	cout << "The second bag contains " << secondBag.getFrequencyOf(9) << "9's!" << endl;
	cout << "The second bag contains " << secondBag.getFrequencyOf(8) << "8's!" << endl;
}
else
{
	cout << "The second bag does not contain any 8's or 9's!";
}

thirdBag.Union(firstBag);
thirdBag.Union(secondBag);

bagsize1 = firstBag.getCurrentSize();
bagsize2 = secondBag.getCurrentSize();
bagsize3 = thirdBag.getCurrentSize();

cout << "First Bag: " << endl;
firstBag.displayBag(bagsize1);
cout << "Second Bag: " << endl;
secondBag.displayBag(bagsize2);
cout << "Third Bag: " << endl;
thirdBag.displayBag(bagsize3);

if(thirdBag.contains(9) == true || thirdBag.contains(8) == true)
{
	cout << "The third bag contains " << thirdBag.getFrequencyOf(9) << "9's!" << endl;
	cout << "The third bag contains " << thirdBag.getFrequencyOf(8) << "8's!" << endl;
}
else
{
	cout << "The third bag does not contain any 8's or 9's!";
}

if(thirdBag.contains(5) == true)
{
	cout << "The third bag contains " << thirdBag.getFrequencyOf(5) << "5's!" << endl;
}
else
{
	cout << "The third bag does not contain any 5's!";
}

fourthBag.Intersection(firstBag);
fourthBag.Intersection(secondBag);

bagsize1 = firstBag.getCurrentSize();
bagsize2 = secondBag.getCurrentSize();
bagsize4 = fourthBag.getCurrentSize();

cout << "First Bag: " << endl;
firstBag.displayBag(bagsize1);
cout << "Second Bag: " << endl;
secondBag.displayBag(bagsize2);
cout << "Fourth Bag: " << endl;
thirdBag.displayBag(bagsize4);

if(fourthBag.contains(9) == true || fourthBag.contains(8) == true)
{
	cout << "The fourth bag contains " << fourthBag.getFrequencyOf(9) << "9's!" << endl;
	cout << "The fourth bag contains " << fourthBag.getFrequencyOf(8) << "8's!" << endl;
}
else
{
	cout << "The fourth bag does not contain any 8's or 9's!";
}

fourthBag.clear();

cout << "Bag 4 size: " << fourthBag.getCurrentSize() << endl;

system("Pause");
return 0;
}
