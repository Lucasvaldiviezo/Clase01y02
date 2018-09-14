#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

/*struct S_Persona
{
    char nombre[70];
    int edad;
    char dni[20];
    float altura;
};*/
/*
tipos de datos propios ponerlos en mayuscula
Declaracion(TypeDef/Struct)
-R/W Campos (.)
-Definir Variable(TIPO NOMBRE) Persona P
*/

typedef struct
{
    char nombre[70];
    int edad;
    char dni[20];
    float altura;
}Persona;

int printPersona(Persona per);

int main()
{

    Persona p;
    p.edad=9;
    p.altura=1.90;
    //fgets(P.nombre,sizeof(P.nombre),stdin);
    strncpy(p.nombre,"Lucas",sizeof(p.nombre));
    strncpy(p.dni,"40091498",sizeof(p.dni));



    printPersona(p);


    /*int data[5];
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
    }*/

    return 0;
}

int printPersona(Persona per)
{
    printf("Su nombre es: %s\n",per.nombre);
    printf("Su DNI es: %s\n",per.dni);
    printf("Su edad es: %d\n",per.edad);
    printf("Su altura es: %.2f\n", per.altura);
    return 0;
}

