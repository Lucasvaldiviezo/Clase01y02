#include <stdio_ext.h>
#include <stdlib.h>
#include "Compra.h"
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "utn.h"
static int isValidNombre(char* nombre);
static int isValidId(char* employeeId);
static int isValidPrecioUnitario(char* precioUnitario);
static int isValidUnidades(char* precioUnitario);
static int isValidIva(char* precioUnitario);
static int isValidMontoTotal(char* precioUnitario);

Compra* Compra_new()
{
    Compra* this;
    this=malloc(sizeof(Compra));
    return this;
}

void Compra_delete(Compra* this)
{
    free(this);
}

Compra* Compra_newConParametros(char* nombreCliente,char* idProducto,char* precioUnitario,char* unidades,char* iva)
{
    Compra* p;
    p=Compra_new();
    if(p!=NULL)
    {
        if( Compra_setNombreCliente(p,nombreCliente)==-1 ||
            Compra_setIdProducto(p,idProducto)==-1 ||
            Compra_setPrecioUnitario(p,precioUnitario) == -1 ||
            Compra_setUnidades(p,unidades)==-1 ||
            Compra_setIva(p,iva)==-1)
        {
            Compra_delete(p);
            p=NULL;
        }
    }
    return p;
    return NULL;
}

int Compra_setNombreCliente(Compra* this,char* nombreCliente)
{
    int retorno=-1;
    if(this!=NULL && nombreCliente!=NULL && isValidNombre(nombreCliente)==0)
    {
        strcpy(this->nombreCliente,nombreCliente);
        retorno=0;
    }
    printf("El retorno de nombre es: %d\n",retorno);
    return retorno;
}

int Compra_getNombreCliente(Compra* this,char* nombreCliente)
{
    int retorno=-1;
    if(this!=NULL && nombreCliente!=NULL)
    {
        strcpy(nombreCliente,this->nombreCliente);
        retorno=0;
    }
    return retorno;
}

static int isValidNombre(char* nombre)
{
    int i=0;
    int retorno=0;
    int flag=0;
    while(nombre[i] != '\0')
    {
        if(flag==0)
        {
            nombre[i]=toupper(nombre[i]);
            flag=1;
        }else if ((nombre[i] < 'A' || nombre[i] > 'Z') &&
                (nombre[i] < 'a' || nombre[i] > 'z'))
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}

int Compra_setIdProducto(Compra* this,char* idProducto)
{
    int retorno=-1;
    if(this!=NULL && isValidId(idProducto)==0)
    {
        this->idProducto=atoi(idProducto);
        retorno=0;
    }
    printf("El retorno de Id es: %d\n",retorno);
    return retorno;
}

int Compra_getIdProducto(Compra* this,int* idProducto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idProducto=this->idProducto;
        retorno=0;
    }
    return retorno;
}

static int isValidId(char* idProducto)
{
    int i=0;
    int retorno=0;
    int contadorDeGuiones=0;
    while(idProducto[i] != '\0')
    {
        if(idProducto[i] == '-' && contadorDeGuiones==0)
        {
            contadorDeGuiones++;
            i++;
            continue;
        }
        if(idProducto[i] < '0' || idProducto[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}

int Compra_setPrecioUnitario(Compra* this,char* precioUnitario)
{
    int retorno=-1;
    if(this != NULL && isValidPrecioUnitario(precioUnitario)==0)
    {
        this->precioUnitario=atof(precioUnitario);
        retorno=0;
    }
    printf("El retorno de Precio unitario es: %d\n",retorno);
    return retorno;
}

int Compra_getPrecioUnitario(Compra* this,float* precioUnitario)
{
    int retorno=-1;
    if(this!=NULL && precioUnitario != NULL)
    {
        *precioUnitario=this->precioUnitario;
        retorno=0;
    }
    return retorno;
}

static int isValidPrecioUnitario(char* precioUnitario)
{
    int i=0;
    int retorno=0;
    int contadorDePuntos=0;
    while(precioUnitario[i] != '\0')
    {
        if(precioUnitario[i] == '.' && contadorDePuntos==0)
        {
            contadorDePuntos++;
            i++;
            continue;
        }
        if(precioUnitario[i] < '0' || precioUnitario[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}

int Compra_setUnidades(Compra* this,char* unidades)
{
    int retorno=-1;
    if(this!=NULL && isValidUnidades(unidades)==0)
    {
        this->unidades=atoi(unidades);
        retorno=0;
    }
        printf("El retorno de unidades es: %d\n",retorno);
    return retorno;
}

int Compra_getUnidades(Compra* this,int* unidades)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *unidades=this->unidades;
        retorno=0;
    }
    return retorno;
}

static int isValidUnidades(char* unidades)
{
    int i=0;
    int retorno=0;
    while(unidades[i] != '\0')
    {
        if(unidades[i] < '0' || unidades[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}

int Compra_setIva(Compra* this,char* iva)
{
    int retorno=-1;
    if(this!=NULL && isValidIva(iva)==0)
    {
        this->iva=atof(iva);
        retorno=0;
    }
        printf("El retorno de Iva es: %d\n",retorno);
    return retorno;
}

int Compra_getIva(Compra* this,float* iva)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *iva=this->iva;
        retorno=0;
    }
    return retorno;
}

static int isValidIva(char* iva)
{
    int i=0;
    int retorno=0;
    int contadorDePuntos=0;
    while(iva[i] != '\0')
    {
        if(iva[i] == '.' && contadorDePuntos==0)
        {
            contadorDePuntos++;
            i++;
            continue;
        }
        if(iva[i] < '0' || iva[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}


int Compra_setMontoTotal(Compra* this,char* montoTotal)
{
    int retorno=-1;
    if(this!=NULL && isValidMontoTotal(montoTotal)==0)
    {
        this->montoTotal=atof(montoTotal);
        retorno=0;
    }
        printf("El retorno de monto total es: %d\n",retorno);
    return retorno;
}

int Compra_getMontoTotal(Compra* this,float* montoTotal)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *montoTotal=this->montoTotal;
        retorno=0;
    }
    return retorno;
}

static int isValidMontoTotal(char* montoTotal)
{
    int i=0;
    int retorno=0;
    int contadorDePuntos=0;
    while(montoTotal[i] != '\0')
    {
        if(montoTotal[i] == '.' && contadorDePuntos==0)
        {
            contadorDePuntos++;
            i++;
            continue;
        }
        if(montoTotal[i] < '0' || montoTotal[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}

int compra_buscarPorId(LinkedList* listaCompras, int idProducto)
{
    int retorno=-1;
    int i;
    Compra* auxCompra;
    int size=ll_len(listaCompras);
    if(listaCompras!=NULL)
    {
        for(i=0;i<size;i++)
        {
            auxCompra=ll_get(listaCompras,i);
            if(auxCompra!=NULL && auxCompra->idProducto== idProducto)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int compras_ProductoSeleccionado(void* pProducto,void* idProducto)
{
    int retorno=-1;

    if(((Compra*)pProducto)->idProducto == idProducto)
    {
        retorno=0;
    }
    return retorno;


}

