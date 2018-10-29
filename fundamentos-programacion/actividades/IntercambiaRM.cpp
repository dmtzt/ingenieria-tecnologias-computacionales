#include <iostream>

using namespace std;

int main()
{
	int n, m, temp;
	
	cin >> n >> m;
	
	int arr[n][m];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
		
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < (n / 2); j++)
		{
			temp = arr[j][i];
			arr[j][i] = arr[n - j - 1][i];
			arr[n - j - 1][i] = temp;
		} 
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j];
			
			if (j + 1 < m)
				cout << " ";
		}
		
		cout << endl;
	}	
		
	return 0;	
}