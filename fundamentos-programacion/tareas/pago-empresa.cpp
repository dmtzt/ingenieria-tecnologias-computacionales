/*
 * pago-empresa
 * Calcula la compensaci�n econ�mica de un empleado finiquitado
 * seg�n el tiempo trabajado en la empresa.
 * David Alejandro Mart�nez Trist�n
 * A01610267		
 * Fecha de creaci�n: 15/08/2018
 */

#include <iostream>

using namespace std;

int main(void) {
	int dias = 0;
	int aniosTrabajados = 0;
	double sueldoDiario = 0.0;
	double pago = 0.0;
	
	// Solicita al usuario introducir a�os trabajando en la empresa
	cout << "Introducir anios trabajados en la empresa: ";
	
	// Mientras no introduzca una cantidad v�lida, repetir solicitud
	do {
		cin >> aniosTrabajados;
		
		if (aniosTrabajados <= 0) {
			cout << "Introducir cantidad valida: ";
		}	
	}
	while(aniosTrabajados <= 0);
	
	// Solicita al usuario introducir sueldo diario
	cout << "Introducir sueldo diario: $";
	
	// Mientras no introduzca una cantidad v�lida, repetir solicitud
	do {
		cin >> sueldoDiario;
		
		if (sueldoDiario <= 0) {
			cout << "Introducir cantidad valida: $";
		} 	  		
	}
	while (sueldoDiario <= 0);
	
	// Calcular el n�mero de d�as de pago seg�n el n�mero de a�os
	dias = aniosTrabajados * 20;
	
	// Sumar el n�mero de d�as en 3 meses
	dias += 60;
	
	// Multiplicar el n�mero de d�as por el sueldo diario y obtener pago
	pago = dias * sueldoDiario;
	
	// Imprimir pago
	cout << "El monto a pagar es de: $" << pago << endl;
	
	return 0;
}