#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "array.h"
#define CANTIDAD_EMPLEADOS 5
#define DATO_INVALIDO -1

//&salario[0];Esta bien,pero es muy largo
//salario; => &salario[60] desde donde quiero la direccion de memoria
//void fun(int pA[],int limite) Asi tambien se puede recibir un array
//auxiliar=*(pArray + i) es otra forma de leer el indice actual

int main()
{
    int edades[CANTIDAD_EMPLEADOS];
    int i;
    int maximo;
    int minimo;
    float promedio;

    while(utn_inicializarArray(edades,DATO_INVALIDO,CANTIDAD_EMPLEADOS)==-1)
    {
        printf("La direccion del array esta mal");
    }

    for(i=0;i< CANTIDAD_EMPLEADOS;i++)
    {

        utn_getEntero(&edades[i],1,"Ingrese la edad: \n", "Esa no es una edad\n",200,0);
        /*if(utn_getEntero(&edades[i],1,"Ingrese la edad: \n", "Esa no es una edad\n",200,0)==-1)
        {
            edades[i]=-1;
        }*/

    }

    utn_mostrarArray(edades,CANTIDAD_EMPLEADOS);
    //utn_mostrarArray(edades+2,CANTIDAD_EMPLEADOS-2);
    utn_calcularMaximoArray(edades,CANTIDAD_EMPLEADOS,&maximo);
    utn_calcularMinimoArray(edades,CANTIDAD_EMPLEADOS,&minimo);
    utn_promedioArray(edades,CANTIDAD_EMPLEADOS,&promedio);
    printf("\n\nEl maximo es: %d\n",maximo);
    printf("\nEl minimo es: %d\n",minimo);
    printf("\nEl promedio es: %.2f\n",promedio);
    return 0;
}


