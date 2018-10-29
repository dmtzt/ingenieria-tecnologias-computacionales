/* trianguloNumeros.cpp
 *
 * Muestra un tri�ngulo de n�meros del 0 al n, con dimensiones n x n
 *
 * David Alejandro Mart�nez Trist�n
 * A01610267
 *
 * 20/09/2018
*/

#include <iostream>

using namespace std;

int main(void) {
	int n;
	
	n = 0;
	
	cin >> n;
	
	// Resta el �ltimo n�mero mayor en cada sucesi�n
	for (int i = n; i > 0; i--) {
		// Imprime la sucesi�n de 1 al siguiente n�mero mayor
		for (int j = 1; j <= i; j++) {
			cout << j;
		}
		// Imprime una nueva l�nea despu�s de cada sucesi�n
		cout << endl;
	}
	
	return 0;	
}