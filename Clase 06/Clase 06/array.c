#include <stdio_ext.h>
#include <stdlib.h>
#include "array.h"
#define DATO_INVALIDO -1
#define true 1
#define false 0



int utn_inicializarArray(int* pArray,int valor, int limite)
{
    int retorno=-1;
    int i;
    if(pArray != NULL && limite >0)
    {
        for(i=0;i < limite;i++)
        {
            pArray[i]=valor;
        }
        retorno=0;
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

int utn_calcularMaximoArray(int* pArray,int limite,int* pMaximo)
{
    int i;
    int retorno;
    int maximo;
    int flagPrimerMaximo=0;
    for(i=0;i < limite;i++)
    {
        if(pArray[i]!=DATO_INVALIDO)
        {
            if(flagPrimerMaximo == 0)
            {
                maximo = pArray[i];
                flagPrimerMaximo=1;
            }
            else if(pArray[i] > maximo)
            {
                maximo = pArray[i];
            }
        }

    }
    if(flagPrimerMaximo==0)
    {
        retorno=-2;
    }else
    {
        retorno=0;
        *pMaximo=maximo;
    }

    return retorno;
}

int utn_promedioArray(int* pArray,int limite,float* pPromedio)
{
    int i;
    int retorno;
    float suma;
    float auxpromedio;
    int cantidadValidos=0;
    int flagPrimerMaximo=0;
    for(i=0;i < limite;i++)
    {
        if(pArray[i]!=DATO_INVALIDO)
        {
            suma=suma+pArray[i];
            cantidadValidos++;
            if(flagPrimerMaximo==0)
            {
                flagPrimerMaximo=1;
            }
        }

    }
    if(flagPrimerMaximo==0)
    {
        retorno=-1;
    }else
    {
        auxpromedio=suma/(float)cantidadValidos;
        *pPromedio=auxpromedio;
        retorno=0;
    }


    return retorno;
}

int utn_calcularMinimoArray(int* pArray,int limite,int* pMinimo)
{
    int i;
    int minimo= pArray[0];
    for(i=0;i < limite;i++)
    {
        if(pArray[i] < minimo)
        {
            minimo= pArray[i];
        }
    }
    *pMinimo=minimo;
    return 0;
}

int utn_arrayEsNumero(char* pArray)
{
    int retorno=0;
    int i=0;
    char aux;
    aux=pArray[i];
    while(aux!= 0)
    {
        if(pArray[i] >= '0' && pArray[i] <= '9')
        {
            i++;
            aux=pArray[i];
        }else
        {
            break;
            retorno=-1;
        }


    }
    return retorno;
}

int utn_ordenarArray(int* pArray,int limite,char mayorMenor)
{
    int i=0;
    int aux;
    int flagNoTermineOrdenar=1;
    int retorno=0;

    if(pArray != NULL && limite > 0)
    {
        while(flagNoTermineOrdenar == 1)
        {
            flagNoTermineOrdenar=0;
            for(i=0;i<(limite-1);i++)
            {

                if((pArray[i] > pArray[i+1] && mayorMenor == '>') || (pArray[i] < pArray[i+1] && mayorMenor == '<'))
                {
                        aux=pArray[i];
                        pArray[i]=pArray[i+1];
                        pArray[i+1]=aux;
                        flagNoTermineOrdenar=1;
                }


            }

        }
    }else
    {
        retorno=-1;
    }


    return retorno;
}
