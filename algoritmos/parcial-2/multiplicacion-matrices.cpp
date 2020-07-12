#include <iostream>
#include <climits>

using namespace std;

#define MAX 51

// d: dimensiones de la matriz (?)
void calcula(int D[MAX][MAX], int P[MAX][MAX], int d[MAX], int n){
	// Llena diagonal principal
	for (int i=1; i<=n; i++){
		D[i][i] = 0;
	}
	int j;
	// Recorre n - 1 diagonales restantes
	for (int diag=1; diag<= n-1; diag++){
		// Celdas por diagonal: número de cortes - diagonal actual
		// Fila de la celda
		for (int i = 1; i<=n-diag; i++) {
			// Columna de la celda
			j = i + diag;
			int men = INT_MAX, aux, menk;
			// Calcula k desde i hasta j - 1
			for (int k=i; k<j; k++){
				// aux = D[i][k] + D[k+1][j];

				if (aux < men){
					men = aux;
					menk = k;
				}
			}
			// Calcula la diferencia entre el último y el primer pedazo
			int diferencia = d[j] - d[i];
			// Menor
			D[i][j] = men + diferencia;
			P[i][j] = menk;
		}
	}
}
/*
4
20 2 30 12 8

RESP = 1232
(A)x(((B)x(C))x(D))
*/
void recorre(int P[MAX][MAX], int ini, int fin){
	if (P[ini][fin] != 0){
		cout << "(";
		recorre(P, ini, P[ini][fin]);
		cout << ")x(";
		recorre(P, P[ini][fin]+1, fin);
		cout << ")";
	}
	else{
		char ch='A'+ini-1;
		cout << ch;
	}
}

void despliega(int P[MAX][MAX], int n){
	recorre(P,1,n);
	cout << endl;
}

int main(){
	int d[MAX]; // Las dimenciones de las matrices
	int D[MAX][MAX], P[MAX][MAX];
	int n; // cantidad de matrices a mult.

	cin >> n;
	for (int i=0; i<=n; i++){
		cin >> d[i];
	}
	// A  8 x 2
	// B  2 x 5
	// C  5 x 4
	// n = 3
	// d  8 2 5 4

	calcula(D, P, d, n);
	cout << D[1][n]<< endl;
	despliega(P, n);

}