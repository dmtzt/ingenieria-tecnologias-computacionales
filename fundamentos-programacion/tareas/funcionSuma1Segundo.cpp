/* funcionSuma1Segundo.cpp
 *
 * Lee una hora y la imprime con un segundo agregado.
 *
 * David Alejandro Martínez Tristán
 * A01610267
 *
 * 12/10/2018
*/

#include <iostream>

using namespace std;

void sumarSegundo(int& hora, int& minuto, int& segundo);

int main()
{
	int hora, minuto, segundo;
	
	// Leer hora
	cin >> hora >> minuto >> segundo;
	
	// Llamar función para sumar un segundo
	sumarSegundo(hora, minuto, segundo);
	
	// Imprimir hora actualizada
	cout << hora << " " << minuto << " " << segundo << endl;
	
	return 0;
}


/* Suma un segundo y actualiza los valores de los minutos y las horas
 *
 * Recibe la hora por referencia y en el orden hora, minuto y segundo
 *
 * Los valores se actualizan en las variables mismas
 *
*/

void sumarSegundo(int& hora, int& minuto, int& segundo)
{
	segundo++;
	
	if (segundo == 60)
	{
		segundo = 0;
		minuto++;
		
		if (minuto == 60)
		{
			minuto = 0;
			hora++;
			
			if (hora == 25)
				hora = 1;
		}
	}
}