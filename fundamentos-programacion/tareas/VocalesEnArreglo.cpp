#include <iostream>

using namespace std;

int main()
{
	int n;
	
	int cantidad = 0;
	
	cin >> n;
	
	char arr[n];
	
 	for (int i = 0; i < n; i++)
	 {
	 	cin >> arr[i];
	 	
	 	if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o'
		    || arr[i] == 'u')
			cantidad++;
	 }
	 
	 cout << cantidad << endl;
	 
	return 0;
}