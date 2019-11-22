#include "Matrix.h"
#include <iostream>
#include <cctype>

// Constructors
Matrix::Matrix() {
	matrixPtr = nullptr;
}

Matrix::Matrix(int rows, int cols) {
	bool confirmed = false;
	char userChar = ' ';
	int counter = 0;
	int dimArr [2];

	numRows = rows;
	numCols = cols;
	
	// Create Matrix and pointer array pointing to each row
	matrixPtr = new double* [numRows];
	
	// Create pointers for each column 
	for (int i = 0; i < numRows; i++) {
		matrixPtr[i] = new double[numCols];
	}
	do {
		// 2nd+ time entering prompt re-entry of matrix
		if (counter != 0) {
			cout << endl;
			cout << "Please re-enter your matrix" << endl;
			
			// Set new dimensions
			getDimensions(dimArr);
			numRows = dimArr[0];
			numCols = dimArr[1];

			// Create Matrix and pointer array pointing to each row
			
			matrixPtr = new double* [numRows];


			// Create pointers for each column 
			for (int i = 0; i < numRows; i++) {
				matrixPtr[i] = new double[numCols];
			}
		
		}


		// Enter Matrix
		cin >> *this;

		// Confirm Matrix
		cout << *this;
		cout << "Is this the matrix you entered (Y/N)?";
		cin >> userChar;
		if (toupper(userChar) == 'Y') {
			confirmed = true;
		}

		counter++;

	} while (!confirmed);
}

// Initializes all entries in Matrix with initVal
Matrix::Matrix(int rows, int cols, int initVal) {
	numRows = rows;
	numCols = cols;

	// Create Matrix and pointer array pointing to each row
	matrixPtr = new double* [numRows];

	// Create pointers for each column 
	for (int i = 0; i < numCols; i++) {
		matrixPtr[i] = new double[numCols];
	}

	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			matrixPtr[i][j] = initVal;
		}
	}
}

// Overloaded operators
Matrix Matrix::operator+(Matrix addMatrix) {
	if ((this->numCols != addMatrix.numCols) || (this->numRows != addMatrix.numRows)) {
		cout << "Dimension mismatch, addition cannot be performed" << endl;
		// TODO: PREVENT PRINTING IN THIS CASE
	} else {
		for (int i = 0; i < this->numRows; i++) {
			for (int j = 0; j < this->numCols; j++) {
				this->matrixPtr[i][j] += addMatrix.matrixPtr[i][j];
			}
		}
	}

	return *this;
}

Matrix Matrix::operator-(Matrix subtractMatrix) {
	if ((this->numCols != subtractMatrix.numCols) || (this->numRows != subtractMatrix.numRows)) {
		cout << "Dimension mismatch, addition cannot be performed" << endl;
	}
	else {
		for (int i = 0; i < this->numRows; i++) {
			for (int j = 0; j < this->numCols; j++) {
				this->matrixPtr[i][j] -= subtractMatrix.matrixPtr[i][j];
			}
		}
	}

	return *this;
}

// Dot product multiplication
Matrix Matrix::operator*(Matrix multMatrix) {
	// Create a storage matrix of all 0's
	Matrix* returnPtr = nullptr;
	
	// Check dimensions
	if (this->numCols != multMatrix.numRows) {
		cout << "Dimenstion mismatch, Multiplication cannot be performed";
		return *returnPtr;
	} else {
		// Holding pointer for the matrix
		returnPtr = new Matrix(this->numRows, multMatrix.numCols, 0);
		int rowIterator = 0;
		for (int i = 0; i < this->numRows; i++) {
			for (int j = 0; j < multMatrix.numCols; j++) {
				for (int k = 0; k < this->numCols; k++) {
					returnPtr->matrixPtr[i][j] += this->matrixPtr[i][k] * multMatrix.matrixPtr[k][j];
				}
			}
		}
	}

	return *returnPtr;
}

