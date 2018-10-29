#include <iostream>

using namespace std;

int main(void)
{
	int k, n;
	
	cin >> k >> n;
	
	cout << k;
	
	for (int i = 0; i < n - 1; i++)
	{	
		if (i == 0 || i % 2 == 0)
			k += 2;
		else
			k--;
	
		cout << " " << k;
	}
	
	cout << endl;
	
	return 0;
}