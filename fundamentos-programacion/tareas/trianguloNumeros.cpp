/* trianguloNumeros.cpp
 *
 * Muestra un triángulo de números del 0 al n, con dimensiones n x n
 *
 * David Alejandro Martínez Tristán
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
	
	// Resta el último número mayor en cada sucesión
	for (int i = n; i > 0; i--) {
		// Imprime la sucesión de 1 al siguiente número mayor
		for (int j = 1; j <= i; j++) {
			cout << j;
		}
		// Imprime una nueva línea después de cada sucesión
		cout << endl;
	}
	
	return 0;	
}