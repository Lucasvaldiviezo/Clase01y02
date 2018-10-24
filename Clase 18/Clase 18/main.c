#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *pArchivo;
    pArchivo=fopen("archivo.ext","r");
    if(pArchivo!=NULL)
    {
        printf("Abrio");
        fclose(pArchivo);
    }else
    {
        printf("El archivo no existe");
    }

    return 0;
}
