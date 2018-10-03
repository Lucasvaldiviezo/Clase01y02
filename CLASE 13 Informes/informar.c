#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "pantalla.h"
#include "informar.h"
#define QTY 10


int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit)
{
    int retorno = -1;

    return retorno;
}



int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}


int informar_OrdenarPantallasPorPrecioNombre(Pantalla* pantallas, int lenPantallas)
{
    int retorno=-1;
    int i;
    int j;
    Pantalla auxiliar;
    if(lenPantallas > 0 && pantallas != NULL)
    {
        for(i=0;i<lenPantallas-1;i++)
        {
            for(j=i+1;j<lenPantallas;j++)
            {
                if(pantallas[i].precio < pantallas[j].precio)
                {
                    auxiliar=pantallas[i];
                    pantallas[i]=pantallas[j];
                    pantallas[j]=auxiliar;
                }
                else if(pantallas[i].precio == pantallas[j].precio)
                {
                    if(strcmp(pantallas[i].nombre,pantallas[j].nombre)>0)
                    {
                        auxiliar=pantallas[i];
                        pantallas[i]=pantallas[j];
                        pantallas[j]=auxiliar;
                    }
                }
            }
        }
    }
    return retorno;
}

int informar_ListarPantallasMenoresIguales(Pantalla* pantallas,int lenPantallas, int valorComparativo)
{
    int retorno = -1;
    int i;
    int flag=0;
    if(pantallas != NULL && lenPantallas > 0)
    {
        retorno=0;
        for(i=0;i<lenPantallas;i++)
        {
            if(pantallas[i].isEmpty==0 && pantallas[i].precio <= valorComparativo)
            {
                pantalla_ImprimirPantallaUnica(pantallas,lenPantallas,i);
                flag=1;
            }
        }

    }
    if(flag==0)
    {
        printf("El precio de ninguna pantalla es menor o igual a: %d",valorComparativo);
    }

    return retorno;
}

int informar_ListarPantallasMayores(Pantalla* pantallas,int lenPantallas, int valorComparativo)
{
    int retorno = -1;
    int i;
    int flag=0;
    if(pantallas != NULL && lenPantallas > 0)
    {
        retorno=0;
        for(i=0;i<lenPantallas;i++)
        {
            if(pantallas[i].isEmpty==0 && pantallas[i].precio > valorComparativo)
            {
                pantalla_ImprimirPantallaUnica(pantallas,lenPantallas,i);
                flag=1;
            }
        }

    }
    if(flag==0)
    {
        printf("El precio de ninguna pantalla es menor o igual a: %d",valorComparativo);
    }

    return retorno;
}

int informar_ListarPantallasMayoresPromedio(Pantalla* pantallas,int lenPantallas, int valorComparativo)
{
    int retorno = -1;
    int i;
    int flag=0;
    if(pantallas != NULL && lenPantallas > 0)
    {
        retorno=0;
        for(i=0;i<lenPantallas;i++)
        {
            if(pantallas[i].isEmpty==0 && pantallas[i].precio > valorComparativo)
            {
                pantalla_ImprimirPantallaUnica(pantallas,lenPantallas,i);
                flag=1;
            }
        }

    }
    if(flag==0)
    {
        printf("El precio de ninguna pantalla es menor o igual a: %d",valorComparativo);
    }

    return retorno;
}
