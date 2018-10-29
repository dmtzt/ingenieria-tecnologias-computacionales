#include <iostream>

using namespace std;

void suma(int* arr, int n);

int main(void)
{
	int n;
	
	cin >> n;
	
	int arr[n];
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	suma(arr, n);
	
	return 0;
}

void suma(int* arr, int n)
{
	int par = 0;
	int impar = 0;
	
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			par += arr[i];
		else
			impar += arr[i];
	}
	
	cout << par << " " << impar << endl;
}