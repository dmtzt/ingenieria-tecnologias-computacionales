#include <iostream>

using namespace std;

int main()
{
	int n;
	char letra;
	
	cin >> n >> letra;
	
	if (letra == 'L')
	{

		
		for (int i = 1; i < n; i++)
		{
			cout << '#';
			
			for (int j = 1; j < n; j++)
			cout << '.';
		
			cout << endl;
		}
		
		for (int i = 0; i < n; i++)
			cout << '#';
	}
	else if(letra == 'O')
	{
		
	}
	else if (letra == 'C')
	{
		
	}
	else if (letra == 'X')
	{
		
	}

	return 0;	
}