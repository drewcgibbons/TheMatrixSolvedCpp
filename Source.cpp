#include <iostream>
#include <cctype>
#include <string>
#include "Matrix.h"

using namespace std;

// Declarations
void showMenu();
void showElementaryMenu();
int validate(int, int, bool);
void showLUDecompMenu();

int main (){
	showMenu();
	return 0;
}

void showMenu() {
	int switchKey;
	const int firstChoice = 1;
	const int finalChoice = 3;

	
	do {
		// Menu Options
		cout << "Select from the following options" << endl;
		cout << "1.) Elementary Matrix Operations" << endl;
		cout << "2.) LU Decomposition" << endl;
		cout << "3.) Exit" << endl;

		// Validate Switch Key
		switchKey = validate(firstChoice, finalChoice, true);

		// Operation Selection
		switch (switchKey) {
		case 1:
			showElementaryMenu();
			break;
		case 2:
			showLUDecompMenu();
			cout << "2";
			break;
		case 3:
			cout << "3";
			break;
		}
	} while (switchKey != 3);

}


void showElementaryMenu() {
	int menuKey;
	const int firstChoice = 1;
	const int finalChoice = 3;

	// Menu options
	cout << "Select from the following options" << endl;
	cout << "1.) Matrix Addition" << endl;
	cout << "2.) Matrix Subtraction" << endl;
	cout << "3.) Matrix Multiplication" << endl;

	menuKey = validate(firstChoice, finalChoice, true);

	// Switch menu
	switch (menuKey) {
	case 1:
		cout << "Add" << endl;
		break;
	case 2:
		cout << "Subtract" << endl;
		break;
	case 3:
		cout << "Multiply" << endl;
		break;

	}
}

void showLUDecompMenu() {
	cout << "LUDecompMenu";
	return;
}

int validate(int lowerBound, int upperBound, bool inclusive) {
	string numString;
	int num;
	bool validInput = false;


	while (!validInput) {
		// Read in num as string
		cin >> numString;
		int stringLength = numString.length();
		
		// Validate Integer
		while (!(isdigit(numString[0])) && (stringLength != 1)) {
			cout << "Please enter an integer" << endl;
			cin >> numString;
		}
		
		// Convert String to int
		char numCharArr[1];
		numCharArr[0] = numString[0];
		num = atoi(numCharArr);

		// Range Check
		if (inclusive) {
			while (num > upperBound || num < lowerBound) {
				cout << "Input out of bounds. Please enter a number (inclusive) between " << upperBound << " and " << lowerBound << endl;
				cin >> num;
			}
			validInput = true;
		}
		else {
			while (num >= upperBound || num <= lowerBound) {
				cout << "Input out of bounds. Please enter a number (inclusive) between " << upperBound << " and " << lowerBound << endl;
				cin >> num;
			}
			validInput = true;
		}
	}

	return num;

}