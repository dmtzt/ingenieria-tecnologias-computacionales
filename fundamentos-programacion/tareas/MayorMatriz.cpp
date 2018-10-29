#include <iostream>
#include <string>

using namespace std;

char* valorMayor(int n, int m, int** arr);

int main()
{
	int n, m;
	
	char* output;
	
	cin >> n >> m;
	
	int arr[n][m];
	
	output = valorMayor(n, m, arr);
	
	if (output != NULL)
		cout << output;
	
	return 0; 
}

char* valorMayor(int n, int m, int** arr)
{
	int column, row, value;
	
	row = -1;
	column = -1;
	value = -1000;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			
			if (arr[i][j] > value)
			{
				value = arr[i][j];
				row = i;
				column = j;
			}
		}
	}
	
	if (column != -1 && row != -1)
		return to_string(value) + " " to_string(row) + " " to_string(column);
	else
		return NULL;
}
