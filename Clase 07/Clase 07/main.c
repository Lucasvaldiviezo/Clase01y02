#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "array.h"
#include <string.h>
#define CANTIDAD_EMPLEADOS 5

int main()
{

    float edades[CANTIDAD_EMPLEADOS];
    int i;

    for(i=0;i< CANTIDAD_EMPLEADOS;i++)
    {

        utn_getNumeroDecimal(&edades[i],1,"Ingrese la edad: \n", "Esa no es una edad\n",200,0);

    }

    utn_mostrarArray(edades,CANTIDAD_EMPLEADOS);
}
