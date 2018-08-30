#include <stdio_ext.h>
#include <stdlib.h>


int getEdad(int* pEdad);

int main()
{
    int edad;

    if(getEdad(&edad) == 0)
    {
        printf("La edad es: %d", edad);
    }
    return 0;
}

int getEdad(int* pEdad)
{
    int auxiliarEdad;
    int retorno = -1;
    int reintentos;
    for(reintentos=3;reintentos>0;reintentos--)
    {
        printf("Ingrese la edad: ");
        if(scanf("%d",&auxiliarEdad) == 1)
        {
            if(auxiliarEdad >= 0 && auxiliarEdad < 199)
            {
                *pEdad = auxiliarEdad;
                retorno = 0;
                break;
            }else
            {
                printf("La edad esta fuega de rango [0-199]\n");
            }

        }else
        {
            printf("La edad es numerica \n");
            __fpurge(stdin);
        }
    }


    return retorno;
}
