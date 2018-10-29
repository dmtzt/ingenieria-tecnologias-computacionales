/*
 * Seq_Multas_Transito.cpp
 *
 * Calcula el monto a pagar por una multa de tránsito con base en
 * la cantidad de salarios mínimos correspondientes a la multa
 * y el valor del salario mínimo actual
 *
 * David Alejandro Martínez Tristán 
 * A01610267
 *
 * 21/08/2018
 */

#include <iostream>

using namespace std;

int main(void) {
	int numSalariosMin;
	float salarioMin;
	float multa;
	
	numSalariosMin = 0;
	salarioMin = 0.0;
	multa = 0.0;
	
	cin >> numSalariosMin;
	
	cin >> salarioMin;
	
	multa = numSalariosMin * salarioMin;
	
	cout << multa << endl;
	
	return 0;
}