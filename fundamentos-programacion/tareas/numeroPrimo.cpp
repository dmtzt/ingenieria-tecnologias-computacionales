/* numeroPrimo.cpp
 *
 * Indica si un número introducido por el usuario es primo o no
 *
 * David Alejandro Martínez Tristán
 * A01610267
 *
 * 18/09/2018
*/

#include <iostream>
#define DIVISORS_SIZE 22

using namespace std;

int main(void) {
	int n;
	
	// Arreglo con divisores para probar divisibilidad
	int divisors[] = {2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14,
						15, 17, 18, 19, 20, 25, 29, 31, 100, 125};
	
    // Variable para monitorear si existe más de un divisor
    bool prevDivisorFound;
    
    n = 0;
    
    prevDivisorFound = false;
	
	cin >> n;
	
	// Iterar por todo el arreglo de divisores										
	for (int i = 0; i < DIVISORS_SIZE; i++) {
		// Si n es divisible por el divisor actual
		if (n % divisors[i] == 0) {
			// Si existe un divisor previo
			if (prevDivisorFound) {
				// Indicar que n es un número no primo y terminar programa
				cout << "NO PRIMO" << endl;
				return 0;
			}
			// Si no existe un divisor previo, actualizar estado
			else
				prevDivisorFound = true;
		}
	}
	
	// Si existió ninguno o un divisor por ser el mismo número, n es primo
	cout << "PRIMO" << endl;
	
	return 0;
}