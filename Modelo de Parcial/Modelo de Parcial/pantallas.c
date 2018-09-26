#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "pantallas.h"
#include "utn.h"
static int generarID(void);

int pan_cargarDatosVacio(Pantalla* pPantalla, int limite)
{
    int retorno=-1;
    int i;
    if(pPantalla != NULL && limite >0)
    {
        for(i=0;i<limite;i++)
        {
            pPantalla[i].isEmpty=-1;
        }
        retorno=0;
    }

    return retorno;
}
int pan_cargarIndice(Pantalla* pPantalla,int indice,int limite)
{
    int retorno=-1;
    char auxNombre[128];
    char auxDireccion[128];
    int auxTipo;
    float auxPrecio;

    if(pPantalla != NULL && limite >0)
    {
        printf("Ingrese nombre de la pantalla:");
        if(getString(auxNombre,128)==0)
        {
            strncpy(pPantalla[indice].nombre,auxNombre,128);

            if(utn_getEntero(&auxTipo,2,"Ingrese el tipo(1 LCD,0 LED): ","Ese no es un tipo valido\n",2,-1)==0)
            {
                pPantalla[indice].tipo=auxTipo;

                if(utn_getNumeroDecimal(&auxPrecio,10,"Ingrese el precio de la Pantalla:","Ese no es un precio valido\n",4096,0)==0)
                {
                    pPantalla[indice].precio=auxPrecio;
                    printf("Ingrese la direccion: ");
                    if(getString(auxDireccion,128)==0)
                    {
                        strncpy(pPantalla[indice].direccion,auxDireccion,128);
                        pPantalla[indice].ID=generarID();
                        pPantalla[indice].isEmpty=0;
                        retorno =0;
                    }
                }

            }
        }
    }


    return retorno;
}

int pan_modificarIndice(Pantalla* pPantalla,int id, int limite)
{
    int retorno=-1;
    char auxNombre[128];
    char auxDireccion[128];
    int auxTipo;
    float auxPrecio;
    int indice;
    indice=pan_buscarPantallaPorId(pPantalla,limite,id);
    if(indice >= 0)
    {
        if(pPantalla != NULL && limite >0)
        {
            printf("Ingrese el nuevo nombre de la pantalla:");
            if(getString(auxNombre,128)==0)
            {
                strncpy(pPantalla[indice].nombre,auxNombre,128);

                if(utn_getEntero(&auxTipo,2,"Ingrese el nuevo tipo(1 LCD,0 LED): ","Ese no es un tipo valido\n",2,-1)==0)
                {
                    pPantalla[indice].tipo=auxTipo;

                    if(utn_getNumeroDecimal(&auxPrecio,10,"Ingrese el nuevo precio de la Pantalla:","Ese no es un precio valido\n",4096,0)==0)
                    {
                        pPantalla[indice].precio=auxPrecio;
                        printf("Ingrese la direccion: ");
                        if(getString(auxDireccion,128)==0)
                        {
                            strncpy(pPantalla[indice].direccion,auxDireccion,128);
                            retorno =0;
                        }
                    }

                }
            }
        }
    }else
    {
        printf("El ID no existe");
    }



    return retorno;

    return 0;
}

int pan_buscarPantallaPorId(Pantalla* pPantalla,int limite,int id)
{
    int retorno=-1;
    int i;

    for(i=0;i<limite;i++)
    {
        if(pPantalla[i].isEmpty==0)
        {
            if(pPantalla[i].ID==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int pan_borrarPantalla(Pantalla* pPantalla,int limite,int id)
{
    int retorno=-1;
    int i;

    for(i=0;i<limite;i++)
    {
        if(pPantalla[i].isEmpty==0)
        {
            if(pPantalla[i].ID==id)
            {
                pPantalla[i].isEmpty=-1;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int pan_mostrarIndice(Pantalla* pPantalla,int limite)
{
    int retorno=-1;
    int i=0;
    if(pPantalla != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
                if(pPantalla[i].isEmpty==0)
                {
                    printf("\nEl ID de la pantalla es: %d", pPantalla[i].ID);
                    printf("|| El nombre de la pantalla es: %s",pPantalla[i].nombre);
                    printf("||El tipo de la pantalla es(LCD:1, LED:0): %d ",pPantalla[i].tipo);
                    printf("||El precio de la pantalla es: %.2f por dia",pPantalla[i].precio);
                    printf("||La direccion de la pantalla es: %s",pPantalla[i].direccion);
                    retorno=0;
                }

        }

    }

    return retorno;
}
int pan_getEmptyIndex(Pantalla* pPantalla,int limite,int* indiceVacio)
{
    int i=0;
    int retorno = -1;
    if(pPantalla != NULL && limite > 0)
    {
         while(i<limite)
        {
            if(pPantalla[i].isEmpty==-1)
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

static int generarID(void)
    {
        static int cont = -1; //es privada de la funcion, además no muere
        return ++cont;
    }
