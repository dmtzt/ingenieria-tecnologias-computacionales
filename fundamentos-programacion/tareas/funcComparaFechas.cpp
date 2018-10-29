/* funcComparaFechas.cpp
 *
 * Lee 3 fechas e imprime la menor de ellas.
 *
 * David Alejandro Martínez Tristán
 * A01610267
 *
 * 12/10/2018
*/

#include <iostream>

using namespace std;

void compararFechas(int& d1, int& m1, int& a1, int& d2, int& m2, int& a2);

int main()
{
	// Arreglo para almacenar día, mes y año de 3 fechas
	int fechas[3][3];
	
	// Leer valores de las fechas
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >>  fechas[i][j];
		
	// Encontrar la fecha menor entra la 1 y la 2
	// La función almacena la fecha menor en la 1, por lo que después se
	// comparan la fecha 1 y la 3	
	for (int i = 1; i < 3; i++)
		compararFechas(fechas[0][0], fechas[0][1], fechas[0][2],
				   	   fechas[i][0], fechas[i][1], fechas[i][2]);
						   
	// Imprimir fecha menor					   
	cout << fechas[0][0] << " " << fechas[0][1] << " " << fechas[0][2];
	
	return 0;
}

/* Compara dos fechas y determina cuál de ellas es menor
 *
 * Recibe los valores de las fechas como parámetros por referencia, en el orden
 * día, mes y año, primero de la fecha 1 y después de la fecha 2
 *
 * Los valores de la fecha menor son asignados a las variables de la fecha 1
*/
void compararFechas(int& d1, int& m1, int& a1, int& d2, int& m2, int& a2)
{
	if (a1 < a2)
		return;
	else if (a2 < a1)
	{
		d1 = d2;
		m1 = m2;
		a1 = a2;
	}
	else
	{
		if (m1 < m2)
			return;
		else if (m2 < m1)
		{
			m1 = m2;
			d1 = d2;
		}
		else
		{
			if (d1 < d2)
				return;
			else if (d2 < d1)
				d1 = d2;
		}
	}
}