//	Douglas G Calmes	CS3350	6 - 7:20 PM
//	Program 4
//	Purpose:	The purpose of this program is to show and learn the process of using a stack and using its operations (push, pop, peek)

#include <iostream>
#include <string>
#include <cctype>
#include "lib/ArrayStack.h"
using namespace std;

// Prototype Functions
double getResult(string postFix);
double evaluateExpression(char operation, double firstOperand, double secondOperand);
bool checkOperand(char C);
bool checkDigit(char C);

int main(){
	string postFix;

	cout << "Please Enter a Post Fix Expression" << endl;
	
	while (postFix[0] != 'q') {
		cout << "Please Enter a Post Fix Expression" << endl;
		getline(cin, postFix);
		double result = getResult(postFix);
		cout << "Output : " << result << endl;
	}
}

//	This function will generate the expression result
double getResult(string postFix) {
	ArrayStack <double> Stack;
	
	for (int i = 0; i < postFix.length(); i++) {
		if (postFix[i] == ' ' || postFix[i] == ',') continue;

		else if (checkOperand(postFix[i])){
			double secondOperand = Stack.peek(); Stack.pop();
			double firstOperand = Stack.peek(); Stack.pop();
			double result = evaluateExpression(postFix[i], firstOperand, secondOperand);
			Stack.push(result);
		}

		else if (checkDigit(postFix[i])) {
			double operand = 0;
			while (i < postFix.length() && checkDigit(postFix[i])) {
				operand = (operand * 10) + (postFix[i] - '0');
				i++;
				Stack.push(operand);
			}
		}
		if (postFix.length() == 1 || postFix.length() == 2) {
			cout << "This expression is too short of an expression. INVALID ENTRY!" << endl;
		}
		else if (checkDigit(postFix[i]) == false && checkOperand(postFix[i] == false)) {
			cout << postFix[i] << "isn't a valid symbol." << endl;
			return 0;
		}
	}
	return Stack.peek();
}

//	This function will do all the work to prepare the expression for its results
double evaluateExpression(char operation, double firstOperand, double secondOperand) {
	if (operation == '+') {
		return firstOperand + secondOperand;
	}
	else if (operation == '-') {
		return firstOperand - secondOperand;
	}
	else if (operation == '*') {
		return firstOperand * secondOperand;
	}
	else if (operation == '/') {
		return firstOperand / secondOperand;
	}
	else cout << "ERROR!" << endl;
	return -1;
}

//	This function will check to see if C is a valid operator
bool checkOperand(char C) {
	if (C == '+' || C == '-' || C == '*' || C == '/') {
		return true;
	}
	return false;
}

//	This function will check to see if C is a valid digit
bool checkDigit(char C) {
	if (C >= '0' && C <= '9') {
		return true;
	}
	return false;
}





