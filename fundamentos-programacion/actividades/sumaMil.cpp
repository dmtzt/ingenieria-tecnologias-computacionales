#include <iostream>

using namespace std;

int main(void)
{
	int i, n, suma;
	
	i = 0;
	n = 0;
	suma = 0;
	
	while (suma < 1000)
	{
		cin >> n;
		suma += n;
		i++;
	}	
	
	cout << suma << " " << i << endl;
	
	return 0;
}