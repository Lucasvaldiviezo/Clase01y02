#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"

#define DEFINE_DEL_ARCHIVO  "hola"

//Funciones privadas
static int proximoId(void);
static int buscarLugarLibre(Pantalla* array,int limite);
//__________________



/** \brief
 * \param array Pantalla*
 * \param limite int
 * \return int
 *
 */
int pantalla_init(Pantalla* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

int pantalla_mostrarDebug(Pantalla* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d - %s - %s - %f - %d - %d\n",array[i].idPantalla, array[i].nombre,array[i].direccion,array[i].precio,array[i].tipo, array[i].isEmpty);
        }
    }
    return retorno;
}

int pantalla_mostrar(Pantalla* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("[RELEASE] - %d - %s - %d\n",array[i].idPantalla, array[i].nombre, array[i].isEmpty);
        }
    }
    return retorno;
}

int pantalla_alta(Pantalla* array,int limite)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char direccion[50];
    float precio;
    int tipo;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
            {
                if(!getValidString("\nDireccion? ","\nEso no es un direccion","El maximo es 40",direccion,40,2))
                {
                    if(!getValidFloat("\nPrecio? ","\nEso no es un precio",&precio,0,9999999,2))
                    {
                        if(!getValidInt("\nTipo? ","\nEso no es un precio",&tipo,0,1,2))
                        {
                            retorno = 0;
                            strcpy(array[i].nombre,nombre);
                            strcpy(array[i].direccion,direccion);
                            array[i].precio = precio;
                            array[i].tipo = tipo;
                            //------------------------------
                            //------------------------------
                            array[i].idPantalla = proximoId();
                            array[i].isEmpty = 0;
                        }
                    }
                }
            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


int pantalla_baja(Pantalla* array,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = pantalla_buscarPorId(array,limite,id);
    if(indiceAEliminar>=0)
    {
        array[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}




int pantalla_modificacion(Pantalla* array,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char buffer[50];

    indiceAModificar = pantalla_buscarPorId(array,limite,id);
    if(indiceAModificar>=0)
    {
        if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",buffer,40,2))
        {
            retorno = 0;
            strcpy(array[indiceAModificar].nombre,buffer);
            //------------------------------
            //TODO
        }
        else
        {
            retorno = -3;
        }
    }
    return retorno;
}

int pantalla_ordenar(Pantalla* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Pantalla auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

static int buscarLugarLibre(Pantalla* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}


int pantalla_buscarPorId(Pantalla* array,int limite, int id)
//static int buscarPorId(Pantalla* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPantalla==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



int pantalla_altaForzada(Pantalla* array,int limite,char* nombre,char* direccion, float precio, int tipo)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombre,nombre);
            strcpy(array[i].direccion,direccion);
            array[i].precio = precio;
            array[i].tipo = tipo;
            //------------------------------
            //------------------------------
            array[i].idPantalla = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

int pantalla_ImprimirPantallaUnica(Pantalla* pantallas,int lenPantallas,int indice)
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

int pantalla_ListarPantallas(Pantalla* pantallas,int lenPantallas)
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








