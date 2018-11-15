#include <cstdlib>
#include <ctime>
#include <iostream>
#include <climits>

#define VERTICAL 1
#define HORIZONTAL 2
#define DIAGONAL 3
#define CUATRO_ESQUINAS 4
#define POCITO 5
#define CUADRO_EXTERIOR 6
#define TAMANO_TABLERO 4
#define CARTA_ENCONTRADA 0
#define TABLERO_ACTUALIZADO 0
#define NO_NUMERO -1
#define FUERA_RANGO -2
#define YA_INTRODUCIDA -3
#define NO_ENCONTRADA -4

using namespace std;

void bienvenida(int &tipoJuego);
void actualizarTablero(int tableroInicial[4][4], int tableroActual[4][4], int& resultado);
void mostrarTablero(int tableroInicial[4][4], int tableroActual[4][4]);
void llenarTablero(int tableroInicial[4][4], int tableroActual[4][4]);
void mostrarError(int& resultado);
void mensajeGanador(int numerosGanadores[], int n);
bool revisarPatron(int tableroInicial[4][4], int tableroActual[4][4],int numerosGanadores[], int tipoJuego);

int main()
{
	int tableroInicial[4][4], tableroActual[4][4];
	int tipoJuego;
	int resultado = 0;

	bienvenida(tipoJuego);

	int n = (tipoJuego == CUADRO_EXTERIOR) ? 12 : 4;

	int numerosGanadores[n];

	llenarTablero(tableroInicial, tableroActual);
	mostrarTablero(tableroInicial, tableroActual);

	do
	{
    	actualizarTablero(tableroInicial, tableroActual, resultado);
    	mostrarTablero(tableroInicial, tableroActual);
	}
	while(!revisarPatron(tableroInicial, tableroActual, numerosGanadores, tipoJuego));

	mensajeGanador(numerosGanadores, n);

	return 0;
}

/*
 * Funcion de bienvenida.
 * 
 * Da la bienvenida a la loteria, imprime las opciones de juego
 * y lee la opcion seleccionada por el jugador.
 * 
 * La opcion seleccionada es almacenada en la variable proporcionada
 * como argumento de la funcion, puesto que sera indispensable al momento
 * de revisar el patron ganador.
 *
*/
void bienvenida(int &tipoJuego)
{
	cout<<endl<<endl<<endl;
    cout<<" !!!!    LLLL           OOOOOOOO    TTTTTTTTTTTTTT   EEEEEEEEEEEE   RRRRRRRRR    IIIIIIIIIIII         AAA         !!!!"<<endl;
    cout<<" !!!!    LLLL          OOOOOOOOOO   TTTTTTTTTTTTTT   EEEEEEEEEEEE   RRRRRRRRRR   IIIIIIIIIIII        AAAAA        !!!!"<<endl;
    cout<<"         LLLL         OOOO    OOOO       TTTT        EEE            RRR   RRRR       IIII           AAAAAAA       !!!!"<<endl;
    cout<<" !!!!    LLLL         OOO      OOO       TTTT        EEEEEEEEE      RRRRRRRRR        IIII          AAA   AAA      !!!!"<<endl;
    cout<<" !!!!    LLLL         OOO      OOO       TTTT        EEEEEEEEE      RRRRRRRR         IIII         AAAAAAAAAAA     !!!!"<<endl;
    cout<<" !!!!    LLLL         OOOO    OOOO       TTTT        EEE            RRR RRR          IIII        AAAAAAAAAAAAA        "<<endl;
    cout<<" !!!!    LLLLLLLLLLL   OOOOOOOOOO        TTTT        EEEEEEEEEEEE   RRR  RRR     IIIIIIIIIIII   AAA         AAA   !!!!"<<endl;
    cout<<" !!!!    LLLLLLLLLLL    OOOOOOOO         TTTT        EEEEEEEEEEEE   RRR   RRR    IIIIIIIIIIII  AAAA         AAAA  !!!!"<<endl;
    cout<<endl<<endl<<endl;

	system("pause");
	system("cls");
	
	// Imprimir opciones de juego
	cout << "OPRIME EL NUMERO PARA SELECCIONAR EL TIPO DE JUEGO:" << endl;
	cout << "1) VERTICAL" << endl;
	cout << "2) HORIZONTAL" << endl;
	cout << "3) DIAGONAL" << endl;
	cout << "4) CUATRO ESQUINAS" << endl;
	cout << "5) POCITO"<< endl;
	cout << "6) CUADRO EXTERIOR" << endl;
	
	// Leer opcion seleccionada por el usuario
	do
	{
		system("cls");

		// Imprimir opciones de juego
		cout << "OPRIME EL NUMERO PARA SELECCIONAR EL TIPO DE JUEGO:" << endl;
		cout << "1) VERTICAL" << endl;
		cout << "2) HORIZONTAL" << endl;
		cout << "3) DIAGONAL" << endl;
		cout << "4) CUATRO ESQUINAS" << endl;
		cout << "5) POCITO"<< endl;
		cout << "6) CUADRO EXTERIOR" << endl;

		if (!cin.good() || tipoJuego < 1 || tipoJuego > 6)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "SELECCIONA UNA OPCION VALIDA: " << endl;
		}

		cin >> tipoJuego;
	}
	while (tipoJuego < 1 || tipoJuego > 6);
	

	while (!cin.good())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}

}

