#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

Cliente* cliente_new(void)
{
    return (Cliente*) malloc(sizeof(Cliente));
}
