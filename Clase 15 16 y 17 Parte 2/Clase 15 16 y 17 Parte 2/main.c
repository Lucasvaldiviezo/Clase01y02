#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#define CANT_CLIENTES 100

int main()
{
    Cliente* listaClientes[CANT_CLIENTES];
    Cliente* auxCliente;
    char nombreAux[64];
    int indexVacio;

    cliente_inicializarArray(listaClientes,CANT_CLIENTES);
    auxCliente=cliente_new();
    indexVacio=cliente_buscarLugarVacio(listaClientes,CANT_CLIENTES);
    if(auxCliente!=NULL)
    {
        cliente_setNombre(auxCliente,"Juan");
        listaClientes[indexVacio]=auxCliente;
        cliente_getNombre(listaClientes[indexVacio],nombreAux);
        printf("%s",nombreAux);
    }
    return 0;
}
