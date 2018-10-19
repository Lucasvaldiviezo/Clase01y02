#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
static int isValidNombre(char* nom);
static int isValidApellido(char* ape);
static int isValidId(int clienteId);

Cliente* cliente_new(void)
{
    return (Cliente*) malloc(sizeof(Cliente));
}

int cliente_setNombre(Cliente* this,char* nom)
{
    int retorno=0;
    //validar!!
    if(this != NULL && isValidNombre(nom))
    {
        strncpy(this->nombre,nom,sizeof(this->nombre));
    }
    return retorno;
}

int cliente_getNombre(Cliente* this,char* nom)
{
    int retorno=0;
    //validar!!
    if(this != NULL && nom != NULL)
    {
        strncpy(nom,this->nombre,sizeof(this->nombre));
    }
    return retorno;
}

static int isValidNombre(char* nom)
{
    return 1;
}

int cliente_setApellido(Cliente* this,char* ape)
{
    int retorno=0;
    //validar!!
    if(this != NULL && isValidApellido(ape))
    {
        strncpy(this->apellido,ape,sizeof(this->apellido));
    }

    return retorno;
}

int cliente_getApellido(Cliente* this,char* ape)
{
    int retorno=0;
    //validar!!
    if(this != NULL && ape != NULL)
    {
        strncpy(ape,this->apellido,sizeof(this->apellido));
    }

    return retorno;
}

static int isValidApellido(char* ape)
{
    return 1;
}

int cliente_setId(Cliente* this,int idCliente)
{
    int retorno=0;
    //validar!!
    if(this != NULL && isValidId(idCliente))
    {
        this->clienteId=idCliente;
    }
    return retorno;
}

int cliente_getId(Cliente* this,int* idCliente)
{
    int retorno=0;
    //validar!!
     if(this != NULL && idCliente != NULL)
     {
        *idCliente=this->clienteId;

     }
    return retorno;
}

static int isValidId(int clienteId)
{
    return 1;
}
