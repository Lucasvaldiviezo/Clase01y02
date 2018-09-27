#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pantallas.h"
#include "contratacion.h"
#define DIAS_MAX 400

static int generarID(void);

int con_cargarIndice(Contratacion* pContratacion,int indice,int limite, int idPantalla)
{
    int retorno=-1;
    char auxNombreVideo[128];
    char auxCuitCliente[128];
    int auxDias;

    if(pContratacion != NULL && limite >0)
    {
        printf("Ingrese su CUIT: ");
        if(getString(auxCuitCliente,128)==0)
        {
            strncpy(pContratacion[indice].cuitCliente,auxCuitCliente,128);

            if(utn_getEntero(&auxDias,2,"Ingrese la cantidad de Dias que desea: ","\nEsa no es una cantidad valida",DIAS_MAX,-1)==0)
            {
                pContratacion[indice].dias=auxDias;
                printf("Ingrese nombre del video: ");
                if(getString(auxNombreVideo,128)==0)
                {
                    strncpy(pContratacion[indice].nombreVideo,auxNombreVideo,128);
                    pContratacion[indice].ID=generarID();
                    pContratacion[indice].idPantalla=idPantalla;
                    pContratacion[indice].isEmpty=0;
                    retorno =0;

                }

            }
        }
    }


    return retorno;
}

int con_cargarDatosVacio(Contratacion* pContratacion, int limite)
{
    int retorno=-1;
    int i;
    if(pContratacion != NULL && limite >0)
    {
        for(i=0;i<limite;i++)
        {
            pContratacion[i].isEmpty=-1;
        }
        retorno=0;
    }

    return retorno;
}

int con_modificarIndice(Contratacion* pContratacion,int id,int limite)
{
    int retorno=-1;
    int auxDias;
    int indice;

    indice=con_buscarContratacionPorId(pContratacion,limite,id);

    if(indice >=0)
    {
        if(pContratacion != NULL && limite >0)
        {
                if(utn_getEntero(&auxDias,2,"Ingrese la nueva cantidad de Dias que desea: ","\nEsa no es una cantidad valida\n",DIAS_MAX,-1)==0)
                {
                    pContratacion[indice].dias=auxDias;
                }
        }
    }else
    {
        printf("El ID no existe");
    }




    return retorno;
}

int con_getEmptyIndex(Contratacion* pContratacion,int limite,int* indiceVacio)
{
    int i=0;
    int retorno = -1;
    if(pContratacion != NULL && limite > 0)
    {
         while(i<limite)
        {
            if(pContratacion[i].isEmpty==-1)
            {
                *indiceVacio=i;
                retorno = 0;
                break;
            }
            i++;
        }
    }

    return retorno;
}

int con_buscarContratacionPorId(Contratacion* pContratacion,int limite,int id)
{
    int retorno=-1;
    int i;

    for(i=0;i<limite;i++)
    {
        if(pContratacion[i].isEmpty==0)
        {
            if(pContratacion[i].ID==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int con_imprimirContratacionesCuit(Contratacion* pContratacion,int limite,Pantalla* pPantalla,int limite2)
{
    char cuit[20];
    int retorno=-1;
    int i=0;
    printf("Ingrese su CUIT: ");
    if(getString(cuit,20)==0)
    {
        if(pContratacion != NULL && limite > 0)
        {
            for(i=0;i<limite;i++)
            {
                if(pContratacion[i].isEmpty==0 && strcmp(pContratacion[i].cuitCliente,cuit)==0)
                {
                        pan_mostrarIndice(pPantalla,limite2);
                        retorno=0;
                }

            }

        }
    }

    return retorno;
}
static int generarID(void)
{
    static int cont = -1; //es privada de la funcion, además no muere
    return ++cont;
}
