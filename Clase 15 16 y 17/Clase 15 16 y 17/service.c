#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "service.h"
#include <ctype.h>

static int isValidGravedad(int gravedad);
static int isValidMensaje(char* mensaje);
static int isValidServiceId(int id);

Service* service_new(void)
{

    return (Service*) malloc(sizeof(Service));
}

Service* service_newConParametro(int gravedad, char* mensaje)
{
    Service* this = NULL;
    this=service_new();
    if( this == NULL ||
        service_setGravedad(this,gravedad) ||
        service_setMensaje(this,mensaje) ||
        service_setServiceId(this))
    {
        service_delete(this);
        this = NULL;
    }

    return this;
}

void service_delete(Service* this)
{
    free(this);
}

void service_print(Service* this)
{
    if(this != NULL)
    {
        printf("\nGravedad:%d - Mensaje:%s - Service ID:%d ",this->gravedad,this->mensaje,this->serviceId);
    }

}

int service_setGravedad(Service* this,int gravedad)
{
    int retorno=-1;

    if(this != NULL && isValidGravedad(gravedad))
    {
        this->gravedad=gravedad;
        retorno=0;
    }

    return retorno;
}

int service_getGravedad(Service* this,int* gravedad)
{
    int retorno=-1;

    if(this != NULL && gravedad != NULL)
    {
        *gravedad=this->gravedad;
        retorno=0;
    }

    return retorno;
}

static int isValidGravedad(int gravedad)
{
    int retorno=1;
    return retorno;
}

int service_compareGravedad(Service* thisA, Service* thisB)
{
    int retorno=0;

    if(thisA->gravedad > thisB->gravedad)
    {
        retorno=1;
    }else if (thisA->gravedad < thisB->gravedad)
    {
        retorno=-1;
    }
    return retorno;
}

int service_setMensaje(Service* this,char* mensaje)
{
    int retorno=-1;

    if(this != NULL && isValidMensaje(mensaje))
    {
        strcpy(this->mensaje,mensaje);
        retorno=0;
    }

    return retorno;
}

int service_getMensaje(Service* this,char* mensaje)
{
    int retorno=-1;

    if(this != NULL && mensaje != NULL)
    {
        strcpy(mensaje,this->mensaje);
        retorno=0;
    }

    return retorno;
}

static int isValidMensaje(char* mensaje)
{
    int retorno=1;
    return retorno;
}

int service_compareMensaje(Service* thisA, Service* thisB)
{
    return strcmp(thisA->mensaje,thisB->mensaje);
}

int service_setServiceId(Service* this)
{
    int retorno=-1;
    static int serviceIdCont=-1;
    //es privada de la funcion, además no muere
    if(this != NULL)
    {
        serviceIdCont++;
        if(isValidServiceId(serviceIdCont))
        {
            this->serviceId=serviceIdCont;
            retorno=0;
        }

    }

    return retorno;
}

int service_getServiceId(Service* this,int* serviceId)
{
    int retorno=-1;

    if(this != NULL && serviceId != NULL)
    {
        *serviceId=this->serviceId;
        retorno=0;
    }

    return retorno;
}

static int isValidServiceId(int id)
{
    int retorno=1;
    return retorno;
}
