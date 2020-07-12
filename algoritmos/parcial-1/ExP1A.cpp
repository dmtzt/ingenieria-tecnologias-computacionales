/*
  Matricula: A01610267
  Nombre: David Alejandro Martinez Tristan
*/

#include <iostream>
#include <vector>

using namespace std;

bool iguales(vector<int> &d, int k){
    int count;
    for (int i = 0; i < d.size() - 1; i++) //n - 1
    {
        if (i + k >= d.size())
            count = d.size() - i - 1;
        else
            count = k;

        while (count > 0)
        {
            if (d[i] == d[i + count])
                return true;

            count--;
        }
    }
  
	return false;
}

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> datos(n);
	for (int i=0; i<n; i++){
		cin>>datos[i];
	}
  cout << (iguales(datos, k)? "YES" : "NO") <<endl;
}

/*
Ejemplo 1
4 3
1 2 3 1

Ejemplo 2
4 1
1 0 1 1

Ejemplo 3
6 2
1 2 3 1 2 3
 
*/