ostream& operator<<(ostream& output, Matrix matrix) {
	for (int i = 0; i < matrix.numRows; i++) {
		cout << "| ";
		for (int j = 0; j < matrix.numCols; j++) {
			output << matrix.matrixPtr[i][j] << " ";
		}
		cout << "|";
		cout << endl;
	}

	return output;
}

istream& operator>>(istream& input, Matrix myMatrix) {
	double tempDouble;

	// Populate the matrix (TODO: figure out how to unnest these loops
	for (int i = 0; i < myMatrix.numRows; i++) {
		for (int j = 0; j < myMatrix.numCols; j++) {
			// TODO: VALIDATE TEMP DOUBLE
			cout << "Enter the value for Row " << (i + 1) << ", Column " << (j + 1) << ": ";
			input >> tempDouble;
			myMatrix.matrixPtr[i][j] = tempDouble;
		}
	}

	return input;
}


// Static Matrix operations

// First dimension is row, Second is col;
void Matrix::getDimensions(int dimensions[]) {
	const int MIN_ROWS = 1;
	const int MAX_ROWS = 10;

	// Get rows
	cout << "Enter the number of rows in the Matrix: ";
	dimensions[0] = validateInt(MIN_ROWS, MAX_ROWS, true);

	// Get cols
	cout << "Enter the number of columns in the Matrix: ";
	dimensions[1] = validateInt(MIN_ROWS, MAX_ROWS, true);
}

// Returns identity matrix of correct size (nxn)
Matrix Matrix::getIdentityMatrix(int numRows) {
	// Create a matrix of all 0's
	Matrix * identity = new Matrix(numRows, numRows, 0);

	// Add the 1's on the diagonal
	for (int i = 0; i < numRows; i++) {
		identity->matrixPtr[i][i] = 1;
	}

	return *identity;
}

// Validates integer based input between an upper and lower bound
int Matrix::validateInt(int lowerBound, int upperBound, bool inclusive) {
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

Matrix Matrix::addB() {
	cout << "Enter B: " << endl;

	// Create b
	Matrix* b = new Matrix(numRows, 1);
	cin >> *b;

	// resize matrix to hold b
	double* tempArr = new double[numCols + 1];

	// loop through the matrix and add b on each end
	for (int i = 0; i < this->numRows; i++) {
		for (int j = 0; j < this->numCols + 1; j++) {
			// Add b
			if (j == this->numCols) {
				tempArr[j] = b->matrixPtr[i][0];
			}
			else {
				tempArr[j] = this->matrixPtr[i][j];
			}
		}
	}


	cout << *this;

	return *this;
}


/* Advanced Matrix Operations
*  
*  
*
*/
Matrix Matrix::transpose() {
	double tempDouble;
	double** tempPtr = new double* [numCols];

	// Set columns to rows rows to columns
	for (int i = 0; i < numCols; i++) {
		tempPtr[i] = new double[numRows];
	}

	// copy values
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			tempPtr[j][i] = this->matrixPtr[i][j];
		}
	}

	// Swap num rows and cols
	tempDouble = numRows;
	numRows = numCols;
	numCols = tempDouble;

	// Deallocate matrixPtr
	for (int i = 0; i < numRows; i++) {
		delete[] this->matrixPtr[i];
	}

	matrixPtr = tempPtr;

	return *this;
}

Matrix Matrix::eliminateRow(int rowOne, int rowTwo) {
	return eliminateRow(rowOne, rowTwo, true);
}

