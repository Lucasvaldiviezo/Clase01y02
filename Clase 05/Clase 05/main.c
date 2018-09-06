#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

#define CANTIDAD_EMPLEADOS 5

//&salario[0];Esta bien,pero es muy largo
//salario; => &salario[60] desde donde quiero la direccion de memoria
int utn_mostrarArray(int* pArray,int limite);
int utn_inicializarArray(int* pArray,int valor, int limite);
int utn_calcularmaximoArray(int* pArray,int limite,int* maximo);

int main()
{
    int edades[CANTIDAD_EMPLEADOS];
    int i;
    int maximo;

    while(utn_inicializarArray(edades,-1,CANTIDAD_EMPLEADOS)==-1)
    {
        printf("La direccion del array esta mal");
    }

    for(i=0;i< CANTIDAD_EMPLEADOS;i++)
    {

        utn_getEntero(&edades[i],1,"Ingrese la edad: \n", "Esa no es una edad\n",200,0);
        /*if(utn_getEntero(&edades[i],1,"Ingrese la edad: \n", "Esa no es una edad\n",200,0)==-1)
        {
            edades[i]=-1;
        }*/

    }

    utn_mostrarArray(edades,CANTIDAD_EMPLEADOS);
    utn_mostrarArray(edades+2,CANTIDAD_EMPLEADOS-2);
    utn_calcularmaximoArray(edades,CANTIDAD_EMPLEADOS,&maximo);
    printf("\nEl maximo es: %d\n",maximo);
    return 0;
}

int utn_inicializarArray(int* pArray,int valor, int limite)
{
    int retorno=-1;
    int i;
    if(pArray != NULL && limite >0)
    {
        retorno=0;
        for(i=0;i < limite;i++)
        {
            pArray[i]=valor;
        }
    }


    return retorno;
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

int utn_calcularmaximoArray(int* pArray,int limite,int* maximo)
{
    int i;
    *maximo = pArray[0];
    for(i=0;i < limite;i++)
    {
        if(pArray[i] > *maximo)
        {
            *maximo = pArray[i];
        }
    }

    return 0;
}
