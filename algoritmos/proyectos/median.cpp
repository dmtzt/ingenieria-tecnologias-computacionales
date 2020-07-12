/*
 * median
 * David Alejandro Martinez Tristan
 * A01610267
*/
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std; 

double helperMedian(int arr[], int);
double getMedian(int arr1[], int arr2[], int n); 

int main() 
{ 
    int t, n, num;
	
	cin >> t;

	double median[t];

    for (int i = 0; i < t; i++)
    {
        cin >> n;

        int arr1[n];
		int arr2[n];
        
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            arr1[j] = num;
        }

        for (int j = 0; j < n; j++)
        {
            cin >> num;
            arr2[j] = num;
        }
        
		median[i] = getMedian(arr1, arr2, n); 
    }

	for (int i = 0; i < t; i++)
		cout << "Median case " << fixed << setprecision(2) << (i + 1) << ": " << median[i] << endl;
	
	return 0; 
}

double getMedian(int arr1[], int arr2[], int n) 
{ 
	// O(1)
	if (n == 1) 
		return (double) (arr1[0] + arr2[0]) / 2; 
	// O(1)
	if (n == 2)
		return (double) (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1])) / 2; 

	// Get medians of both arrays and compare them
	int m1 = helperMedian(arr1, n); 
	
	int m2 = helperMedian(arr2, n); 

	// O(1)
	if (m1 == m2) 
		return m1; 

	// O(log n) 
	// Divide and conquer recursive approach
	// Pass subarrays until the size of both is 2
	if (m1 < m2) 
	{ 
		// If m1 is greater than m2, the median is in arr1[0]->m1 or m2->arr2[n-1]
		// Even number of elements
		if (n % 2 == 0) 
			return getMedian(arr1 + n / 2 - 1, arr2, n - n / 2 + 1);
		// Odd number of elements
		else 
			return getMedian(arr1 + n / 2, arr2, n - n / 2); 
	} 
	else
	{
		// If m1 is less than m2, the median is in m1->arr1[n-1] or arr2[0]->m2
		// Even number of elements
		if (n % 2 == 0) 
			return getMedian(arr2 + n / 2 - 1, arr1, n - n / 2 + 1);
		// Odd number of elements
		else
			return getMedian(arr2 + n / 2, arr1, n - n / 2); 
	}
	
} 

double helperMedian(int arr[], int n) 
{ 
	if (n % 2 == 0) 
		return (double) (arr[n / 2] + arr[n / 2 - 1]) / 2; 
	else
		return arr[n / 2]; 
} 