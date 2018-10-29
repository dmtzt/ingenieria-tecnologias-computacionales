/*
 * cds.cpp
 * Obtiene el precio de un precio de un CD con base en su clave
 * David Alejandro Martínez Tristán
 * A01610267
 * 11/09/2018
*/

#define A 59.90
#define B 129.90
#define C 179.90
#define D 250.50

#include <iostream>

using namespace std;

int main(void) {
	char clave;
	
	cin >> clave;
	
	switch (clave) {
	case 'A':
		cout << A;
		break;
	case 'B':
		cout << B;
		break;
	case 'C':
		cout << C;
		break;
	case 'D':
		cout << D;
		break;
	default:
		cout << "CLAVE INCORRECTA";
		break;
	}
	
	cout << endl;
	
	return 0;
}