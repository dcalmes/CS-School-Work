///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Program:		Porgram 2
// Purpose:     This programs purpose is to find, add, and display student information using a structure array
// Input:       The input file of this program is prog2.txt.  User inputs the student they want to find, add, or modify
// Processing:  This program will add a student to the student list.  It was  check to make sure there is room in the
//				array before doing so.  It will also update student information if a student has been found using the find
//				student function.  In addition it will be able to display all the information about all of the students in
//				the array.
// Output:      This program outputs wither a student is found.  Outputs the students information.  Also error codes if
//				something was incorrectly input.
// Programmer:  Douglas Calmes
// Class:       CS 2020 Spring 2016
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream> 
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// Student Structure
struct Student
{
	int id;
	string name;
	string zip;
	double balance;
	string lastPay;
};

// Prototypes
void addStud(Student[], int, int &);
void updateStud(Student[], int, int);
void displayStud(Student[], int);
int findStud(Student[], int, int);
int menu();

// Max elements
const int MAXSTUD = 30;


int main()
{
	Student studentList[MAXSTUD];

	int choice;
	int search_ID;
	int num=0;
	int findID;
	ifstream inputFile;

	// Menu
	choice = menu();

	// Open inputfile and input data into structure array
	inputFile.open("prog2.txt");

	if (inputFile)
	{
		while (num < MAXSTUD)
		{
			inputFile >> studentList[num].id;
			inputFile.ignore();
			getline(inputFile, studentList[num].name);
			inputFile >> studentList[num].zip;
			inputFile >> studentList[num].balance;
			inputFile.ignore();
			getline(inputFile, studentList[num].lastPay);
			num++;
		}
		inputFile.close();
	}
	else
	{
		cout << "ERROR: File not found" << endl;
	}



	// Repeat menu until user inputs 5
	do
	{
		if (choice == 1)
		{
			cout << "ID: ";
			cin.ignore();
			cin >> search_ID;

			findID = findStud(studentList, search_ID, MAXSTUD);

			if (findID = -1 && num < MAXSTUD)
			{
				addStud(studentList, MAXSTUD, num);	
			}
			else
			{
				cout << "Student cannot be added" << endl;
			}
			
			choice =menu();
		}

		else if (choice == 2)
		{
			cout << "ID: ";
			cin.ignore();
			cin >> search_ID;

			findID = findStud(studentList, search_ID, MAXSTUD);

			if (findID != -1)
			{
				updateStud(studentList, MAXSTUD, findID);
			}
			else
			{
				cout << "Student not found" << endl;
			}

			choice = menu();
		}

		else if (choice == 3)
		{
			displayStud(studentList, num);

			choice = menu();
		}

		else if (choice == 4)
		{
			cout << "ID: ";
			cin.ignore();
			cin >> search_ID;

			findID = findStud(studentList, search_ID, MAXSTUD);

			if (findID != -1)
			{
				cout << "Student found" << endl;
			}
			else
			{
				cout << "Student not found" << endl;
			}

			choice = menu();
		}

		//	Tell user the error was invalid
		else if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
		{
			cout << "ERROR: Option invalid.  Please Re-Enter" << endl;
			cout << endl;
			choice = menu();
		}
	} while (choice != 5);

	return 0;

	}

	//////////////////////////////////////////////////////////////////////////////
	// Program			2                                                                                                                                                                                                                                          /      
	// Programmer:		Douglas Calmes                                                                                   
	// Class:           CS 2020, Spring 2016                                     
	//                                                                           
	// Function:        menu                                                   
	// Description:     This function displays the menu.  It asks user to input choice
	// Parameters:      None
	// Returns:         choice- The menu choice the user inputs            
	//////////////////////////////////////////////////////////////////////////////
int menu()
{
	int choice = 0;

	// Display menu
	cout << right << setw(30) << "Menu of Choices" << endl;
	cout << "-------------------------------------" << endl;
	cout << "1. Enter new account information" << endl;
	cout << "2. Change account information" << endl;
	cout << "3. Display all account information" << endl;
	cout << "4. Find student" << endl;
	cout << "5. Exit program" << endl;

	cout << "Choice? ";
	cin >> choice;


	return choice;
}

