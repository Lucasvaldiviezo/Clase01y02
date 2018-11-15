#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "LinkedList.h"

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    int retorno=-1;
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    char delim=",";
    char* line;
    Empleado* auxiliarPunteroEmployee;
    FILE* pFile;
    pFile=fopen(fileName,"r");
    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%s",line);
            bufferId=strtok(line, delim);
            bufferNombre=strtok(NULL, delim);
            bufferHorasTrabajadas=strtok(NULL, delim);
            auxiliarPunteroEmployee=empleado_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
            if(auxiliarPunteroEmployee!=NULL)
            {
                ll_add(listaEmpleados,auxiliarPunteroEmployee);
                retorno=0;
            }

        }
    }
    fclose(pFile);
    return retorno;
}

