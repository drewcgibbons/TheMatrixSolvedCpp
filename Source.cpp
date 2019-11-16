#include <iostream>

using namespace std;

// Declarations
void showMenu();
void showElementaryMenu();

int main (){
	showMenu();
	return 0;
}

void showMenu() {
	int switchKey;
	// Menu options
	cout << "Select from the following options" << endl;
	cout << "1.) Elementary Matrix Operations" << endl;
	cout << "2.) LU Decomposition" << endl;

	switch (switchKey) {
	case 1:
		showElementaryMenu();
		break;
	case 2:
		cout << "2";
		break;
	case 3:
		cout << "3";
		break;
	}
}


void showElemenatryMenu() {
	int menuKey;

	// Menu options
	cout << "Select from the following options" << endl;
	cout << "1.) Matrix Addition" << endl;
	cout << "2.) Matrix Subtraction" << endl;
	cout << "3.) Matrix Multiplication" << endl;

	// Switch menu
	switch (menuKey) {

	}
}