/*
 * pago-empresa
 * Calcula la compensación económica de un empleado finiquitado
 * según el tiempo trabajado en la empresa.
 * David Alejandro Martínez Tristán
 * A01610267		
 * Fecha de creación: 15/08/2018
 */

#include <iostream>

using namespace std;

int main(void) {
	int dias = 0;
	int aniosTrabajados = 0;
	double sueldoDiario = 0.0;
	double pago = 0.0;
	
	// Solicita al usuario introducir años trabajando en la empresa
	cout << "Introducir anios trabajados en la empresa: ";
	
	// Mientras no introduzca una cantidad válida, repetir solicitud
	do {
		cin >> aniosTrabajados;
		
		if (aniosTrabajados <= 0) {
			cout << "Introducir cantidad valida: ";
		}	
	}
	while(aniosTrabajados <= 0);
	
	// Solicita al usuario introducir sueldo diario
	cout << "Introducir sueldo diario: $";
	
	// Mientras no introduzca una cantidad válida, repetir solicitud
	do {
		cin >> sueldoDiario;
		
		if (sueldoDiario <= 0) {
			cout << "Introducir cantidad valida: $";
		} 	  		
	}
	while (sueldoDiario <= 0);
	
	// Calcular el número de días de pago según el número de años
	dias = aniosTrabajados * 20;
	
	// Sumar el número de días en 3 meses
	dias += 60;
	
	// Multiplicar el número de días por el sueldo diario y obtener pago
	pago = dias * sueldoDiario;
	
	// Imprimir pago
	cout << "El monto a pagar es de: $" << pago << endl;
	
	return 0;
}