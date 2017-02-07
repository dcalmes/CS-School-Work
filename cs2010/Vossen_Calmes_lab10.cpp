/*
 Description	:	 Lab 10 - GCD
 Author			:	 Wiebe Vossen and Douglas Calmes
 Date			:	 11/04/2015
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int RNG();
int GCD(int, int);

int main()
{
	int c1, c2, c3, c4, c5;
	srand(time(NULL));
	c1 = RNG();
	c2 = RNG();
	c3 = RNG();
	c4 = RNG();
	c5 = RNG();
	int rows;
	cout << "How many rows do you want in the table? ";
	cin >> rows;
	cout << endl;
	cout << "GCD  |\t" << c1 << "\t" << c2 << "\t" << c3 << "\t" << c4 << "\t" << c5 << endl;
	cout << "-------------------------------------------" << endl;
	for (int i = 0; i < rows; i++)
	{
		int row_random = RNG();
		int c1_gcd = GCD(row_random, c1);
		int c2_gcd = GCD(row_random, c2);
		int c3_gcd = GCD(row_random, c3);
		int c4_gcd = GCD(row_random, c4);
		int c5_gcd = GCD(row_random, c5);
		cout << row_random<<"  |"<<"\t" << c1_gcd << "\t" <<c2_gcd<<"\t" <<c3_gcd<<"\t"<<c4_gcd<<"\t"<<c5_gcd<< endl;
	}

	system("pause");
	return 0;
}

int RNG()
{
	return rand() % 400 + 101;
}

int GCD(int x, int y)
{
	if (x%y == 0)
		return y;
	else
		return GCD(y, x%y);
}