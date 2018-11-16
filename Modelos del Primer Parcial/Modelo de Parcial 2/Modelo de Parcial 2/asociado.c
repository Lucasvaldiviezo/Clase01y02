#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "asociado.h"
#include "utn.h"
static int generarID(void);

int aso_cargarForzadaIndice(Asociado* pAsociado,int limite,char* nombrePantalla, char* direccion,int tipo, int precio)
{
    int retorno=-1;
    int indice;
    pan_getEmptyIndex(pAsociado,limite,&indice);

    if(pAsociado != NULL && limite >0)
    {
          if(indice >= 0)
          {
            strncpy(pAsociado[indice].nombre,nombrePantalla,128);
            pAsociado[indice].tipo=tipo;
            pAsociado[indice].precio=precio;
            strncpy(pAsociado[indice].direccion,direccion,128);
            pAsociado[indice].ID=generarID();
            pAsociado[indice].isEmpty=0;
            retorno =0;
          }

    }


    return retorno;
}

int aso_cargarDatosVacio(Asociado* pAsociado, int limite)
{
    int retorno=-1;
    int i;
    if(pAsociado != NULL && limite >0)
    {
        for(i=0;i<limite;i++)
        {
            pAsociado[i].isEmpty=-1;
        }
        retorno=0;
    }

    return retorno;
}

int aso_cargarIndice(Asociado* pAsociado,int indice,int limite)
{
    int retorno=-1;
    char auxNombre[128];
    char auxDireccion[128];
    int auxTipo;
    float auxPrecio;

    if(pAsociado != NULL && limite >0)
    {
        printf("Ingrese nombre de la pantalla:");
        if(getString(auxNombre,128)==0)
        {
            strncpy(pAsociado[indice].nombre,auxNombre,128);

            if(utn_getEntero(&auxTipo,2,"Ingrese el tipo(1 LCD,0 LED): ","Ese no es un tipo valido\n",2,-1)==0)
            {
                pAsociado[indice].tipo=auxTipo;

                if(utn_getNumeroDecimal(&auxPrecio,10,"Ingrese el precio de la Pantalla:","Ese no es un precio valido\n",4096,0)==0)
                {
                    pAsociado[indice].precio=auxPrecio;
                    printf("Ingrese la direccion: ");
                    if(getString(auxDireccion,128)==0)
                    {
                        strncpy(pAsociado[indice].direccion,auxDireccion,128);
                        pAsociado[indice].ID=generarID();
                        pAsociado[indice].isEmpty=0;
                        retorno =0;
                    }
                }

            }
        }
    }


    return retorno;
}

int aso_modificarIndice(Asociado* pAsociado,int id, int limite)
{
    int retorno=-1;
    char auxNombre[128];
    char auxDireccion[128];
    int auxTipo;
    float auxPrecio;
    int indice;
    indice=pan_buscarPantallaPorId(pAsociado,limite,id);
    if(indice >= 0)
    {
        if(pAsociado != NULL && limite >0)
        {
            printf("Ingrese el nuevo nombre de la pantalla:");
            if(getString(auxNombre,128)==0)
            {
                strncpy(pAsociado[indice].nombre,auxNombre,128);

                if(utn_getEntero(&auxTipo,2,"Ingrese el nuevo tipo(1 LCD,0 LED): ","Ese no es un tipo valido\n",2,-1)==0)
                {
                    pAsociado[indice].tipo=auxTipo;

                    if(utn_getNumeroDecimal(&auxPrecio,10,"Ingrese el nuevo precio de la Pantalla:","Ese no es un precio valido\n",4096,0)==0)
                    {
                        pAsociado[indice].precio=auxPrecio;
                        printf("Ingrese la direccion: ");
                        if(getString(auxDireccion,128)==0)
                        {
                            strncpy(pAsociado[indice].direccion,auxDireccion,128);
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

int aso_buscarPantallaPorId(Asociado* pAsociado,int limite,int id)
{
    int retorno=-1;
    int i;

    for(i=0;i<limite;i++)
    {
        if(pAsociado[i].isEmpty==0)
        {
            if(pAsociado[i].ID==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int aso_borrarPantalla(Asociado* pAsociado,int limite,int id)
{
    int retorno=-1;
    int i;

    for(i=0;i<limite;i++)
    {
        if(pAsociado[i].isEmpty==0)
        {
            if(pAsociado[i].ID==id)
            {
                pAsociado[i].isEmpty=-1;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int aso_mostrarIndices(Asociado* pAsociado,int limite)
{
    int retorno=-1;
    int i=0;
    if(pAsociado != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
                if(pAsociado[i].isEmpty==0)
                {
                    printf("\n-El ID de la pantalla es: %d", pAsociado[i].ID);
                    printf("\n-El nombre de la pantalla es: %s",pAsociado[i].nombre);
                    printf("\n-El tipo de la pantalla es(LCD:1, LED:0): %d ",pAsociado[i].tipo);
                    printf("\n-El precio de la pantalla es: %.2f por dia",pAsociado[i].precio);
                    printf("\n-La direccion de la pantalla es: %s\n",pAsociado[i].direccion);
                    retorno=0;
                }

        }

    }

    return retorno;
}

int aso_mostrarUnIndice(Asociado* pAsociado,int limite,int indice)
{
    int retorno=-1;
    if(pAsociado != NULL && limite > 0)
    {
        if(pAsociado[indice].isEmpty==0)
        {
            printf("\n-El ID de la pantalla es: %d", pAsociado[indice].ID);
            printf("\n-El nombre de la pantalla es: %s",pAsociado[indice].nombre);
            printf("\n-El tipo de la pantalla es(LCD:1, LED:0): %d ",pAsociado[indice].tipo);
            printf("\n-El precio de la pantalla es: %.2f por dia",pAsociado[indice].precio);
            printf("\n-La direccion de la pantalla es: %s\n",pAsociado[indice].direccion);
            retorno=0;
        }

    }

    return retorno;
}

static int generarID(void)
{
    static int cont = -1; //es privada de la funcion, además no muere
    return ++cont;
}
