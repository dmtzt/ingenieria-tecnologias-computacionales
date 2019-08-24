#include <iostream>

using namespace std;

int main(void)
{
    int n;
    int arr[4][4];

    cin >> n;

    n %= 4;

    if (n < 0)
        n += 4;

    if (n == 2)
    {
        for (int i = 3; i >= 0; i--)
            for (int j = 3; j >= 0; j--)
                cin >> arr[i][j];
    }
    else if (n % 2 == 1)
    {
        if (n == 1)
        {
            for (int j = 3; j >= 0; j--)
                for (int i = 0; i < 4; i++)
                    cin >> arr[i][j];
        }
        else
        {
            for (int j = 0; j < 4; j++)
                for (int i = 3; i >= 0; i--)
                    cin >> arr[i][j];
        }
    }
    else
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                cin >> arr[i][j];
    }
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0; 
}