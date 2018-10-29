/* tipoTriangulo.cpp
 * Indica si tres lados forman un triángulo y de qué tipo
 * David Alejandro Martínez Tristán
 * A01610267
 * 24/08/2018
*/

#include <iostream>

using namespace std;

int main(void)
{
	double x, y, z;
	
	x = 0;
	y = 0;
	z = 0;
	
	cin >> x >> y >> z;
	
	// Si los tres lados son positivos
	if (x > 0 && y > 0 && z > 0)
	{
		// Si la suma de dos lados es mayor que la longitud del tercer lado
		if (x + y > z || x + z > y || y + z > x)
		{
			// Si dos lados son iguales
			if (x == y)
			{
				// Si uno de los dos es igual al tercero, los tres son iguales
				if (y == z)
                {
                    // Indicar que el triángulo es equilátero
					cout << "EQUILATERO" << endl;
                }    	
				// Si solos los dos primeros lados son iguales
				else
				{
					// Indicar que el triángulo es isóceles
					cout << "ISOCELES" << endl;
				}	
			}
			else if (x == z)
				cout << "ISOCELES" << endl;
			else if (y == z)
				cout << "ISOCELES" << endl;
			else
				cout << "ESCALENO" << endl;
		}
        else
            cout << "NO ES TRIANGULO" << endl;     
	}
    else
        cout << "NO ES TRIANGULO" << endl;
    
    return 0;
}