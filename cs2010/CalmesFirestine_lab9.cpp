#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void checkAgeTime(int &, int &);
void convertTime(int &, int &, int);

int main()
{
	ifstream fileName;
	fileName.open("lab9.txt");
	string name;
	int age, time;
	int minutes, seconds;

	if (!fileName)
	{
		cout << "File is not correctly opened.";
	}
	else
	{
		cout << "File is correctly opened." << endl;
	}


	cout << setw(10) << "Name" << setw(10) << "Age" << setw(10) << "Time" << setw(20) << "Time (min/sec)" << endl;
	cout << "--------------------------------------------------" << endl;

	while (!fileName.eof())
	{
		fileName >> name >> age >> time;

		if (time < age)
		{
			checkAgeTime(age, time);
		}

		convertTime(minutes, seconds, time);

		cout << setw(10) << name << setw(10) << age << setw(10) << time << setw(10) << minutes << ":" << setfill('0') << setw(2) << seconds << setw(1) << setfill(' ') << endl;

	}




	system("pause");
	return 0;
}

void checkAgeTime(int &age, int &time)
{
	int x;
	x = age;
	age = time;
	time = x;

}

void convertTime(int &minutes, int &seconds, int time)
{
	minutes = time / 60;
	seconds = time % 60;
}