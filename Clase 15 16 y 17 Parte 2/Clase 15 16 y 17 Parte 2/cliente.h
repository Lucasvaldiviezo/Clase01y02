#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    char nombre[64];
    char apellido[64];
    int clienteId;
}Cliente;

Cliente* cliente_new(void);
int cliente_setNombre(Cliente* this,char* nom);
int cliente_getNombre(Cliente* this,char* nom);
int cliente_setApellido(Cliente* this,char* ape);
int cliente_getApellido(Cliente* this,char* ape);
int cliente_setId(Cliente* this,int idCliente);
int cliente_getId(Cliente* this,int* idCliente);
#endif // CLIENTE_H_INCLUDED
