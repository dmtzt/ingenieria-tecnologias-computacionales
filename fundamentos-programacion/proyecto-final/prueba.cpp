#include <ctime>
#include <iostream>
#include <cstdlib>

#define VERTICAL 1
#define HORIZONTAL 2
#define DIAGONAL 3
#define CUATRO_ESQUINAS 4
#define POCITO 5
#define CUADRO_EXTERIOR 6
#define TAMANO_TABLERO 4
#define CARTA_ENCONTRADA 0

using namespace std;

void llenarTablero(int tableroInicial[4][4], int tableroActual[4][4]);
void imprimirTablero(int tableroInicial[4][4], int tableroActual[4][4]);
void actualizarTablero(int tableroInicial[4][4], int tableroActual[4][4]);

int main(void)
{
    int tableroInicial[4][4];
    int tableroActual[4][4];

    llenarTablero(tableroInicial, tableroActual);

    while(true)
   {
        imprimirTablero(tableroInicial, tableroActual);
        cout << "Impreso" << endl;

        actualizarTablero(tableroInicial, tableroActual);
        cout << "Actualizado" << endl;
   } 

    return 0;
}

void llenarTablero(int tableroInicial[4][4], int tableroActual[4][4])
{
	srand(time(0));

	for (int i = 0; i < TAMANO_TABLERO; i++)
    {
        for (int j = 0; j < TAMANO_TABLERO; j++)
        {
            tableroInicial[i][j] = rand() % 53 + 1;
            tableroActual[i][j] = tableroInicial[i][j];
        }
    }		
}

void imprimirTablero(int tableroInicial[4][4], int tableroActual[4][4])
{
    for (int i = 0; i < TAMANO_TABLERO; i++)
    {
        for (int j = 0; j < TAMANO_TABLERO; j++)
        {
            cout << tableroInicial[i][j] << ' ';
        }
        cout << endl;
    }

    cout << endl; 

    for (int i = 0; i < TAMANO_TABLERO; i++)
    {
        for (int j = 0; j < TAMANO_TABLERO; j++)
        {
            if (tableroActual[i][j] != 0)
                cout << tableroActual[i][j] << ' ';
            else
                cout << '*' << ' ';
        }
        cout << endl;
    }   
}

void actualizarTablero(int tableroInicial[4][4], int tableroActual[4][4])
{
    int carta;

    cin >> carta;

	// Verificar que la carta se encuentre dentro del rango valido
    if (carta < 1 || carta > 54)
		return;

	// Encontrar la carta en el tablero
	for (int i = 0; i < TAMANO_TABLERO; i++)
	{
		for (int j = 0; j < TAMANO_TABLERO; j++)
		{
			// La carta se encuentra en el tablero
			if (tableroInicial[i][j] == carta)
			{
				// Si se encuentra en el tablero inicial y no ha sido encontrada
				if (tableroActual[i][j] == carta)
                    // Marcar carta encontrada en tablero actual
					tableroActual[i][j] = CARTA_ENCONTRADA;
                // Si ya fue encontrada anteriormente, omitirla
				else
                    return;
			}
		}
	}
}

bool revisaPatron(int tableroInicial[4][4], int tableroActual[4][4], int cartas[], int patron)
{
    if (patron == VERTICAL)
    {

    }
    else if (patron == HORIZONTAL)
    {

    }
    else if (patron == DIAGONAL)
    {

    }
    else if (patron == CUATRO_ESQUINAS)
    {
        for (int i = 0; i < 4; i += 3)
        {
            for (int j = 0; j < 4; j += 3)
            {
                if (tableroActual[i][j] != CARTA_ENCONTRADA)
                    return false;
            }
        }
    }
    else if (patron == POCITO)
    {
        
    }
    else if (patron == CUADRO_EXTERIOR)
    {

    }
}