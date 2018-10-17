#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "empleado.h"

int main()
{
    Empleado* listaEmpleados[1000];
    int qtyEmpleados=0;
    int i;
    char auxiliar[50];

    for(i=0;i<100;i++)
    {
        sprintf(auxiliar,"Juan_%d",i);
        listaEmpleados[i] = empleado_newConParametro(auxiliar,"Perez",1.45);
        qtyEmpleados++;
    }

    for(i=0;i<qtyEmpleados;i++)
    {
        empleado_print(listaEmpleados[i]);
    }


    return 0;
}
