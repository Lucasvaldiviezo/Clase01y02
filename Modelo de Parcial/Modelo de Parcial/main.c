#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pantallas.h"
#define PANTALLAS_MAX 100
#define CONTRATACIONES_MAX 1000

int main()
{
    int indiceVacio;
    int i;
    int opcion;
    int id;
    int salir=0;
    Pantalla pantallas[PANTALLAS_MAX];
    pan_cargarDatosVacio(pantallas,PANTALLAS_MAX);
    do
    {
    utn_getEntero(&opcion,3,"\n1)Cargar una pantalla\n2)Imprimir lista de pantallas\n3)Modificar una pantalla\n4)Borrar una pantalla\n5)Salir\n","Error",6,0);
        switch(opcion)
        {
            case 1:

                    if(pan_getEmptyIndex(pantallas,PANTALLAS_MAX,&indiceVacio)==0)
                    {
                        pan_cargarIndice(pantallas,indiceVacio,PANTALLAS_MAX);
                        break;
                    }
                    else
                    {
                        printf("No hay lugar");
                    }


                    break;
                case 2:
                    for(i=0;i<PANTALLAS_MAX;i++)
                    {
                        if(pantallas[i].isEmpty==0)
                        {
                            pan_mostrarIndice(pantallas,i);
                        }
                    }
                    break;
                case 3:
                    if(utn_getEntero(&id,10,"Ingrese el ID de la pantalla que desea modificar: ","Ese no es un ID valido\n",PANTALLAS_MAX,-1)==0)
                    {
                        pan_modificarIndice(pantallas,id,PANTALLAS_MAX);
                    }
                    break;
                case 4:
                    if(utn_getEntero(&id,10,"Ingrese el ID de la pantalla que desea borrar: ","Ese no es un ID valido\n",PANTALLAS_MAX,-1)==0)
                    {
                        pan_borrarPantalla(pantallas,PANTALLAS_MAX,id);
                    }
                    break;
                case 5:
                salir = 1;

        }
    }while(salir==0);

    return 0;
}
