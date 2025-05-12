#include "Portfolio3.h"

#include <iostream>

using namespace std;

int main() {

	int rowvar;
		int colvar;

	cout << "Enter rows and columns (number [SPACE] number): ";
	while (!(cin >> rowvar >> colvar) || rowvar < 1 || colvar < 1) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Provide two positive digits: ";

	}

	int birthnmr;

	cout << "Create a cell if the number of neighbors are: ";
	while (!(cin >> birthnmr) || birthnmr < 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Be sure to enter a positive digit: ";
	}

	int survivalminimum, survivalmaximum;

	cout << "Maintain a cell if the neighbors are between the given minimum and maximum: ";
	while (!(cin >> survivalminimum >> survivalmaximum) || survivalminimum < 0 || survivalmaximum <0 || survivalmaximum < survivalminimum || survivalminimum > 8 || survivalmaximum >8){
		cin.clear();
		cin.ignore(1000, '\n');
		cout <<"Be sure to enter two numbers that are  0 <orequalto minval <orequalto maxval: ";



	}

	Port3 gameplay(rowvar, colvar, birthnmr, survivalmaximum, survivalminimum);
	gameplay.makefirstcells();

	int takegens;

	cout << "Number of generations: ";
	while (!(cin >> takegens) || takegens < 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Be sure to enter a number that is not negative: ";

	}
	for (int h = 0; h <= takegens; ++h) {
		cout << "Generation " << h << ":\n";
		gameplay.displaygridlayout();

	}
	return 0;


}