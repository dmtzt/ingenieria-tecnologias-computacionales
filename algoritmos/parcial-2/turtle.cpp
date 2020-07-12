#include <iostream>
// El Tesoro de la Tortuga
// Matricula: A01610267
// Nombre: David Alejandro Martinez Tristan

using namespace std;
#define MAX 100

int turtle(int mat[MAX][MAX], int n, int m){
    // Encuentra el maximo numero de monedas de oro ACUMULADO por cada celda
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Celda que no esta en la fila ni en la columna inicial
            if(i > 0 && j > 0)
            {
                // Realiza la suma maxima con el mayor entre (i - 1, j) y (i, j - 1)
                if (mat[i - 1][j] > mat[i][j - 1])
                    mat[i][j] += mat[i - 1][j];
                else
                    mat[i][j] += mat[i][j - 1];
            }
            // Celda que esta en fila inicial
            else if (i > 0)
                // Realiza la unica suma posible con (i - 1, j)
                mat[i][j] += mat[i - 1][j];
            // Celda que esta en columna inicial
            else if (j > 0)
                // Realiza la unica suma posible con (i, j - 1)
                mat[i][j] += mat[i][j - 1];
        }
    }
    
    // El numero maximo es el resultado de la seleccion de la sumas mayores posibles
	return mat[n - 1][m - 1];
}

void print(int mat[MAX][MAX], int n, int m){
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
		 cout << mat[i][j]<< " ";
		}
		cout << endl;
	}	
}

int main(){
	int n, m;
	int mat[MAX][MAX];
	cin >> n  >> m;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> mat[i][j];
		}
	}
//	print(mat, n, m);
	cout << turtle(mat, n, m)<<endl;
}

/*
3 5
1 2 1 1 3
2 10 2 2 3
1 1 0 1 3

Resp: 23

3 4
163 141 752 620
672 91 899 120
50 974 456 297
Resp: 2708

*/