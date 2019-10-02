#define SIZE_CLASES 6
#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    double media = 0;
    double varianza = 0;
    double datos = 0;
    double marcas[SIZE_CLASES];
    double frecuencias[SIZE_CLASES];

    for (int i = 0; i < SIZE_CLASES; i++)
        cin >> marcas[i];
    
    for (int i = 0; i < SIZE_CLASES; i++)
    {
        cin >> frecuencias[i];
        
        datos += frecuencias[i];
        media += marcas[i] * frecuencias[i];
    }

    media /= datos;

    for (int i = 0; i < SIZE_CLASES; i++)
        varianza += pow(marcas[i] - media, 2.0);

    varianza /= datos;

    cout << "media: " << media << endl;
    cout << "varianza: " << varianza << endl;
}