#include <stdio.h>

enum _meses {ENERO = 1, FEBRERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, AGOSTO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE};

int main()
{
    enum _meses mes;
    char* nombreMes[] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};

    for (mes=ENERO; mes <= DICIEMBRE; mes++)
        printf("%2d %11s\n", mes, nombreMes[mes]);
}