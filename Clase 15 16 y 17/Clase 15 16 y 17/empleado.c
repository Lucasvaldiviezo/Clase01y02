#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include <ctype.h>
static int isValidNombre(char* nombre);
static int isValidApellido(char* apellido);
static int isValidAltura(float altura);

Empleado* empleado_new(void)
{

    return (Empleado*) malloc(sizeof(Empleado));
}

void empleado_delete(Empleado* this)
{
    free(this);
}

int empleado_setNombre(Empleado* this,char* nombre)
{
    int retorno=-1;

    if(this != NULL && isValidNombre(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }

    return retorno;
}

int empleado_getNombre(Empleado* this,char* nombre)
{
    int retorno=-1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }

    return retorno;
}

static int isValidNombre(char* nombre)
{
    int retorno=1;
    return retorno;
}

int empleado_compareEmpleado(Empleado* thisA, Empleado* thisB)
{
    return strcmp(thisA->nombre,thisB->nombre);
}

int empleado_setApellido(Empleado* this,char* apellido)
{
    int retorno=-1;

    if(this != NULL && isValidApellido(apellido))
    {
        strcpy(this->apellido,apellido);
        retorno=0;
    }

    return retorno;
}

int empleado_getApellido(Empleado* this,char* apellido)
{
    int retorno=-1;

    if(this != NULL && apellido != NULL)
    {
        strcpy(apellido,this->apellido);
        retorno=0;
    }

    return retorno;
}

static int isValidApellido(char* apellido)
{
    int retorno=1;
    return retorno;
}

int empleado_setAltura(Empleado* this,float altura)
{
    int retorno=-1;

    if(this != NULL && isValidAltura(altura))
    {
        this->altura=altura;
        retorno=0;
    }

    return retorno;
}

int empleado_getAltura(Empleado* this,float* altura)
{
    int retorno=-1;

    if(this != NULL && altura != NULL)
    {
        *altura=this->altura;
        retorno=0;
    }

    return retorno;
}

static int isValidAltura(float altura)
{
    int retorno=1;
    return retorno;
}

