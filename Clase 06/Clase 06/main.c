#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
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
    /*int num;

    if(utn_getEntero(&num,1,"Ingrese numero: \n","Hay una letra\n",999,0)==0)
    {
        printf("\nEl numero ingresado es: %d",num);
    }*/
    char mayorMenor;
    int i=0;
    int edades[CANTIDAD_EMPLEADOS];
    for(i=0;i< CANTIDAD_EMPLEADOS;i++)
    {

        utn_getEntero(&edades[i],1,"Ingrese la edad: \n", "Esa no es una edad\n",200,0);
        /*if(utn_getEntero(&edades[i],1,"Ingrese la edad: \n", "Esa no es una edad\n",200,0)==-1)
        {
            edades[i]=-1;
        }*/

    }
    printf("En que orden desea el array?\n > de menor a mayor.\n < de mayor a menor. \n");
    __fpurge(stdin);
    scanf("%c",&mayorMenor);

    printf("\nEl array original es: ");
    utn_mostrarArray(edades,CANTIDAD_EMPLEADOS);

    if(utn_ordenarArray(edades,CANTIDAD_EMPLEADOS,mayorMenor)==-1)
    {
       printf("\n\nEl limite o el array estan mal. ");
    }else
    {
        printf("\n\nEl array ordenado es: ");
        utn_mostrarArray(edades,CANTIDAD_EMPLEADOS);

    }



    return 0;
}


