/* Estacionamiento.cpp
 * Calcula la cuota de estacionamiento con base en la cantidad de
 * horas y minutos transcurridos
 * David Alejandro Mart�nez Trist�n
 * A01610267
 * 31/08/2018
*/

#include <iostream>

using namespace std;

// Prototipo de la funci�n para calcular la cuota de estacionamiento
int calcularCuota(int horas, int minutos);

int main(void) {
	int horas, minutos, cuota;
	
	horas = 0;
	minutos = 0;
	cuota = 0;
	
	// Leer la cantidad de horas y minutos
	cin >> horas >> minutos;
	
	// Invocar la funci�n para calcular la cuota
	cuota = calcularCuota(horas, minutos);
	
	// Imprimir la cuota total
	cout << cuota << endl;
}

/* Funci�n para calcular la cuota de estacionamiento
 * Recibe como par�metros la cantidad de horas y minutos transcurridos
 * Devuelve la cuota total
*/
int calcularCuota(int horas, int minutos) {
	// Si el usuario no ingres� al estacionamiento, no cobrar cuota
	if (horas == 0 && minutos == 0)
		return 0;
	
	int cuota = 20;
	
	// Si el usuario permaneci� 3 horas o menos, cobrar $20 
	if (horas < 3 || (horas == 3 && minutos == 0))
		return cuota;
	
	// Restar las 3 primeras horas al n�mero total
	horas -= 3;
	
	// Sumar $5 por cada hora adicional transcurrida
	cuota += horas * 5;
	
	// Si permaneci� una fracci�n de hora, sumar $5
	if (minutos > 0)
		cuota += 5;
	
	if (cuota > 100)
		cuota = 100;
	
	// Devolver cuota total
	return cuota;
}