//////////////////////////////////////////////////////////////////////////////
// Program			2                                                                                                                                                                                                                                            /      
// Programmer:		Douglas Calmes                                                                                   
// Class:           CS 2020, Spring 2016                                     
//                                                                           
// Function:        addStud                                                   
// Description:     This function asks user to input information about the 
//					student they would like to add to the structure array
// Parameters:      studentList[]- Student array
//					MAXSTUD- The maximum number of students
//					num- increase the number of students and add info
// Returns:         Nothing              
//////////////////////////////////////////////////////////////////////////////

void addStud(Student studentList[], int MAXSTUD, int & num)
{
	double newBalance;
	 num++;

	// Add information for a new student
	cout << "New ID: ";
	cin >> studentList[num].id;

	cout << "Name: ";
	cin.ignore();
	getline(cin, studentList[num].name);

	cout << "ZIP Code: ";
	cin >> studentList[num].zip;

	cout << "Account Balance: ";
	cin >> newBalance;

	while (newBalance < 0)
	{
		// Alert if student balance is below 0, ask again.
		cout << "ERROR:  Acount cannot be below 0.  What is the Account Balance? " << endl;
		cin >> newBalance;
	}

	studentList[num].balance = newBalance;

	cout << "Last Payment: ";
	cin.ignore();
	getline(cin, studentList[num].lastPay);

}

//////////////////////////////////////////////////////////////////////////////
// Program			2                                                                                                                                                                                                                                           /      
// Programmer:		Douglas Calmes                                                                                   
// Class:           CS 2020, Spring 2016                                     
//                                                                           
// Function:        updateStud                                                   
// Description:     This function updates the student information that the 
//					user wants (if found).
// Parameters:      studentList[]- Student array
//					MAXSTUD- The maximum number of students
//					findID- The ID of the student you are updating
// Returns:         Nothing              
//////////////////////////////////////////////////////////////////////////////

void updateStud(Student studentList[], int MAXSTUD, int findID)
{
	cout << "Update information:" << endl;

	cout << "Name: " << endl;
	cin.ignore();
	getline(cin, studentList[findID].name);

	cout << "ZIP Code: " << endl;
	cin >> studentList[findID].zip;

	cout << "Account Balance: " << endl;
	cin >> studentList[findID].balance;

	cout << "Date of last Payment" << endl;
	cin.ignore();
	getline(cin, studentList[findID].lastPay);
}

//////////////////////////////////////////////////////////////////////////////
// Program 2                                                                                                                                                                                                                                            /      
// Programmer:		Douglas Calmes                                                                                   
// Class:           CS 2020, Spring 2016                                     
//                                                                           
// Function:        displayStud                                                   
// Description:     This function uses a for loop to display the information
//					of all the students in the array
// Parameters:      studentList[]- Student array
//					num- The number of students in the array
// Returns:         Nothing              
//////////////////////////////////////////////////////////////////////////////

void displayStud(Student studentList[], int num)
{
	// Display the information of the students using a for loop
	cout << "Student List" << endl;
	cout << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "ZIP" << setw(10) << "Balance" << setw(10) << "Last Payment" << endl;
	cout << "----------------------------------------------------------------------" << endl;

	for (int i = 0; i < num; i++)
	{
		cout << setw(10) << studentList[i].id << setw(20) << studentList[i].name << setw(10) << studentList[i].zip << setw(10) << studentList[i].balance << setw(10) << studentList[i].lastPay << endl;
	}
}

//////////////////////////////////////////////////////////////////////////////
// Program 2                                                                                                                                                                                                                                            /      
// Programmer:		Douglas Calmes                                                                                   
// Class:           CS 2020, Spring 2016                                     
//                                                                           
// Function:        findStud                                                   
// Description:     This function uses the input of search_ID in the main in
//					order to find if the student exists in the array.  If it 
//					does it will return the student ID, if not it will return -1
// Parameters:      studentList[]- Student array
//					MAXSTUD- The maximum number of students
//					search_ID- The student ID input in the main
// Returns:         position if student is found
//					-1 if student was not found
//////////////////////////////////////////////////////////////////////////////

int findStud(Student studentList[], int search_ID, int MAXSTUD)
{
	int i = 0;
	int position = -1;
	bool isFound = false;

	//	While loop until the student ID is found.  Return the position of student.
	//	Returns -1 if student was not found.
	while (i < MAXSTUD && !isFound)
	{
		if (studentList[i].id == search_ID)
		{
			isFound = true;
			position = i;
		}
		i++;
	}
	return position;
}