void actualizarTablero(int tableroInicial[4][4], int tableroActual[4][4], int& resultado)
{
	int carta;
	bool cartaEncontrada = false;

   mostrarError(resultado);

   cout << "Introduce la carta que gritaron: ";
   		
	cin >> carta;

	if (!cin.good())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		resultado = NO_NUMERO;
		return;
	}


	// Verificar que la carta se encuentre dentro del rango valido
   if (carta < 1 || carta > 54)
   {
	   resultado = FUERA_RANGO;
	   return;
   }
	   
    	
	// Encontrar la carta en el tablero
	for (int i = 0; i < TAMANO_TABLERO; i++)
	{
    	for (int j = 0; j < TAMANO_TABLERO; j++)
    	{
        	// La carta se encuentra en el tablero
        	if (tableroInicial[i][j] == carta)
        	{
				cartaEncontrada = true;
            	// Si se encuentra en el tablero inicial y no ha sido encontrada
            	if (tableroActual[i][j] == carta)
               		// Marcar carta encontrada en tablero actual
                	tableroActual[i][j] = CARTA_ENCONTRADA;
           		// Si ya fue encontrada anteriormente, indicarselo al jugador y omitirla
            	else
				{
					resultado = YA_INTRODUCIDA;
					return;
				}
        	}
    	}
	}

	// Si la carta no fue encontrada, indicarlo
	if (!cartaEncontrada)
	{
		resultado = NO_ENCONTRADA;
		return;
	}
		
	resultado = TABLERO_ACTUALIZADO;
}

void mostrarTablero(int tableroInicial[4][4], int tableroActual[4][4])
{
	system("cls");
	cout << string(50, '_') << endl;
	cout << "Tablero inicial" << endl;

	for (int i = 0; i < 4; i++)
	{
    	for(int j = 0; j < 4; j++)
		{
        	cout << tableroInicial[i][j];

        	if(tableroInicial[i][j]>=10)
            	cout<<" ";
        	else
            	cout<<"  ";
    	}
	cout<<endl;
	}

	cout<<endl << "Tablero actual" << endl;

	for(int i=0; i<4; i++){
    	for(int j=0; j<4; j++){
        	if (tableroActual[i][j]==0)
            	cout<<"*";
        	else
        	cout<<tableroActual[i][j];
        	if(tableroActual[i][j]>=10)
            	cout<<" ";
        	else
            	cout<<"  ";
    	}
    	cout<< endl;
	}
}

