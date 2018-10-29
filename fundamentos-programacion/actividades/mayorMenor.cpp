#include <iostream>

using namespace std;

int main(void)
{
	int mayor, menor, n, k;
	
	cin >> n;
	
	mayor = 0;
	menor = 0;
	k = 0;
	
	cin >> menor;
	
	for (int i = 1; i < n; i++)
	{
		cin >> k;
		
		if (k < menor)
		{
			if (mayor == 0)
			{
				mayor = menor;
				menor = k;
			}
			else
				menor = k;
		}
		
		if (k > mayor)
			mayor = k;
	}
	
	cout << menor << " " << mayor;
	
	return 0;
}