#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "pantalla.h"
#include "informar.h"
#define QTY 10
static void  initInfoCliente(Contratacion* contrataciones, int lenContrataciones,InfoCliente* InfoC, int lenInfoC);
static int estaCuitEnInfoCliente(InfoCliente* InfoC, int lenInfoC,char* cuit);

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

InfoCliente arrayIC[1000];

static void initInfoCliente(Contratacion* contrataciones, int lenContrataciones,InfoCliente* infoC, int lenInfoC)
{
    int i;
    int proximoLibre=0;
    for(i=0;i<lenInfoC;i++)
    {
        infoC[i].isEmpty=-1;
    }

    for(i=0;i<lenContrataciones;i++)
    {
        if(estaCuitEnInfoCliente(infoC,lenInfoC,contrataciones[i].cuit)==0)
        {
            strcmp(infoC[proximoLibre].cuit,contrataciones[i].cuit);
            infoC[i].isEmpty=0;
            proximoLibre++;

        }
    }

}

static int estaCuitEnInfoCliente(InfoCliente* infoC, int lenInfoC,char* cuit)
{
    int i;
    int retorno=0;
    for(i=0;i<lenInfoC;i++)
    {
        if(infoC[i].isEmpty==0 && strcmp(infoC[i].cuit,cuit)==0)
        {
            retorno=-1;
        }
    }

    return retorno;
}

static void cargaInfoCliente(Contratacion* contraciones, int lenContraciones,
                            InfoCliente* infoC, int lenInfoC,
                            Pantalla* pantallas,int lenPantallas)
{

    int i;
    int j;

    Pantalla auxPantalla;
    for(i=0;i<lenInfoC;i++)
    {
        if(infoC[i].isEmpty==0)
        {
            int qtyContrataciones=0;
            //int infoC[i].importe=0;
            for(j=0;j<lenContraciones;j++)
            {
                if(strcmp(infoC[i].cuit,contraciones[j].cuit)==0)
                {
                    qtyContrataciones++;
                    //llamar al getById para obtener el ID de una pantalla
                    //auxPantalla=getPantallaByID(pantallas,lenPantallas,contraciones[i].idPantalla
                    //infoC[i].importe=auxPantalla->precio * contraciones[j].dias
                }
            }
            infoC[i].cantContrataciones=qtyContrataciones++;

        }
    }
}
