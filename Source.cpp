#include <iostream>
#include <cctype>
#include <string>
#include "Matrix.h"

using namespace std;

// Declarations
void showMenu();
void showElementaryMenu();
int validate(int, int, bool);

int main (){
	showMenu();
	return 0;
}

// Shows the Main Menu
void showMenu() {
	// Local vars
	int switchKey;

	// For num choices
	const int firstChoice = 1;
	const int finalChoice = 5;

	// Holds matrix
	Matrix* mPtrOne = nullptr;

	// Holds matrix dimensions
	int dimensionsArr[2];

	
	do {
		// Menu Options
		cout << "Select from the following options" << endl;
		cout << "1.) Elementary Matrix Operations" << endl;
		cout << "2.) Upper Triangular" << endl;
		cout << "3.) LU Decomposition" << endl;
		cout << "4.) Solve AX=b" << endl;
		cout << "5.) Exit" << endl;

		// Validate Switch Key
		switchKey = validate(firstChoice, finalChoice, true);

		// Operation Selection
		switch (switchKey) {
		case 1:
			showElementaryMenu();
			break;
		case 2:
			 // Upper Trinagular only
			// Get dimensions for and create matrix
				cout << "Matrix One: " << endl;
				Matrix::getDimensions(dimensionsArr);
				mPtrOne = new Matrix(dimensionsArr[0], dimensionsArr[1]);
			cout << mPtrOne->getUpperTriangular();
			break;
		case 3:
			// Lower and upper
			cout << "Matrix One: " << endl;
			Matrix::getDimensions(dimensionsArr);
			mPtrOne = new Matrix(dimensionsArr[0], dimensionsArr[1]);
			cout << mPtrOne->getLowerTriangular();
			cout << mPtrOne->getUpperTriangular();
			break;
		case 4:
			cout << "Enter A: " << endl;
			Matrix::getDimensions(dimensionsArr);
			mPtrOne = new Matrix(dimensionsArr[0], dimensionsArr[1]);
			cout << mPtrOne->addB();
		case 5:
			break;
		}
	} while (switchKey != finalChoice);

	cout << endl << endl;
	cout << "Exiting" << endl;

}

// Shows the Menu for elementary matrix operation
void showElementaryMenu() {
	// Local vars
	int menuKey;				// Key that controls menu selections
	int dimensionsArr[2];		// Array for dimensions, 1st is rows, 2nd is cols
	const int firstChoice = 1;	// Number of choices min
	const int finalChoice = 5;  // Number of choices max
	Matrix* mPtrOne = nullptr;	// Pointer for first matrix
	Matrix* mPtrTwo = nullptr;  // Pointer for second matrix

	// Menu options
	cout << "Select from the following options" << endl;
	cout << "1.) Matrix Addition" << endl;
	cout << "2.) Matrix Subtraction" << endl;
	cout << "3.) Matrix Multiplication" << endl;
	cout << "4.) Matrix Transposition" << endl;
	cout << "5.) Matrix Determinant" << endl;
	cout << "6.) Return to Main Menu" << endl;

	menuKey = validate(firstChoice, finalChoice, true);

	// Switch menu
	switch (menuKey) {
	case 1:
		// Get dimensions for and create matrix a
		cout << "Matrix One: " << endl;
		Matrix::getDimensions(dimensionsArr);
		mPtrOne = new Matrix(dimensionsArr[0], dimensionsArr[1]);

		// Get dimension for and create matrix b
		cout << "Matrix Two: " << endl;
		Matrix::getDimensions(dimensionsArr);
		mPtrTwo = new Matrix(dimensionsArr[0], dimensionsArr[1]);

		cout << (*mPtrOne + *mPtrTwo) << endl;
		break;
	case 2:
		// Get dimensions for and create matrix a
		Matrix::getDimensions(dimensionsArr);
		mPtrOne = new Matrix(dimensionsArr[0], dimensionsArr[1]);

		// Get dimension for and create matrix b
		Matrix::getDimensions(dimensionsArr);
		mPtrTwo = new Matrix(dimensionsArr[0], dimensionsArr[1]);

		cout << (*mPtrOne - *mPtrTwo) << endl;
		cout << "Subtract" << endl;
		break;
	case 3:
		// Get dimensions for and create matrix a
		Matrix::getDimensions(dimensionsArr);
		mPtrOne = new Matrix(dimensionsArr[0], dimensionsArr[1]);

		// Get dimension for and create matrix b
		Matrix::getDimensions(dimensionsArr);
		mPtrTwo = new Matrix(dimensionsArr[0], dimensionsArr[1]);

		cout << (*mPtrOne * *mPtrTwo) << endl;
		break;
	case 4:
		// Get dimensions for and create matrix a
		cout << "Matrix: " << endl;
		Matrix::getDimensions(dimensionsArr);
		mPtrOne = new Matrix(dimensionsArr[0], dimensionsArr[1]);

		cout << mPtrOne->transpose();
		break;
	case 5:
		Matrix::getDimensions(dimensionsArr);
		mPtrOne = new Matrix(dimensionsArr[0], dimensionsArr[1]);
		
		// Check dimensions
		if (dimensionsArr[0] == dimensionsArr[1]) {
		cout << "Deterimant is: " << mPtrOne->getDeterminant();
		} else {
			cout << "There is no determinant" << endl;
		}
		break;
	case 6:
		break;
	}
	

	cout << endl << endl;

	// Deallocate memory
	delete mPtrOne;
	delete mPtrTwo;
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
				cout << "Input out of bounds. Please enter a number (inclusive) between " << lowerBound << " and " << upperBound << endl;
				cin >> num;
			}
			validInput = true;
		}
		else {
			while (num >= upperBound || num <= lowerBound) {
				cout << "Input out of bounds. Please enter a number (inclusive) between " << lowerBound << " and " << upperBound << endl;
				cin >> num;
			}
			validInput = true;
		}
	}

	return num;

}