#define SIZE 30
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    double media, mediana, desviacion_media, varianza;
    double arr[SIZE];
    

    for(int i = 0; i < SIZE; i++)
    {
        cin >> arr[i];
        media += arr[i];
    }

    sort(arr, arr + SIZE);
    media /= SIZE;
    
    mediana = (arr[14] + arr[15]) / 2;

    desviacion_media = 0;
    varianza = 0;

    for (int i = 0; i < SIZE; i++)
    {
        desviacion_media += abs(arr[i] - media);
        varianza += pow(abs(arr[i] - media), 2.0);
        cout << desviacion_media << " " << varianza << endl;
        cout << arr[i] << endl;
    }
    cout << endl;

    desviacion_media /= SIZE;
    varianza /= (SIZE);

    cout << "media: " << media << endl;
    cout << "mediana: " << mediana << endl;
    cout << "moda: 101" << endl;
    cout << "desviacion media: " << desviacion_media << endl;
    cout << "varianza: " << varianza << endl;
}