void llenarTablero(int tableroInicial[4][4], int tableroActual[4][4])
{
	// Asignar seed para generador de numeros pseudo-aleatorios
	srand(time(0));

	// Generar numeros aleatorios en el rango 1-54 y almacenar en tablero
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
   		{
       		tableroInicial[i][j] = rand() % 53 + 1;
       		tableroActual[i][j] = tableroInicial[i][j];
   		}
   	}
}

void mostrarError(int& resultado)
{
	switch (resultado)
	{
		case TABLERO_ACTUALIZADO:
			break;
		case NO_NUMERO:
			cout << "La carta no es un numero" << endl;
			break;
		case FUERA_RANGO:
			cout << "La carta se encuentra fuera del rango" << endl;
			break;
		case YA_INTRODUCIDA:
			cout << "La carta ya fue introducida" << endl;
			break;
		case NO_ENCONTRADA:
			cout << "La carta no fue encontrada" << endl;
			break;
		default:
			break;
	}
}

void mensajeGanador(int numerosGanadores[], int n)
{
	cout<<endl<<endl<<endl;
    cout<<" !!!!    LLLL           OOOOOOOO    TTTTTTTTTTTTTT   EEEEEEEEEEEE   RRRRRRRRR    IIIIIIIIIIII         AAA         !!!!"<<endl;
    cout<<" !!!!    LLLL          OOOOOOOOOO   TTTTTTTTTTTTTT   EEEEEEEEEEEE   RRRRRRRRRR   IIIIIIIIIIII        AAAAA        !!!!"<<endl;
    cout<<"         LLLL         OOOO    OOOO       TTTT        EEE            RRR   RRRR       IIII           AAAAAAA       !!!!"<<endl;
    cout<<" !!!!    LLLL         OOO      OOO       TTTT        EEEEEEEEE      RRRRRRRRR        IIII          AAA   AAA      !!!!"<<endl;
    cout<<" !!!!    LLLL         OOO      OOO       TTTT        EEEEEEEEE      RRRRRRRR         IIII         AAAAAAAAAAA     !!!!"<<endl;
    cout<<" !!!!    LLLL         OOOO    OOOO       TTTT        EEE            RRR RRR          IIII        AAAAAAAAAAAAA        "<<endl;
    cout<<" !!!!    LLLLLLLLLLL   OOOOOOOOOO        TTTT        EEEEEEEEEEEE   RRR  RRR     IIIIIIIIIIII   AAA         AAA   !!!!"<<endl;
    cout<<" !!!!    LLLLLLLLLLL    OOOOOOOO         TTTT        EEEEEEEEEEEE   RRR   RRR    IIIIIIIIIIII  AAAA         AAAA  !!!!"<<endl;
    cout<<endl<<endl;
	
	cout << "NUMEROS GANADORES:" << endl;
	cout << numerosGanadores[0];
	for(int i = 1; i < n; i++)
    	cout<<" | "<<numerosGanadores[i];

	cout << endl;
}

