#include <stdio_ext.h>
#include <stdlib.h>
#include "Compra.h"
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "utn.h"

int parser_parseCompras(char* fileName, LinkedList* lista)
{

    int retorno=-1;
    char* tokenNombre;
    char* tokenIdProducto;
    char* tokenPrecioUnitario;
    char* tokenUnidades;
    char* tokenIva;
    char* delim=",";
    char* delim2="\n";
    int valueF;
    int contadorEntradas=0;
    char line[1024];
    Compra* auxiliarPunteroCompra;
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
                printf("Entre aca\n");
                break;
            }
            tokenNombre=strtok(line, delim);
            tokenIdProducto=strtok(NULL, delim);
            tokenPrecioUnitario=strtok(NULL, delim);
            tokenUnidades=strtok(NULL, delim);
            tokenIva=strtok(NULL, delim2);
            auxiliarPunteroCompra=Compra_newConParametros(tokenNombre,tokenIdProducto,tokenPrecioUnitario,tokenUnidades,tokenIva);
            if(auxiliarPunteroCompra!=NULL)
            {
                contadorEntradas++;
                ll_add(lista,auxiliarPunteroCompra);
                retorno=0;
            }

        }
        printf("Se cargaron %d compras. \n",contadorEntradas);
    }
    fclose(pFile);
    return retorno;
}

