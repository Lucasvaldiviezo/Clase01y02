#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "empleado.h"
#include "service.h"
void ordenar(void* lista[], int limite,int (*comparar)(void*,void*));

int main()
{
    /*Service* listaService[1000];
    int qtyServices=0;
    int i;

    for(i=0;i<100;i++)
    {
        listaService[i] = service_newConParametro(i+10,"Hola y chau");
        qtyServices++;
    }

    for(i=0;i<qtyServices;i++)
    {
        service_print(listaService[i]);
    }*/


    Empleado* listaEmpleados[1000];
    int qtyEmpleados=0;
    int i;
    char auxiliar[50];

    for(i=0;i<100;i++)
    {
        sprintf(auxiliar,"Juan_%d",i);
        listaEmpleados[i] = empleado_newConParametro(auxiliar,"Perez",1.45);
        qtyEmpleados++;
    }
    listaEmpleados[i] = empleado_newConParametro("AAAAA","Perez",1.45);
    qtyEmpleados++;
    ordenar((void*)listaEmpleados,qtyEmpleados,empleado_compareNombre);
    for(i=0;i<qtyEmpleados;i++)
    {
        empleado_print(listaEmpleados[i]);
    }


    return 0;
}

void ordenar(void* lista[], int limite,int (*comparar)(void*,void*))
{
    int flagSwap;
    int i;
    void* auxiliarPuntero;

    do
    {
        flagSwap=0;
        for(i=0;i<limite-1;i++)
        {
            if(empleado_compareNombre(lista[i],lista[i+1])>0)
            {
                auxiliarPuntero=lista[i];
                lista[i]=lista[i+1];
                lista[i+1]=auxiliarPuntero;
                flagSwap=1;
            }
        }
    }while(flagSwap);
}
