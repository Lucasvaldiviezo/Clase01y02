#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
void mostrar(Cliente *arrayPunteroCliente[],int size);
void guardar(Cliente *arrayPunteroCliente[],int size);
int main()
{
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferApellido[1024];
    Cliente *arrayPunteroCliente[1024];
    Cliente *auxiliarPunteroCliente;
    int size=0;
    FILE *pArchivoCliente;

    pArchivoCliente=fopen("archivo.ext","r");
    while(!feof(pArchivoCliente))
    {

        fscanf(pArchivoCliente,"%[^,],%[^,],%[^\n]\n",  bufferId,
                                                        bufferNombre,
                                                        bufferApellido);
        //printf("%s - %s - %s\n",bufferId,bufferNombre,bufferApellido);
        auxiliarPunteroCliente=cliente_newConParametros(bufferNombre,bufferApellido,bufferId);
        if(auxiliarPunteroCliente!=NULL)
        {
            arrayPunteroCliente[size]=auxiliarPunteroCliente;
        }
        size++;
    }
    fclose(pArchivoCliente);
    mostrar(arrayPunteroCliente,size);
    guardar(arrayPunteroCliente,size);
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
   /* pArchivo=fopen("archivo.ext","r");
    if(pArchivo!=NULL)
    {
        while(!feof(pArchivo))
        {
            //strcpy(bufferApellido,"----------------");
            fscanf(pArchivo,"%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferApellido);
            printf("%s - %s - %s\n",bufferId,bufferNombre,bufferApellido);

        }

        fclose(pArchivo);
    }else
    {
        printf("El archivo no existe");
    }*/

    return 0;
}

void mostrar(Cliente *arrayPunteroCliente[],int size)
{
    int i;
    int auxId;
    char auxNombre[64];
    char auxApellido[64];
    for(i=0;i<size;i++)
    {
        cliente_getId(arrayPunteroCliente[i],&auxId);
        cliente_getNombre(arrayPunteroCliente[i],auxNombre);
        cliente_getNombre(arrayPunteroCliente[i],auxApellido);
        printf("ID: %d - NOMBRE: %s - APELLIDO: %s \n", auxId,auxNombre,auxApellido);
    }
}

void guardar(Cliente *arrayPunteroCliente[],int size)
{
    int i;
    int auxId;
    char auxNombre[64];
    char auxApellido[64];
    FILE* pArchivoBackUp=fopen("bkp.txt","w");
    if(pArchivoBackUp != NULL)
    {
        for(i=0;i<size;i++)
        {
            cliente_getId(arrayPunteroCliente[i],&auxId);
            cliente_getNombre(arrayPunteroCliente[i],auxNombre);
            cliente_getNombre(arrayPunteroCliente[i],auxApellido);
            fprintf(pArchivoBackUp,"ID: %d - NOMBRE: %s - APELLIDO: %s \n", auxId,auxNombre,auxApellido);
        }
        fclose(pArchivoBackUp);
    }

}
