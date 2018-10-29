#include <iostream>

using namespace std;

void ordenar(int& a, int& b, int& c);

int main(void)
{
	int a, b, c;
	
	cin >> a >> b >> c;
	
	ordenar(a, b, c);
	
	cout << a << " " << b << " " << c << endl;
	
	return 0;
}

void ordenar(int& a, int& b, int& c)
{
	int temp = 0;
	
	while (!(a < b && b < c))
	{
		if (a > b)
		{
			temp = b;
			b = a;
			a = temp;
		}
		
		if (b > c)
		{
			temp = c;
			c = b;
			b = temp;
		}	
	}
}