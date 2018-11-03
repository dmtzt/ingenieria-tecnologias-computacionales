#include <iostream>

using namespace std;

int main()
{
    int days, temps, highestDay;
    int highestTemp = 0;
    double promedioTmp = 0;
    double promedioFinal = 0;

    cin >> days >> temps;

    int arr[days][temps];

    for (int i = 0; i < days; i++)
    {
        promedioTmp = 0;

        for (int j = 0; j < temps; j++)
        {
            cin >> arr[i][j];
            promedioTmp += arr[i][j];
        }

        promedioTmp /= temps;

        if (promedioTmp > promedioFinal)
        {
            promedioFinal = promedioTmp;
            highestDay = i;
        }

    }

    cout << highestDay << endl;
}
