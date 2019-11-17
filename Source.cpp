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

// Shows the Main Menu
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

// Shows the Menu for elementary matrix operation
void showElementaryMenu() {
	int menuKey;
	const int firstChoice = 1;
	const int finalChoice = 3;

	Matrix a;
	Matrix b;


	// Menu options
	cout << "Select from the following options" << endl;
	cout << "1.) Matrix Addition" << endl;
	cout << "2.) Matrix Subtraction" << endl;
	cout << "3.) Matrix Multiplication" << endl;

	menuKey = validate(firstChoice, finalChoice, true);

	// Switch menu
	switch (menuKey) {
	case 1:
		// getMatrix();
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

// Shows the LU Decomp menu
void showLUDecompMenu() {
	cout << "LUDecompMenu";
	return;
}

// Validates integer based input between an upper and lower bound
int validate(int lowerBound, int upperBound, bool inclusive) {
	string numString;
	int num;
	bool validInput = false;
	bool isInteger = false;


	while (!validInput) {
		// Read in num as string
		cin >> numString;
		int stringLength = numString.length();
		
		// Validate all digit input
		for (int i = 0; i < stringLength; i++) {
			if (!isdigit(numString[i])) {
				isInteger = false;
				break;
			}
			isInteger = true;
		}

		// Validate Integer
		while (!isInteger) {
			cout << "Please enter an integer" << endl;
			cin >> numString;

			for (int i = 0; i < stringLength; i++) {
				if (!isdigit(numString[i])) {
					break;
				}
				isInteger = true;
			}
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