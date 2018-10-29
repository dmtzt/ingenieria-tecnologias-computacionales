#include <iostream>
#include <string>

using namespace std;
void eliminarDuplicados(int* arr1, int size1, int*& arr2, int& size2);

int main()
{	
	int size1, size2;
	int* arr2;
	
	cin >> size1;
	
	int arr1[size1];
	
	for (int i = 0; i < size1; i++)
		cin >> arr1[i];
	
	eliminarDuplicados(arr1, size1, arr2, size2);
	
	for (int i = 0; i < size2; i++)
		cout << arr2[i] << endl;	
	
	return 0;
}

void eliminarDuplicados(int* arr1, int size1, int*& arr2, int& size2)
{
	bool found;	
	string temp;
	
	size2 = 1;
	
	temp += (char) (arr1[0] + '0');
	
	for (int i = 1; i < size1; i++)
	{
		found = false;
		
		for (int j = 0; j < temp.size(); j++)
		{
			if (arr1[i] == temp[j] - '0')
			{
				found = true;
				break;
			}
		}
		
		if (!found)
		{
			temp += (char) (arr1[i] + '0');
			size2++;
		}
			
	}
	
	arr2 = new int[size2];
		
	for (int i = 0; i < size2; i++)
		arr2[i] = temp[i] - '0';	
}