/* contadorFracciones.cpp
 *
 * Dado un valor n, muestra la sumatoria de fracciones de 1/1 a 1/n
 *
 * David Alejandro Mart�nez Trist�n
 * A01610267
 *
 * 16/09/2018
*/

#include <iostream>

using namespace std;

int main(void)
{
	int n;
	
	cin >> n;
	
	if (n > 0)
	{
		// Imprimir primer t�rmino de la sumatoria
		cout << "1/1";
		
		// Si n > 1, imprimir los t�rminos sucesivos, seguidos por el +
		if (n > 1)
		{
			for (int i = 2; i <= n; i++)
			{
				cout << " + 1/" << i;  
			}
		}	
	}
	
	
	return 0;
}