#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

static int getInt(int* pResultado);
static int getFloat(float* pResultado);

int utn_getNumeroDecimal(float *pNum, int reint, char* msg, char* msgError, float maximo, float minimo)
{
    float auxiliarNum;
    int retorno = -1;
    int reintentos;
    for(reintentos=reint;reintentos>0;reintentos--)
    {
        printf(msg);
        if(getFloat(&auxiliarNum) == 0)
        {
            if(auxiliarNum >= minimo && auxiliarNum < maximo)
            {
                *pNum = auxiliarNum;
                retorno = 0;
                break;
            }else
            {
                printf(msgError);
            }

        }else
        {
            printf(msgError);
            __fpurge(stdin);
        }
    }

    return retorno;
}

int utn_getEntero(int* pNum,int reint,char* msg,char* msgError,int maximo,int minimo)
{
    int auxiliarNum;
    int retorno = -1;
    int reintentos;
    for(reintentos=reint;reintentos>0;reintentos--)
    {
        printf(msg);
        if(getInt(&auxiliarNum) == 0)
        {
            if(auxiliarNum >= minimo && auxiliarNum < maximo)
            {
                *pNum = auxiliarNum;
                retorno = 0;
                break;
            }else
            {
                printf(msgError);
            }

        }else
        {
            printf(msgError);
            __fpurge(stdin);
        }
    }


    return retorno;
}

static int getInt(int* pResultado)
{
    int ret=-1;
    int num;

    if(scanf("%d",&num)==1)
    {
        *pResultado = num;
        ret=0;
    }
    return ret;
}

static int getFloat(float* pResultado)
{
    int ret=-1;
    float num;

    if(scanf("%f",&num)==1)
    {
        *pResultado = num;
        ret=0;
    }
    return ret;
}
