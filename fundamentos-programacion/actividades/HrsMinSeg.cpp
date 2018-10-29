#include <iostream>
#define HORA 3600
#define MINUTO 60

using namespace std;

void convertir(int cantidad, int* segundos, int* minutos, int* horas);

int main(void)
{
	int cantidad;
	int segundos;
	int minutos;
	int horas;
	
	cantidad = 0;
	segundos = 0;
	minutos = 0;
	horas = 0;
	
	cin >> cantidad;
	
	convertir(cantidad, &segundos, &minutos, &horas);
	
	cout << horas << " " << minutos << " " << segundos << endl;
	
	return 0;
}

void convertir(int cantidad, int* segundos, int* minutos, int* horas)
{
	*horas = cantidad / HORA;
	cantidad %= HORA;
	
	*minutos = cantidad / MINUTO;
	cantidad %= MINUTO;
	
	*segundos = cantidad;
}