#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    char nombre[50];
    char apellido[50];
    int clienteId;
}Cliente;

Cliente* cliente_new(void);

#endif // CLIENTE_H_INCLUDED
