/* validaRango.cpp
 * 
 * Valida si un valor dado se encuentra en el rango 1 <= n <= 100
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
	int n;
	
	// Leer entrada del usuario mientras el valor dado no esté en el rango
	do
	{
		cin >> n;
	}
	while (n < 1 || n > 100);
	
	// Confirmar valor correcto
	cout << "CORRECTO" << endl;

    return 0;	
}