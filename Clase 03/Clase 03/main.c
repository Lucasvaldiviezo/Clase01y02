#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
//Static=privada
int main()
{
    int num;
    float numDeci;
    int reint=3;
    int max=100;
    int min=0;
    if(utn_getEntero(&num,reint,"Ingrese un numero: ","Numero erroneo\n",max,min) == 0)
    {
        printf("El numero es: %d\n", num);
    }
    if(utn_getNumeroDecimal(&numDeci,reint,"Ingrese numero decimal: ","Numero Erroneo\n",max,min)==0)
    {
        printf("El numero decimal es: %.2f",numDeci);
    }

    return 0;
}



