#pragma once
class Matrix {
	private:
		int numRows = 1;
		int numCols = 1;
		int x[];
	public:
		// Constructors
		Matrix(int, int);

		// Overloaded operators
		Matrix operator+(Matrix);
		Matrix operator-(Matrix);
		
		// Basic functions
		Matrix transpose();


};

