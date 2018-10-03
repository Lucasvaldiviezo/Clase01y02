#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "pantalla.h"
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
int informar_ImprimirPantallaUnica(Pantalla* pantallas,int lenPantallas,int indice)
{
    int retorno = -1;
    if(lenPantallas > 0 && pantallas != NULL && indice >= 0 && indice <= lenPantallas)
    {

        if(!pantallas[indice].isEmpty)
        {
            printf("\nEl Id de la pantalla es: %d\n",pantallas[indice].idPantalla);
            printf("El nombre de la pantalla es: %s\n",pantallas[indice].nombre);
            printf("La direccion de la pantalla es: %s\n",pantallas[indice].direccion);
            printf("El precio de la pantalla es: %.2f\n",pantallas[indice].precio);
            printf("El tipo de la pantalla es: %d\n",pantallas[indice].tipo);
            retorno = 0;
        }

    }
    return retorno;
}
int informar_ListarPantallas(Pantalla* pantallas,int lenPantallas)
{
    int retorno = -1;
    int i;
    if(lenPantallas > 0 && pantallas != NULL)
    {
        retorno = 0;
        for(i=0;i<lenPantallas;i++)
        {
            if(!pantallas[i].isEmpty)
            {
                printf("\nEl Id de la pantalla es: %d\n",pantallas[i].idPantalla);
                printf("El nombre de la pantalla es: %s\n",pantallas[i].nombre);
                printf("La direccion de la pantalla es: %s\n",pantallas[i].direccion);
                printf("El precio de la pantalla es: %.2f\n",pantallas[i].precio);
                printf("El tipo de la pantalla es: %d\n",pantallas[i].tipo);

            }

        }
    }
    return retorno;
}

int informar_OrdenarPantallasPorPrecio(Pantalla* pantallas, int lenPantallas)
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
                informar_ImprimirPantallaUnica(pantallas,lenPantallas,i);
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
