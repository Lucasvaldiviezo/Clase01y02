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
    /*char saludo[4];
    saludo[0]='h';
    saludo[1]='o';
    saludo[2]='l';
    saludo[3]='a';*/
    int num;

    if(utn_getEntero(&num,1,"Ingrese numero: \n","Hay una letra\n",999,0)==0)
    {
        printf("%d",num);
    }



    return 0;
}


