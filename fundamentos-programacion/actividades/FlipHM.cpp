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
		
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (m / 2); j++)
		{
			temp = arr[i][j];
			arr[i][j] = arr[i][m - j - 1];
			arr[i][m - j - 1] = temp;
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