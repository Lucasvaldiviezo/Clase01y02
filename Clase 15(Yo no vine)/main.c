#include <stdio.h>
#include <stdlib.h>
#define CANT_ENTEROS 10
#define CANT_ENTEROS2 5
#define VALOR 1024

int* newArray(int limite);
int cargarDatosVacio(int* pInt, int limite, int valor);
int mostrarIndices(int* pInt, int limite);
int deleteArray(int* pInt);
int* reSizeArray(int* pInt, int limite);

int main()
{
    int* pInt;
    pInt = newArray(CANT_ENTEROS);
    cargarDatosVacio(pInt, CANT_ENTEROS, VALOR);
    mostrarIndices(pInt, CANT_ENTEROS);
    deleteArray(pInt);
    pInt = reSizeArray(pInt, CANT_ENTEROS2);
    cargarDatosVacio(pInt, CANT_ENTEROS2, VALOR);
    mostrarIndices(pInt, CANT_ENTEROS2);
    return 0;
}

int* newArray(int limite) //Constructor
{
    int* retorno = NULL;
    int* auxInt;
    auxInt = (int*)malloc(sizeof(int) * limite);
    if(auxInt != NULL && limite > 0)
    {
        retorno = auxInt;
    }
    return retorno;
}

int cargarDatosVacio(int* pInt, int limite, int valor)
{
    int retorno = -1;
    int i;
    if(pInt != NULL && limite > 0)
    {
        for(i = 0; i < limite; i++)
        {
            *(pInt+i) = valor;
        }
        retorno=0;
    }
    return retorno;
}

int mostrarIndices(int* pInt, int limite)
{
    int retorno = -1;
    int i;
    printf("\n---> i %p\n", &i);
    if(pInt != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            printf("\n%p - [%d] - %d\n",pInt+i, i, *(pInt+i));
        }
        retorno = 0;
    }
    return retorno;
}

int deleteArray(int* pInt) //Destructor
{
    int retorno = -1;
    if(pInt != NULL)
    {
        free(pInt);
        retorno = 0;
    }
    return retorno;
}

int* reSizeArray(int* pInt, int limite) //Redifine
{
    int* retorno = NULL;
    //int* auxInt;
    if(pInt != NULL && limite > 0)
    {
        retorno = (int*)realloc(pInt, sizeof(int) * limite);
    }
    return retorno;
}
