#define SIZE_CLASES 6
#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    double media_clase, desviacion_media_clase, varianza_clase, desviacion_estandar_clase, datos;
    double marcas[SIZE_CLASES];
    double frecuencias[SIZE_CLASES];

    media_clase = 0;
    desviacion_media_clase = 0;
    varianza_clase = 0;
    datos = 0;

    for (int i = 0; i < SIZE_CLASES; i++)
        cin >> marcas[i];

    for (int i = 0; i < SIZE_CLASES; i++)
    {
        cin >> frecuencias[i];
        media_clase += marcas[i] * frecuencias[i];
        datos += frecuencias[i];
    }

    media_clase /= datos;

    for (int i = 0; i < SIZE_CLASES; i++)
    {
        desviacion_media_clase += abs(marcas[i] - media_clase) * frecuencias[i];
        varianza_clase += pow(desviacion_media_clase, 2.0);
    }
        
    desviacion_media_clase /= datos;
    varianza_clase /= datos;
    desviacion_estandar_clase = sqrt(varianza_clase);

    cout << "media: " << media_clase << endl;
    cout << "desviacion media: " << desviacion_media_clase << endl;
    cout << "varianza: " << varianza_clase << endl;
    cout << "desviacion estandar: " << desviacion_estandar_clase << endl;
}