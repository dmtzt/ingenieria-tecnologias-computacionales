/*
 * km-mi
 * Convierte distancia de mi a km.
 * David Alejandro Martínez Tristán
 * A01610267		
 * Fecha de creación: 15/08/2018
 */

#include <iostream>

using namespace std;

int main(void) {
	double km = 0.0;
	double mi = 0.0;
	
	// Solicita al usuario introducir distancia en mi
	cout << "Introduce distancia en mi: ";
	cin >> mi;
	
	// Convierte distancia en mi a km
	km = mi * 1.6;
	
	// Imprimir distancia en km
	cout << "La distancia en km es: " << km << endl;
	
	return 0;
}