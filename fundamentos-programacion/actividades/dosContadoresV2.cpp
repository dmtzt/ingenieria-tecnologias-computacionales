#include <iostream>

using namespace std;

int main(void)
{
	int a, b;
	
	cin >> a >> b;
	
	while(b != 1)
	{
		a += 2;
		b--;
		
		cout << a << " " << b << endl;
	}
}