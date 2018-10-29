/* raicesCuad.cpp
 * Indica el tipo, cantidad, y valor de las ra�ces de una ecuaci�n cuadr�tica
 * David Alejandro Mart�nez Trist�n
 * A01610267
 * 24/08/2018
 */

#include <iostream>
#include <math.h>

using namespace std;

int main(void)
{
	double a, b, c;
	double discriminant;
	
	a = 0.0;
	b = 0.0;
	c = 0.0;
	discriminant = 0.0;
	
	// Recibe los valores de a, b y c
	cin >> a >> b >> c;
	
	// Calcula el discriminante de la f�rmula general
	discriminant = pow(b, 2) - 4 * a * c;
	
	// Si el discriminante es positivo
	if (discriminant > 0)
	{
		// Calcular e imprimir las dos ra�ces de la ecuaci�n 
		cout << ((-b + sqrt(discriminant)) / (2 * a)) << " " <<
		((-b - sqrt(discriminant)) / (2 * a)) << endl;
		// Indicar el n�mero y tipo de soluciones
		cout << "DOS SOLUCIONES REALES" << endl;
	}
	// Si el discirminante es neutro
	else if (discriminant == 0)
	{
		// Calcular e imprimir la ra�z de la ecuaci�n
		cout << (-b / (2 * a));
		// Indicar el n�mero y tipo de soluciones
		cout << endl << "UNA SOLUCI�N REAL" << endl;
	}
	// Si el discriminante es negativo
	else
		// Indicar el n�mero y tipo de soluciones
		cout << "DOS SOLUCIONES IMAGINARIAS" << endl;
	
	return 0;
}