/* parImparPosNeg.cpp
 * Determina e imprimir si un número es par o impar, positivo o negativo
 * David Alejandro Martínez Tristán
 * A01610267
 * 28/08/2018
*/

#include <iostream>

using namespace std;

int main(void) {
	int x;
	
	cin >> x;
	
	// Si el residuo de la división por 2 es 0, el número es par
	if (x % 2 == 0)
		cout << "PAR ";
	// De otra manera, el número es impar
	else
		cout << "IMPAR ";
	
	// Si el número es menor que 0, es negativo  	
	if (x < 0)
		cout << "NEGATIVO" << endl;
	// De otra manera, es positivo
	else
		cout << "POSITIVO" << endl;
	
	return 0;
}