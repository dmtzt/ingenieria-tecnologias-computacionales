/* serieAlternaDenom.cpp
 *
 * Despliega una serie de fracciones compuestas con numerador y denominador
 * calculado según los valores introducidos por el usuario y un conjunto de
 * criterios establecidos
 *
 * David Alejandro Martínez Tristán
 * A01610267
 *
 * 18/09/2018
*/

#include <iostream>

using namespace std;

int main(void) {
	int n, n1, d1;
	
	n = 0;
	n1 = 0;
	d1 = 0;
	
	cin >> n >> n1 >> d1;
	
	// Imprimir primer término de la serie
	cout << n1 << "/" << d1;
	
	// Calcular e imprimir los términos restantes
	for (int i = 0; i < n - 1; i++) {
		// Incrementar el numerador por 1
		n1++;
		// Si el denominador actual es par, sumar 3
		if (d1 % 2 == 0)
			d1 += 3;
		// Si el denominador es impar, incrementar por 1
		else
		    d1++;
		
		// Imprimir término
		cout << " + " << n1 << "/" << d1;
	}	
	
    cout << endl;
    
	return 0;
}