#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#define CANT_CLIENTES 100

int main()
{
    Cliente* listaClientes[CANT_CLIENTES];
    Cliente* auxCliente;
    int i;
    for(i=0;i<CANT_CLIENTES;i++)
    {
        listaClientes[i]=NULL;
    }
    auxCliente=cliente_new();
    if(auxCliente!=NULL)
    {
        cliente_setNombre(auxCliente,"Juan");
        listaClientes[0]=auxCliente;
    }
    return 0;
}
