#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"

static int getString(char* pBufferString,int limite);
static int getInt(int* pResultado);
static int getFloat(float* pResultado);
static int isFloat(char* pBuffer);
/**
 cargarDatosVacio cargar el array isEmpty -1
 @param struc recibe el array
 @param int limite
 @param int devuelve un 0 si esta todo cargado
*/
int cargarDatosVacio(Producto* pProd, int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        pProd[i].isEmpty=-1;
    }
    return 0;
}
int cargarIndice(Producto* pProd,int indice,int limite)
{
    char auxNombre[32];
    char auxDescripcion[128];
    float auxPrecio;
    printf("Nombre:");
    if(getString(auxNombre,32)==0)
    {
        strncpy(pProd[indice].nombre,auxNombre,32);
        printf("Descripcion: ");
        if(getString(auxDescripcion,128)==0)
        {
            printf("Precio: ");
            strncpy(pProd[indice].descripcion,auxDescripcion,128);
            if(utn_getNumeroDecimal(&auxPrecio,3,"","Error de precio: ",50.5,1.3)==0)
            {
                printf("estoy");
                pProd[indice].precio=auxPrecio;
                pProd[indice].isEmpty=0;
            }
        }
    }

    return 0;
}
static int getString(char* pBufferString,int limite)
{
    __fpurge(stdin);
    fgets(pBufferString,limite,stdin);
    if(pBufferString[strlen(pBufferString)-1]=='\n')
    {
        pBufferString[strlen(pBufferString)-1]='\0';
    }
    return 0;
}
int utn_getEntero(int* pNum,int reint,char* msg,char* msgError,int maximo,int minimo)
{
    int auxiliarNum;
    int retorno = -1;
    for(;reint>0;reint--)
    {
        printf(msg);
        if(getInt(&auxiliarNum) == 0)
        {
            if(auxiliarNum > minimo && auxiliarNum < maximo)
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
        }
    }


    return retorno;
}
int utn_getNumeroDecimal(float *pNum, int reint, char* msg, char* msgError,float maximo,float minimo)
{
    float buffer;
    int retorno = -1;

    if(pNum != NULL && msg != NULL && msgError !=NULL && minimo<=maximo && reint >= 0)
    {

        do
        {
            reint--;
            printf("%s",msg);
            if(getFloat(&buffer) == 0 &&
                buffer <= maximo && buffer >= minimo )
            {
                    *pNum = buffer;
                    retorno = 0;
                    break;

            }else
            {
                printf("%s",msgError);
                fflush(stdin);
            }


        }while(reint >= 0);

    }

    return retorno;
}
static int getInt(int* pResultado)
{
    int retorno=-1;
    int num;

    if(scanf("%d",&num)==1)
    {
        *pResultado = num;
        retorno=0;
    }
    return retorno;
}
static int getFloat(float* pResultado)
{
    int retorno=-1;
    char bufferString[4096];
    if(pResultado != NULL)
    {
        if(getString(bufferString,4096) == 0 && isFloat(bufferString)==0)
        {

            *pResultado=atof(bufferString);
            retorno=0;

        }
    }
    return retorno;
}
static int isFloat(char* pBuffer)
{
    int i=0;
    int retorno=0;
    int contadorPuntos=0;
    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i]=='.' && contadorPuntos==0)
        {
            contadorPuntos++;
            i++;
        }
        if((pBuffer[i] < '0' || pBuffer[i] > '9'))
        {

            retorno=-1;
            break;
        }
        i++;
    }

    if(contadorPuntos > 2)
    {
        retorno=-1;
    }

    return retorno;
}
int mostrarIndice(Producto* pProd,int indice)
{
    if(pProd[indice].isEmpty==0)
    {
        printf("nombre: %s",pProd[indice].nombre);
        printf("\ndescripcion: %s",pProd[indice].descripcion);
        printf("\nprecio: %.2f",pProd[indice].precio);
    }
    else
    {
        printf("Esta Vacio");
    }
    return 0;
}
int prod_getEmptyIndex(Producto* productos,int limite,int* indiceVacio)
{
    int i=0;
    int retorno = -1;
    while(i<limite)
    {
        if(productos[i].isEmpty==-1)
        {
            *indiceVacio=i;
            retorno = 0;
            break;
        }
        i++;
    }
    return retorno;
}
