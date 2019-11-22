#pragma once
#include <iostream>
using namespace std;

class 
Matrix {
	private:
		// Members
		int numRows = 1;
		int numCols = 1;
		double** matrixPtr;

	protected:
		// Functions
		Matrix eliminateRow(int, int);
		Matrix eliminateRow(int, int, bool);
		Matrix permutate(int, int);
		double getPivotFactor(int, int);

		bool isSingular();

	public:
		// Constructors & Destructor
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
		static Matrix getIdentityMatrix(int);

		// Basic functions
		Matrix transpose();
		Matrix getUpperTriangular();
		double getDeterminant();
		Matrix getLowerTriangular();
		Matrix addB();

};