bool revisarPatron(int tableroInicial[4][4], int tableroActual[4][4],int numerosGanadores[], int tipoJuego)
{
   if (tipoJuego == VERTICAL)
   {
   	int cvert=0;
   	for(int i=0; i<4; i++)
	   {
        for(int j=0; j<4; j++)
		{
        	if(tableroActual[j][i]==0)
			{
               	numerosGanadores[cvert]=tableroInicial[j][i];
               	cvert++;
               	
				if(cvert==4)
                   	return true;
           	}
        }
     	cvert=0;
   	}

    return false;
   }
   else if (tipoJuego == HORIZONTAL)
   {
    	// Variable para registrar patron encontrado
    	bool patronEncontrado;

		// Revisar fila por fila
    	for (int i = 0; i < TAMANO_TABLERO; i++)
    	{
			// Suponer que el patron se ha formado en la fila actual
        	patronEncontrado = true;

			// Revisar elementos de la fila
        	for (int j = 0; j < TAMANO_TABLERO; j++)
        	{
				// Si una carta no ha sido encontrada, pasar a siguiente fila
            	if (tableroActual[i][j] != CARTA_ENCONTRADA)
            	{
                	patronEncontrado = false;
                	break;
            	}
				// Si fue encontrada, agregar a arreglo de cartas ganadoras
            	else
					numerosGanadores[j] = tableroInicial[i][j];
        	}

			// Si el patron fue encontrado, indicarlo
			if(patronEncontrado)
				return true;
    	}

		// Indicar que el patron se encontro
		return false;
   }
   
   else if (tipoJuego == DIAGONAL)
   {
   	int cdiag=0;
   	for(int i=0; i<4; i++)
   	{
       	if(tableroActual[i][i]==0){
            	numerosGanadores[cdiag]=tableroInicial[i][i];
            	cdiag++;
            	if(cdiag==4)
                	return true;
       	}
   	}

   	cdiag=0;

   	for(int i=3; i>=0; i--)
   	{
       	if(tableroActual[3 - i][i]==0){
                	numerosGanadores[cdiag]=tableroInicial[ 3 - i][i];
                	cdiag++;
                	if(cdiag==4)
                    	return true;
            	}
   	}


    	return false;
   }
  else if (tipoJuego == CUATRO_ESQUINAS)
	{
		// Revisar las cuatro esquinas del tablero
		// Si se encuentra, agregarla a las cartas ganadoras, de otra manera terminar
		// Esquina superior izquierda
		if (tableroActual[0][0] != CARTA_ENCONTRADA)
			return false;
		else
			numerosGanadores[0] = tableroInicial[0][0];
		
		// Esquina superior derecha
		if (tableroActual[0][3] != CARTA_ENCONTRADA)
			return false;
		else
			numerosGanadores[1] = tableroInicial[0][3];

		// Esquina inferior izquierda
		if (tableroActual[3][0] != CARTA_ENCONTRADA)
			return false;
		else
			numerosGanadores[2] = tableroInicial[3][0];

		// Esquina inferior derecha
		if (tableroActual[3][3] != CARTA_ENCONTRADA)
			return false;
		else
			numerosGanadores[3] = tableroInicial[3][3];

		return true;
	}
	else if (tipoJuego == POCITO)
	{
		int cpoc=0;
   		for(int i=1; i<=2; i++){
        	for(int j=1; j<=2; j++){
            	if(tableroActual[i][j]==0){
                	numerosGanadores[cpoc]=tableroInicial[i][j];
                	cpoc++;
                	if(cpoc==4)
                    	return true;
            	}
        	}
		}
    	return false;
	}
	else if (tipoJuego == CUADRO_EXTERIOR)
	{
		// Revisar fila superior
		for (int i = 0; i < TAMANO_TABLERO; i++)
		{
			if (tableroActual[0][i] != CARTA_ENCONTRADA)
				return false;
			else
				numerosGanadores[i] = tableroInicial[0][i];
		}

		// Revisar cartas del lado izquierdo no comunes
		for (int i = 1; i < 3; i++)
		{
			if (tableroActual[i][0] != CARTA_ENCONTRADA)
				return false;
			else
				numerosGanadores[i + 3] = tableroInicial[i][0];
		}

		// Revisar cartas del lado derecho no comunes
		for (int i = 1; i < 3; i++)
		{
			if (tableroActual[i][3] != CARTA_ENCONTRADA)
				return false;
			else
				numerosGanadores[i + 5] = tableroInicial[i][3];
				
		}

		// Revisar fila inferior
		for (int i = 0; i < TAMANO_TABLERO; i++)
		{
			if (tableroActual[3][i] != CARTA_ENCONTRADA)
				return false;
			else
				numerosGanadores[i + 8] = tableroInicial[3][i];
		}

		return true;
	}

	return false;
}