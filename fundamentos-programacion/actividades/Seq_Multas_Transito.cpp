/*
 * Seq_Multas_Transito.cpp
 *
 * Calcula el monto a pagar por una multa de tr�nsito con base en
 * la cantidad de salarios m�nimos correspondientes a la multa
 * y el valor del salario m�nimo actual
 *
 * David Alejandro Mart�nez Trist�n 
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