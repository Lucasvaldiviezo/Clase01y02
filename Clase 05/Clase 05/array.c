#include <stdio_ext.h>
#include <stdlib.h>
#include "array.h"

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

int utn_calcularMaximoArray(int* pArray,int limite,int* maximo)
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

int utn_calcularMinimoArray(int* pArray,int limite,int* minimo)
{
    int i;
    *minimo= pArray[0];
    for(i=0;i < limite;i++)
    {
        if(pArray[i] < *minimo)
        {
            *minimo= pArray[i];
        }
    }

    return 0;
}
