#include <iostream>

using namespace std;

int main(void)
{
	int n;
	int i = 0;
	char c[] = {'*', '#', '%'};
	
	cin >> n;
	
	while (n != 0)
	{
		n--;
		
		if (i == 3)
			i = 0;
		
		cout << c[i];
		i++;
	}
	
	cout << endl;
	
	return 0;	
}