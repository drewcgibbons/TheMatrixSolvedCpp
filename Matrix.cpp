#include "Matrix.h"

Matrix::Matrix(int rows, int cols) {
	numRows = rows;
	numCols = cols;

	// Create Matrix
	int** rowPtr = new int *[numRows];
	for (int i = 0; i < numCols; i++) {
		rowPtr[i] = new int[numCols];
	}


}
