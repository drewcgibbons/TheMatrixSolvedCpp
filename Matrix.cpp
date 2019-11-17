#include "Matrix.h"

Matrix::Matrix() {
	matrixPtr = nullptr;
}

Matrix::Matrix(int rows, int cols) {
	numRows = rows;
	numCols = cols;

	// Create Matrix and pointer array pointing to each row
	matrixPtr = new double *[numRows];
	
	// Create pointers for each column 
	for (int i = 0; i < numCols; i++) {
		matrixPtr[i] = new double[numCols];
	}
	
	cin >> *this;

}

// Overloaded operators
Matrix Matrix::operator+(Matrix addMatrix) {
	return *this;
}

Matrix Matrix::operator-(Matrix subtractMatrix) {
	return *this;
}

ostream& operator<<(ostream& output, Matrix matrix) {
	for (int i = 0; i < matrix.numRows; i++) {
		for (int j = 0; j < matrix.numCols; j++) {
			output << matrix.matrixPtr[i][j] << " " << endl;
		}
		cout << endl;
	}

	return output;
}

istream& operator>>(istream& input, Matrix myMatrix) {
	// Temp holding array
	double* holdArray = new double[myMatrix.numRows * myMatrix.numCols];

	// populate holding array
	for (int i = 0; i < (myMatrix.numRows * myMatrix.numCols); i++) {
		input >> holdArray[i];
	}

	int k = 0;	// Holding array index

	// Populate the matrix (TODO: figure out how to unnest these loops
	for (int i = 0; i < myMatrix.numRows; i++) {
		for (int j = 0; j < myMatrix.numCols; j++, k++) {
			myMatrix.matrixPtr[i][j] = holdArray[k];
		}
	}

	return input;
}


// Matrix operations
Matrix Matrix::transpose() {
	return *this;
}
