#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pantallas.h"
#include "contratacion.h"
#define PANTALLAS_MAX 100
#define CONTRATACIONES_MAX 1000
#define TEXTO_MENU "\n1)Cargar una pantalla\n\
2)Modificar una Pantalla\n\
3)Borrar una Pantalla\n\
4)Contratar una publicidad\n\
5)Modificar una contratacion\n\
6)Cancelar una Contratacion\n\
7)Consulta facturacion\n\
8)Imprimir Contrataciones\n\
9)Imprimir lista de Pantallas\n\
10)Salir\n"

int main()
{
    int indiceVacio;
    int opcion;
    int id;
    int salir=0;
    int indiceContratacion;
    char cuitVacio[20];
    Pantalla pantallas[PANTALLAS_MAX];
    Contratacion contrataciones[CONTRATACIONES_MAX];
    pan_cargarDatosVacio(pantallas,PANTALLAS_MAX);
    con_cargarDatosVacio(contrataciones,CONTRATACIONES_MAX);
    pan_cargarForzadaIndice(pantallas,PANTALLAS_MAX,"LG","OBELISCO",1,50);
    pan_cargarForzadaIndice(pantallas,PANTALLAS_MAX,"SAMSUNG","CABILDO",0,40);
    pan_cargarForzadaIndice(pantallas,PANTALLAS_MAX,"MSI","CORRIENTES",1,80);
    do
    {
    utn_getEntero(&opcion,3,TEXTO_MENU,"Error",11,0);
        switch(opcion)
        {
            case 1:
                if(pan_getEmptyIndex(pantallas,PANTALLAS_MAX,&indiceVacio)==0)
                {
                    pan_cargarIndice(pantallas,indiceVacio,PANTALLAS_MAX);
                }
                else
                {
                    printf("No hay lugar");
                }
                break;
            case 2:
                if(utn_getEntero(&id,10,"Ingrese el ID de la pantalla que desea modificar: ","Ese no es un ID valido\n",PANTALLAS_MAX,-1)==0)
                {
                    pan_modificarIndice(pantallas,id,PANTALLAS_MAX);
                }
                break;
            case 3:
                if(utn_getEntero(&id,10,"Ingrese el ID de la pantalla que desea borrar: ","Ese no es un ID valido\n",PANTALLAS_MAX,-1)==0)
                {
                    pan_borrarPantalla(pantallas,PANTALLAS_MAX,id);
                }
                break;
            case 4:
                pan_mostrarIndices(pantallas,PANTALLAS_MAX);
                if(utn_getEntero(&id,10,"\nIngrese el ID de la pantalla: ","Ese no es un ID valido",PANTALLAS_MAX,-1)==0)
                {
                    if(pan_buscarPantallaPorId(pantallas,PANTALLAS_MAX,id)!= -1)
                    {
                        if(con_getEmptyIndex(contrataciones,PANTALLAS_MAX,&indiceVacio)==0)
                        {
                            con_cargarIndice(contrataciones,indiceVacio,CONTRATACIONES_MAX,id);
                            break;
                        }
                        else
                        {
                            printf("No hay lugar");
                        }
                    }
                }else
                {
                    printf("Ese ID no existe.");
                }
                break;
            case 5:
                if(con_imprimirContratacionesCuit(contrataciones,CONTRATACIONES_MAX,pantallas,PANTALLAS_MAX,cuitVacio)==0)
                {
                    if(utn_getEntero(&id,10,"\nIngrese el ID de la pantalla: ","Ese no es un ID valido",9999,-1)==0)
                    {
                        if(pan_buscarPantallaPorId(pantallas,PANTALLAS_MAX,id)!= -1)
                        {
                                indiceContratacion=con_buscarContratacionPorIdyCuit(contrataciones,CONTRATACIONES_MAX,id,cuitVacio);
                                con_modificarIndice(contrataciones,indiceContratacion,CONTRATACIONES_MAX);
                        }
                    }else
                    {
                        printf("Ese ID no existe.");
                    }
                }else
                {
                    printf("El CUIT no existe o no tiene contrataciones");
                }
                break;
            case 6:
                if(con_imprimirContratacionesCuit(contrataciones,CONTRATACIONES_MAX,pantallas,PANTALLAS_MAX,cuitVacio)==0)
                {
                    if(utn_getEntero(&id,10,"\nIngrese el ID de la pantalla: ","Ese no es un ID valido",PANTALLAS_MAX,-1)==0)
                    {
                        if(pan_buscarPantallaPorId(pantallas,PANTALLAS_MAX,id) != -1)
                        {
                                indiceContratacion=con_buscarContratacionPorIdyCuit(contrataciones,CONTRATACIONES_MAX,id,cuitVacio);
                                con_borrarContratacion(contrataciones,CONTRATACIONES_MAX,indiceContratacion);
                        }
                    }else
                    {
                        printf("Ese ID no existe.");
                    }
                }else
                {
                    printf("El CUIT no existe o no tiene contrataciones");
                }
                break;
            case 7:
                con_calcularFacturaciones(contrataciones,CONTRATACIONES_MAX,pantallas,PANTALLAS_MAX);
                break;
            case 8:
                con_mostrarIndices(contrataciones,CONTRATACIONES_MAX,pantallas,PANTALLAS_MAX);
                break;
            case 9:
                pan_mostrarIndices(pantallas,PANTALLAS_MAX);
                break;
            case 10:
            salir = 1;

        }
    }while(salir==0);

    return 0;
}
