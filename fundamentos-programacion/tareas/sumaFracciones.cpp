#include <iostream>

using namespace std;

void suma_fracciones(int& n1, int& d1, int& n2, int& d2);

int main(void)
{
	int n1, n2, n3, d1, d2, d3;
	
	cin >> n1 >> d1 >> n2 >> d2 >> n3 >> d3;
	
	suma_fracciones(n1, d1, n2, d2);
	suma_fracciones(n1, d1, n3, d3);
	
	cout << n1 << " " << d1 << endl;
	
}

void suma_fracciones(int& n1, int& d1, int& n2, int& d2)
{
	n1 = (n1 * d2) + (n2 * d1);
	d1 = d1 * d2;	
}