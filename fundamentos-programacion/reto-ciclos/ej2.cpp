#include <iostream>

using namespace std;

int main(void)
{
	int minutos;
	char comando;
	
	cin >> minutos;
	
	cin >> comando;
	
	do
	{
		if (minutos == 0)
			minutos = 60;
		else if (minutos == 60)
			minutos = 0;
		
		if (comando == '+')
			minutos++;
		else if (comando == '-')
			minutos--;
		
		cout << minutos % 60 << endl;
		
		cin >> comando;
	}
	while(comando != 'S');	
}