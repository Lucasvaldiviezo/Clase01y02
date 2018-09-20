#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "utn.h"

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

int printPersona(Persona* per);
int altaPersona(Persona* per);
int getString(char* pBufferString,char* msg,int limite);

int main()
{
    float numero;
    int numeroEntero;
    int i;
    char telefono[10];
    Persona p;
    /*p.edad=9;
    p.altura=1.90;
    //fgets(P.nombre,sizeof(P.nombre),stdin);
    strncpy(p.nombre,"Lucas",sizeof(p.nombre));
    strncpy(p.dni,"40091498",sizeof(p.dni));*/

    utn_getTelefono(telefono,"Ingrese su telefono con un guion en el medio: \n","Ese no es un telefono\n");
    printf("Su telefono es: %s\n",telefono);


    //altaPersona(&p);
    //printPersona(&p);
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
int altaPersona(Persona* per)
{
    char nombreAux[70];
    char dniAux[20];
    int edadAux;
    float alturaAux;
    getString(nombreAux,"Ingrese nombre: ",70);
    getString(dniAux,"Ingrese DNI: ",20);
    scanf("%d",&per->edad);
    scanf("%f",&per->altura);

    strncpy(per->dni,dniAux,20);
    strncpy(per->nombre,nombreAux,70);

    return 0;
}
int printPersona(Persona* per)
{
    printf("Su nombre es: %s\n",per->nombre);
    printf("Su DNI es: %s\n",per->dni);
    printf("Su edad es: %d\n",per->edad);
    printf("Su altura es: %.2f\n", per->altura);
    return 0;
}

int getString(char* pBufferString,char* msg,int limite)
{
    fflush(stdin);
    printf(msg);
    fgets(pBufferString,limite,stdin);
    if(pBufferString[strlen(pBufferString)-1]=='\n')
    {
        pBufferString[strlen(pBufferString)-1]='\0';
    }
    return 0;
}
