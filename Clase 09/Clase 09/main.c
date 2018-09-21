#include <stdio.h>
#include <stdlib.h>
#include "producto.h"
#define LIMITE 2
int main()
{
    Producto productos[LIMITE];
    int op;

    int j;
    int indiceVacio;
    int salir=0;
    cargarDatosVacio(productos,LIMITE);

    do
    {
    utn_getEntero(&op,3,"\n1-Cargar un producto\n2-Imprimir lista producto\n3-Salir\n","Error",4,0);
        switch(op)
        {
            case 1:

                    if(prod_getEmptyIndex(productos,LIMITE,&indiceVacio)==0)
                    {
                        printf("%d",indiceVacio);
                        cargarIndice(productos,indiceVacio,LIMITE);
                        break;
                    }
                    else
                    {
                        printf("No hay lugar");
                    }


                    break;
                case 2:
                    for(j=0;j<LIMITE;j++)
                    {
                        if(productos[j].isEmpty==0)
                        {
                            mostrarIndice(productos,j);
                            break;
                        }
                    }
                    break;
                case 3:
                salir = 1;

        }
    }while(salir==0);
    /*Producto productos[LIMITE];
    cargarDatosVacio(productos,LIMITE);
    cargarIndice(productos,0,LIMITE);
    mostrarIndice(productos,0);
    prod_getEmptyIndex(productos,LIMITE,&indiceVacio);
    printf("Lugar vacio: %d",indiceVacio);*/
    return 0;
}
