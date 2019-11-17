#include "Matrix.h"

// Constructors
Matrix::Matrix() {
	matrixPtr = nullptr;
}

Matrix::Matrix(int rows, int cols) {
	numRows = rows;
	numCols = cols;

	// Create Matrix and pointer array pointing to each row
	matrixPtr = new double *[numRows];
	
	// Create pointers for each column 
	for (int i = 0; i < numRows; i++) {
		matrixPtr[i] = new double[numCols];
	}
	
	cin >> *this;
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


// Matrix operations

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
