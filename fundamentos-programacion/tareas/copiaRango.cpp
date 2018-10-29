#include <iostream>

using namespace std;

void copiaRango(int* arrA, int sizeA, int lowerLim, int upperLim, int*& arrB, int& sizeB);

int main()
{
	int sizeA, sizeB, lowerLim, upperLim;
	
	cin >> sizeA;
	
	int arrA[sizeA];
	
	for (int i = 0; i < sizeA; i++)
		cin >> arrA[i];
	
	cin >> lowerLim >> upperLim;
	
	int* arrB = NULL;
	
	copiaRango(arrA, sizeA, lowerLim, upperLim, arrB, sizeB);
	
	if (arrB != NULL && sizeB != 0)
	{
		for (int i = 0; i < sizeB; i++)
			cout << arrB[i] << endl;
	}
	
	return 0;
	
}

void copiaRango(int* arrA, int sizeA, int lowerLim, int upperLim, int*& arrB, int& sizeB)
{
	sizeB = 0;
	
	for (int i = 0; i < sizeA; i++)
	{
		if (arrA[i] >= lowerLim && arrA[i] <= upperLim)
			sizeB++;
	}
	
	if (sizeB != 0)
	{
		arrB = new int[sizeB];
		
		for (int i = 0, j = 0; i < sizeA; i++)
		{
			if (arrA[i] >= lowerLim && arrA[i] <= upperLim)
			{
				arrB[j] = arrA[i];
				j++;
			}
		}
	}
	else
		arrB = NULL;
}