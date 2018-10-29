/* trianguloAsteriscos.cpp
 *
 * Imprime un tri�ngulo de asteriscos de base y altura n
 *
 * David Alejandro Mart�nez Trist�n
 * A01610267
 *
 * 21/09/2018
*/

#include <iostream>

using namespace std;

int main(void) {
	int n;
	
	n = 0;
	
	cin >> n;
	
	// Tri�ngulo de 1 a n/2
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++)
			cout << '*';			
		cout << endl;
	}
	
	// Tri�ngulo de n/2 + 1 a n
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++)
			cout << '*';			
		cout << endl;
	}
	
	return 0;
}