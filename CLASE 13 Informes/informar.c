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
    int flagSwap;
    Pantalla auxiliar;
    if(lenPantallas > 0 && pantallas != NULL)
    {
        retorno=0;
        do
        {
            flagSwap=0;
            for(i=0;i<lenPantallas-1;i++)
            {
                if((pantallas[i].precio < pantallas[i+1].precio) ||
                  (pantallas[i].precio == pantallas[i+1].precio && strcmp(pantallas[i].nombre,pantallas[i+1].nombre)>0))
                {
                    flagSwap=1;
                    auxiliar=pantallas[i];
                    pantallas[i]=pantallas[i+1];
                    pantallas[i+1]=auxiliar;
                }
            }
        }while(flagSwap==1);

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
        printf("El precio de ninguna pantalla es mayor a: %d",valorComparativo);
    }

    return retorno;
}


