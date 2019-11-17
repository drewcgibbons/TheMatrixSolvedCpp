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
		Matrix(int, int, int);

		// Overloaded operators
		Matrix operator+(Matrix);
		Matrix operator-(Matrix);
		Matrix operator*(Matrix);
		friend ostream& operator<<(ostream&, Matrix);
		friend istream& operator>>(istream&, Matrix);

		// Static functions
		static void getDimensions(int dimensions[]);
		static int validateInt(int, int, bool);

		// Basic functions
		Matrix transpose();
	



};

