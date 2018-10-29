#include <iostream>

using namespace std;

void copiaNegativos(int*& arr, int& size);

int main(void)
{
	int size;
	
	cin >> size;
	
	int arr[size];
	
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
			cout << arr[i];
	}		
	
	return 0;
}