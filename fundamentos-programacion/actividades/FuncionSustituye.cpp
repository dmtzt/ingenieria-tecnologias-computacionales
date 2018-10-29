#include <iostream>

using namespace std;

void sustituye(int* arr, int size, int n);

int main(void)
{
	int size, n;
	
	cin >> size;
	
	int arr[size];
	
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	
	cin >> n;
	
	sustituye(arr, size, n);
	
	for (int i = 0; i < size; i++)
		cout << arr[i] << endl;
}

void sustituye(int* arr, int size, int n)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] % n == 0)
			arr[i] = -1;
	}
}