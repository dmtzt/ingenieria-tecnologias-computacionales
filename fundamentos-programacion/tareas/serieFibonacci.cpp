/* serieFibonacci.cpp
 *
 * Despliega los n�meros de la sucesi�n de Fibonacci menores o iguales a n
 *
 * David Alejandro Mart�nez Trist�n
 * A01610267
 *
 * 18/09/2018
*/

#include <iostream>

using namespace std;

int main(void) {
	int n, prevNum, currNum, temp;
	
	n = 0;
	prevNum = 1;
	currNum = 1;
	
	cin >> n;
	
	// Si n es positivo, imprimir los dos primeros valores
	if (n > 0)
		cout << "1 1";
	// Si n es mayor que 1, imprimir la sucesi�n restante
	if (n > 1) {
		// Mientras la suma de los n�meros anteriores sea menor o igual que n
		while (currNum + prevNum <= n) {
			// Guardar valor de primer n�mero anterior en variable temporal
			temp = currNum;
			// Actualizar valor de primer n�mero
			currNum += prevNum;
			// Actualizar valor de segundo n�mero
			prevNum = temp;
			
			// Imprimir nuevo valor
			cout << " "<< currNum;		
		} 	
	}
	
	cout << endl;
}