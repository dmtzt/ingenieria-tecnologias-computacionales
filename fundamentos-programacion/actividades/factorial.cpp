#include <iostream>

using namespace std;

int main(void)
{
	int n;
	
	cin >> n;
	
	if (n == 0)
	{
		cout << "1" << endl;
		return 0;
	}
	
	int factorial = 1;
	
	for (int i = 1; i <= n; i++)
		factorial *= i;
	
	cout << factorial << endl;
	
	return 0;
}