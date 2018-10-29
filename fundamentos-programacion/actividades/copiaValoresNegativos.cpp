#include <iostream>

using namespace std;

void copiaNegativos(int*& arr, int& size);

int main(void)
{
	int size;
	
	cin >> size;
	
	int* arr = new int[size];
	
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	
	copiaNegativos(arr, size);

	if (arr != NULL)
	{
		cout << arr[0];
		
		for (int i = 1; i < size; i++)
			cout << " " << arr[i];
		
		cout << endl;

		delete arr;	
	}
	
	return 0;
	
}

void copiaNegativos(int*& arr, int& size)
{
	int newSize = 0;
	
	for (int i = 0; i < size; i++)
		if (arr[i] < 0)
			newSize++;
	
	if (newSize > 0)
	{
		int* newArr = new int[newSize];
		
		for (int i = 0, j = 0; i < size; i++)
			if (arr[i] < 0)
			{
				newArr[j] = arr[i];
				j++;
			}
		
		delete arr;
	
		arr = newArr;
	   	size = newSize;
	}	
	else
	{
		delete arr;
		
		arr = NULL;
	   	size = newSize;
	}
}