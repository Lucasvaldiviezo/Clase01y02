#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include <ctype.h>

static int isValidName(char* name);

User* user_new(void)
{

    return (User*) malloc(sizeof(User));
}

void user_delete(User* this)
{
    free(this);
}

int user_setName(User* this,char* name)
{
    int retorno=-1;

    if(this != NULL && isValidName(name))
    {
        strcpy(this->name,name);
        retorno=0;
    }

    return retorno;
}

static int isValidName(char* name)
{
    int retorno=1;
    return retorno;
}