// TODO: WORK ON ROW FACTORS (ESP IN BOTTOM ROW, figure out non 2x2 cases)
// Performs LU Decomposition in upper triangular
Matrix Matrix::eliminateRow(int rowOne, int rowTwo, bool allowNegativePivots) {
	double pivot;			// holds pivot
	int pivotIndex;			// local var for holding pivot index
	double pivotFactor;		// Elim factor
	double inverseFactor;	// Holds inverse

	pivot = this->matrixPtr[rowOne][rowOne];
	pivotIndex = rowOne;

	// No elimination neccessary if 0 is the pivot or it is the last row
	if (pivot == 0 || pivotIndex == (this->numRows - 1)) {
		return *this;
	}
	else {
		// Otherwise calcualte the pivot factor
		pivotFactor = ((double)this->matrixPtr[rowTwo][pivotIndex]) / (this->matrixPtr[rowOne][pivotIndex]);
	}

	// Do the elimination on the row
	for (int col = pivotIndex; col < this->numCols; col++) {
		this->matrixPtr[rowTwo][col] -= (this->matrixPtr[rowOne][col] * (pivotFactor));
	}

	// Normalize rowOne to pivot == 1
	if (!allowNegativePivots) {
		pivotFactor = (1 / pivot);
		for (int col = pivotIndex; col < this->numCols; col++) {
			this->matrixPtr[rowOne][col] *= pivotFactor;
		}
	} else if (pivot != 1 && pivot != -1) {
		pivotFactor = (1 / pivot);
		for (int col = pivotIndex; col < this->numCols; col++) {
			this->matrixPtr[rowOne][col] *= pivotFactor;
		}
	}


	return *this;
}

// Row Permutation
Matrix Matrix::permutate(int rowOne, int rowTwo) {
	double * tempRow;
	
	tempRow = this->matrixPtr[rowOne];
	this->matrixPtr[rowOne] = this->matrixPtr[rowTwo];
	this->matrixPtr[rowTwo] = tempRow;

	return *this;
}

// LU Decomp (TODO: IMPLEMENT PERMUTATION)
Matrix Matrix::getUpperTriangular() {
	cout << "U: " << endl;
	// Eliminate every set of rows 
	for (int i = 0; i < this->numRows; i++) {
		for (int j = i + 1; j < this->numRows; j++) {
			*this = eliminateRow(i, j);
		}
	}

	return *this;
}

double Matrix::getDeterminant() {
	int determinant = 1;		// 1 is chosen due to multiplicative identity of 1
	
	// Check dimensions
	if (this->numCols != this->numRows) {
		cout << "There is no determinant";
		return NULL;
	}
	
	// Copy Matrix (TODO: USE MOVE SEMANTICS)
	Matrix* tempMatrix = this;

	// Multiply pivots after upper triangulation
	tempMatrix->getUpperTriangular();

	for (int i = 0; i < this->numRows; i++) {
		determinant *= this->matrixPtr[i][i];
	}

	return determinant;
}

// TODO: IMPLEMENT MOVE SEMANTICS
Matrix Matrix::getLowerTriangular() {
	// Create matrix of all 0's
	cout << "L: " << endl;
	Matrix* lowerTriangular = new Matrix(this->numRows, this->numCols, 0);
	
	for (int i = 0; i < this->numRows; i++) {
		for (int j = i + 1; j < this -> numCols; j++) {
			lowerTriangular->matrixPtr[j][i] = this->getPivotFactor(i, j);
			
			this->eliminateRow(i, j);
		}
		// j == i (1 on pivot)
		lowerTriangular->matrixPtr[i][i] = 1;
	}

	return *lowerTriangular;
}

double Matrix::getPivotFactor(int rowOne, int rowTwo) {
	double pivot;			// holds pivot
	int pivotIndex;			// local var for holding pivot index
	double pivotFactor;		// Elim factor
	double inverseFactor;	// Holds inverse

	pivot = this->matrixPtr[rowOne][rowOne];
	pivotIndex = rowOne;

	// No elimination neccessary if 0 is the pivot or it is the last row
	if (pivot == 0 || pivotIndex == (this->numRows - 1)) {
		return 0;
	}

	else {
		// Otherwise calculate the pivot factor
		pivotFactor = ((double)this->matrixPtr[rowTwo][pivotIndex]) / (this->matrixPtr[rowOne][pivotIndex]);
		return pivotFactor;
	}
}

bool Matrix::isSingular() {
	return (this->getDeterminant() == 0);
}