#include <iostream>

using namespace std;

int main()
{
    int m, n, row;
    int suma = 0;

    cin >> m >> n;

    int arr[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    cin >> row;

    for (int i = 0; i < n; i++)
    {
        suma+= arr[row][i];
    }

    cout << suma << endl;

    return 0;
}
