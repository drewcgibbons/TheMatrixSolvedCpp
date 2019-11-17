#pragma once
#include <iostream>
using namespace std;

class Matrix {
	private:
		int numRows = 1;
		int numCols = 1;
		double** matrixPtr;

	public:
		// Constructors
		Matrix();
		Matrix(int, int);

		// Overloaded operators
		Matrix operator+(Matrix);
		Matrix operator-(Matrix);
		friend ostream& operator<<(ostream&, Matrix);
		friend istream& operator>>(istream&, Matrix);

		// Basic functions
		Matrix transpose();
	



};

