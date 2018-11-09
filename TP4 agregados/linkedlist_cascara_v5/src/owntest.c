#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "../testing/inc/Employee.h"
#define CANT_EMPLEADOS 10
#include "owntest.h"

void testFilter(void)
{
    LinkedList* test;
    test=ll_newLinkedList();
    LinkedList* newTest;
    Employee* auxEmployee;
    int i;
    int size;
    if(test != NULL)
    {
        printf("La lista sin filtrar es: \n");
        for(i=0;i<CANT_EMPLEADOS;i++)
        {
            auxEmployee=newEmployee(i,"Carlitos","Andromeda",6995+i,i);
            ll_add(test,auxEmployee);
        }
        for(i=0;i<CANT_EMPLEADOS;i++)
        {
            auxEmployee=ll_get(test,i);
            printf("Nombre: %s,Sueldo: %.2f\n",auxEmployee->name,auxEmployee->salary);
        }
        newTest=ll_filter(test,compareEmployee2,1);
        if(newTest!=NULL)
        {
            size=ll_len(newTest);
            printf("\nLa lista filtrada es:\n");
            for(i=0;i<size;i++)
            {
                auxEmployee=ll_get(newTest,i);
                if(auxEmployee!=NULL)
                {
                    printf("Nombre: %s,Sueldo: %.2f\n",auxEmployee->name,auxEmployee->salary);
                }else
                {
                    printf("Es NULL\n");
                }
            }
        }
    }

}

void testStarNext(void)
{
    LinkedList* test;
    LinkedList* test2;
    test=ll_newLinkedList();
    test2=ll_newLinkedList();
    Employee* auxEmployee;
    int i;
    if(test != NULL)
    {
        printf("La lista es: \n");
        for(i=0;i<CANT_EMPLEADOS;i++)
        {
            auxEmployee=newEmployee(i,"Carlitos","Andromeda",6995+i,i);
            ll_add(test,auxEmployee);
        }
        for(i=0;i<CANT_EMPLEADOS;i++)
        {
            auxEmployee=newEmployee(i,"Perez","Antonio",10+i,i);
            ll_add(test2,auxEmployee);
        }
        ll_startIterate(test);
        ll_startIterate(test2);
        for(i=0;i<CANT_EMPLEADOS;i++)
        {
            auxEmployee=ll_getNext(test);
            if(auxEmployee!=NULL)
            {
                printf("Nombre: %s,Sueldo: %.2f\n",auxEmployee->name,auxEmployee->salary);
            }

        }
        for(i=0;i<CANT_EMPLEADOS;i++)
        {
            auxEmployee=ll_getNext(test2);
            if(auxEmployee!=NULL)
            {
                printf("Nombre: %s,Sueldo: %.2f\n",auxEmployee->name,auxEmployee->salary);
            }

        }
    }

}
