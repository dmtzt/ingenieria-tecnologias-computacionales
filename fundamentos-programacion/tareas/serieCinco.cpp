/* serieCinco.cpp
 *
 * Imprime una serie de números que inicia en un valor dado,
 * y se incrementa por 5 mientras no sea mayor que otro valor dado 
 * 
 * David Alejandro Martínez Tristán
 * A01610267
 *
 * 16/09/2018
*/

#include <iostream>

using namespace std;

int main(void)
{
	// a: valor inicial, b: valor máximo
	int a, b;
	
	a = 0;
	b= 0;
	
	cin >> a >> b;
	
	// Imprimir valor inicial
	cout << a;
	
	// Mientras el incremento por 5 sea menor o igual al valor máximo
	while(a + 5 <= b)
	{
		// Incrementar por 5
		a += 5;
		
		// Imprimir valor
		cout << " " << a;
	}
	
	return 0;
}