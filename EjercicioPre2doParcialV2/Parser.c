#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "LinkedList.h"
#include <string.h>

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    int retorno=-1;
    char* tokenId;
    char* tokenNombre;
    char* tokenHorasTrabajadas;
    char* delim=",";
    char* delim2="\n";
    int valueF;
    int contador=0;
    char line[1024];
    Empleado* auxiliarPunteroEmployee;
    FILE* pFile;
    pFile=fopen(fileName,"r");
    if(pFile != NULL)
    {
        fscanf(pFile,"%[^\n]\n",line);
        while(!feof(pFile))
        {
            valueF=fscanf(pFile,"%[^\n]\n",line);
            if(valueF!=1)
            {
                break;
            }

            printf("Entrada numero: %d\n",contador);
            contador++;
            tokenId=strtok(line, delim);
            tokenNombre=strtok(NULL, delim);
            tokenHorasTrabajadas=strtok(NULL, delim2);
            auxiliarPunteroEmployee=empleado_newParametros(tokenId,tokenNombre,tokenHorasTrabajadas);
            if(auxiliarPunteroEmployee!=NULL)
            {
                printf("ENTRE ACA!!!!\n");
                ll_add(listaEmpleados,auxiliarPunteroEmployee);
                retorno=0;
            }

        }
    }
    fclose(pFile);
    return retorno;
}

