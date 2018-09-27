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

            if(utn_getEntero(&auxDias,2,"Ingrese la cantidad de Dias que desea: ","\nEsa no es una cantidad valida\n",DIAS_MAX,-1)==0)
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

int con_modificarIndice(Contratacion* pContratacion,int indiceContratacion,int limite)
{
    int retorno=-1;
    int auxDias;


    if(indiceContratacion >=0)
    {
        if(pContratacion != NULL && limite >0)
        {
                if(utn_getEntero(&auxDias,2,"Ingrese la nueva cantidad de Dias que desea: ","\nEsa no es una cantidad valida\n",DIAS_MAX,-1)==0)
                {
                    pContratacion[indiceContratacion].dias=auxDias;
                }
        }
    }else
    {
        printf("El Indice es incorrecto\n");
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

int con_borrarContratacion(Contratacion* pContratacion,int limite,int indiceContratacion)
{
        int retorno=-1;
       if(pContratacion!=NULL && limite > 0)
       {
            if(pContratacion[indiceContratacion].isEmpty==0)
            {
                if(pContratacion[indiceContratacion].ID==indiceContratacion)
                {
                    pContratacion[indiceContratacion].isEmpty=-1;
                    retorno=0;
                }
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

int con_buscarContratacionPorIdyCuit(Contratacion* pContratacion,int limite,int idPantalla,char* cuit)
{
    int retorno=-1;
    int i;

    for(i=0;i<limite;i++)
    {
        if(pContratacion[i].isEmpty==0)
        {
            if(pContratacion[i].idPantalla==idPantalla && strcmp(pContratacion[i].cuitCliente,cuit)==0)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int con_imprimirContratacionesCuit(Contratacion* pContratacion,int limite,Pantalla* pPantalla,int limite2,char* cuitVacio)
{
    char cuit[20];
    int retorno=-1;
    int i=0;
    int posicion;
    printf("Ingrese su CUIT: ");
    if(getString(cuit,20)==0)
    {
        strcpy(cuitVacio,cuit);
        if(pContratacion != NULL && limite > 0)
        {
            for(i=0;i<limite;i++)
            {
                if(pContratacion[i].isEmpty==0 && strcmp(pContratacion[i].cuitCliente,cuit)==0)
                {
                    posicion=pan_buscarPantallaPorId(pPantalla,limite2,pContratacion[i].idPantalla);
                    pan_mostrarUnIndice(pPantalla,limite2,posicion);
                    retorno=0;
                    printf("-Dias: %d",pContratacion[i].dias);
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
