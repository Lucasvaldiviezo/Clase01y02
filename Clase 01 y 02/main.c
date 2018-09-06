#include <stdio.h>
#include <stdlib.h>
//Clase 2
//Descargar GIT
//Escribir git para ver si funciona.
int main()
{

    int numero;
    int numeroMax;
    int numeroMin;
    int i;
    int suma;
    float promedio;

    suma = 0;

    for(i=0;i<10;i++)
    {
        printf("Ingrese un numero:  ");
        scanf("%d",&numero);
        suma = suma + numero;

        if(i==0)
        {
            numeroMax = numero;
            numeroMin = numero;
        }
        else if(numero < numeroMin)
        {
            numeroMin=numero;
        }
        else if(numero > numeroMax)
        {
            numeroMax=numero;
        }
    }

    promedio =(float)suma / i;
    printf("El numero maximo es: %d \nEl numero minimo es: %d \nEl promedio es: %.2f",numeroMax,numeroMin,promedio);

    return 0;
}
