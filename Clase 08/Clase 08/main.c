#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"


int main()
{

    int data[5];
    int i;
    for(i=0;i<5;i++)
    {
        printf("Ingrese un numero\n");
        scanf("%d",&data[i]);
    }
    for(i=0;i<5;i++)
    {
        printf("Los datos son: %d\n",data[i]);
    }

    utn_insertion(data,5);

    for(i=0;i<5;i++)
    {
        printf("\nLos datos ordenados son: %d\n",data[i]);
    }

    return 0;
}


