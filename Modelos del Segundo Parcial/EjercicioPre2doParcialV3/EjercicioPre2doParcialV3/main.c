#include <stdio.h>
#include <stdlib.h>
#include "Compra.h"
#include "LinkedList.h"
#include "Parser.h"
#include "utn.h"

/**
    Realizar un programa que lee de un archivo los datos de compras de productos realizadas por clientes.
    Luego se le pedira al usuario que ingrese un id de un producto y el programa deberá imprimir por pantalla:
    - 1. Lista de compras filtrada segun el producto ingresado
    - 2. Monto total de cada compra considerando el valor del iva indicado.

    - 3. Por ultimo la lista filtrada obtenida con los datos ya calculados, debera ser escrita en un archivo separado por
    comas llamado "informe.csv", con el mismo formato que el original pero con una columna mas al final, en donde se
    indicara el monto total calculado.

    Para realizar el punto 1, se debera utilizar la funcion "filter".
    Para realizar el punto 2, se debera utilizar la funcion "map".
    Para imprimir por pantalla la lista, utilizar iterator.
*/

int generarArchivoInforme(char* fileName,LinkedList* listaCompras);

int main()
{
    // Definir lista de compras
    LinkedList* listaCompras;
    listaCompras=ll_newLinkedList();
    LinkedList* filteredList;
    int id;
    // Crear lista compras
    //...

    // Leer compras de archivo data.csv
    if(parser_parseCompras("data.csv",listaCompras)==0)
    {
        // Filtrar
        printf("Ingrese id de producto:");
        if(utn_getEnteroSinLimites(&id,10," ","Ese no es un numero valido")==0 && compra_buscarPorId(listaCompras,id)!=-1)
        {
            filteredList=ll_filterVariableComparadoraInt(listaCompras,id,compra_productoSeleccionado);
            //ll_map(filteredList,compra_imprimirProducto);
             // Calcular montos
            if(ll_map(filteredList,compra_calcularMontoTotal)==0)
            {
                printf("Calculando montos totales...\n");
        //TODO

            // Generar archivo de salida
                if(generarArchivoInforme("informe.csv",filteredList)==0)
                {
                    printf("Archivo generado correctamente\n");
                }
                else
                    printf("Error generando archivo\n");
            }


        }else
        {
            printf("Ese id no existe\n");
        }

        //TODO

    }
    else
        printf("Error leyendo compras\n");


    return 0;
}

int generarArchivoInforme(char* fileName,LinkedList* listaCompras)
{
    int retorno=-1;
    int i;
    int limite;
    FILE* pFile;
    pFile=fopen(fileName,"w");
    limite=ll_len(listaCompras);
    Compra* auxCompra;
    if(pFile !=NULL)
    {
        retorno=0;
        for(i=0;i<limite;i++)
        {
            auxCompra=ll_get(listaCompras,i);
            fprintf(pFile,"%s,%d,%.2f,%d,%.2f,%.2f\n",auxCompra->nombreCliente,auxCompra->idProducto,auxCompra->precioUnitario,auxCompra->unidades,auxCompra->iva,auxCompra->montoTotal);
        }
    }
    fclose(pFile);
    return retorno;
    return 1;
}
