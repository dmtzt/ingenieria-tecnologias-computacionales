#include <iostream>
#include <climits>
#include <vector>

using namespace std;

#define MAX 51

void calcula(int D[MAX][MAX], int d[MAX], int n){
	// Llena diagonal principal
	for (int i=1; i<=n; i++)
		D[i][i] = 0;
	
	int j;

	// Recorre n - 1 diagonales restantes
	for (int diag=1; diag<= n-1; diag++)
    {
		// Celdas por diagonal: número de cortes - diagonal actual
		// Fila de la celda
		for (int i = 1; i<=n-diag; i++) 
        {
			// Columna de la celda
			j = i + diag;
			int men = INT_MAX, aux;
			// Calcula k desde i hasta j - 1
			for (int k=i; k<j; k++)
            {	
				aux = D[i][k] + D[k+1][j];

                // Calcula el corte con el menor precio
				if (aux < men)
					men = aux;
			}
			// Calcula la diferencia entre el último y el primer pedazo
			int dif = d[j] - d[i - 1];

			// Almacena el corte con el menor precio más la diferencia
			D[i][j] = men + dif;
		}
	}
}

int main(){
	int d[MAX];
	int D[MAX][MAX];
    int l;
	int n;

    vector<int> res;

    d[0] = 0;

	do
    {
        cin >> l;

        if (l > 0)
        {
            cin >> n;
            
            for (int i = 1; i <= n; i++)
                cin >> d[i];

            d[++n] = l;

            calcula(D, d, n);
            res.push_back(D[1][n]);
        }
    } while (l > 0);

	for (int i = 0; i < res.size(); i++)
        cout << "The minimum cutting is " << res[i] << "." << endl;   
}