#include <iostream>

using namespace std;

void sustituye(int* arr, int size);

int main(void)
{
	int size;
	
	cin >> size;
	
	int arr[size];
	
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	
	sustituye(arr, size);

	cout << arr[0];
		
	for (int i = 1; i < size; i++)
		cout << " " << arr[i];
	
	return 0;
}

void sustituye(int* arr, int size)
{
	int temp;
	
	for (int i = 0, j = size - 1; i < size / 2; i++, j--)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}