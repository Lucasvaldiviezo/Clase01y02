#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

#define CANTIDAD_EMPLEADOS 5

//&salario[0];Esta bien,pero es muy largo
//salario; => &salario[60] desde donde quiero la direccion de memoria
int utn_mostrarArray(int* pArray,int limite);
int utn_inicializarArray(int* pArray,int valor, int limite);

int main()
{
    int edades[CANTIDAD_EMPLEADOS];
    int i;
    utn_inicializarArray(&edades[0],-1,CANTIDAD_EMPLEADOS);

    for(i=0;i< CANTIDAD_EMPLEADOS;i++)
    {

        utn_getEntero(&edades[i],1,"Ingrese la edad: \n", "Esa no es una edad\n",200,0);
        /*if(utn_getEntero(&edades[i],1,"Ingrese la edad: \n", "Esa no es una edad\n",200,0)==-1)
        {
            edades[i]=-1;
        }*/

    }

    utn_mostrarArray(edades,CANTIDAD_EMPLEADOS);
    return 0;
}

int utn_inicializarArray(int* pArray,int valor, int limite)
{
    int i;
    for(i=0;i < limite;i++)
    {
        pArray[i]=valor;
    }

    return 0;
}

int utn_mostrarArray(int* pArray,int limite)
{
    int i;
    for(i=0;i < limite;i++)
    {
        printf("\nIndex:[%d] - Value:%d - Add:%p",i,pArray[i],pArray+i);
    }

    return 0;
}
