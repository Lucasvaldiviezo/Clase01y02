#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferApellido[1024];
    FILE *pArchivo;
/*    pArchivo=fopen("archivo.ext","w");
    if(pArchivo!=NULL)
    {
        fprintf(pArchivo,"Id: %d,Nombre: %s,Apellido: %s\n",id,nombre,apellido);
        fprintf(pArchivo,"Id: %d,Nombre: %s,Apellido: %s\n",id+1,nombre,apellido);
        fprintf(pArchivo,"Id: %d,Nombre: %s,Apellido: %s\n",id+2,nombre,apellido);
        fclose(pArchivo);
    }else
    {
        printf("El archivo no existe");
    }
*/
    pArchivo=fopen("archivo.ext","r");
    if(pArchivo!=NULL)
    {
        while(!feof(pArchivo))
        {
            strcpy(bufferApellido,"----------------");
            fscanf(pArchivo,"%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferApellido);
            printf("%s - %s - %s\n",bufferId,bufferNombre,bufferApellido);
        }

        fclose(pArchivo);
    }else
    {
        printf("El archivo no existe");
    }

    return 0;
}
