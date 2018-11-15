#include "Empleado.h"
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Empleado.h"
#include "utn.h"


static int isValidNombre(char* nom);
static int isValidId(char* empleadoId);
static int isValidHorasTrabajadas(char* horasTrabajadas);
static int isValidSueldo(char* sueldo);
/**
    empleado_new: crea un nuevo espacio en memoria con una variable de tipo Empleado
    @return direccion de memoria creada.
*/
Empleado* empleado_new(void)
{
    return (Empleado*) malloc(sizeof(Empleado));
}
/**
    empleado_newParametros: crea un nuevo espacio en memoria y guarda datos en un tipo Empleado
    @param idStr: cadena de caracteres con el id a guardar
    @param nombreStr: cadena de caracteres con el nombre a guardar
    @param horasTrabajadasStr: cadena de caracteres con las horas trabajadas a guardar
    @param sueldoStr: cadena de caracteres con el sueldo a guardar
    @return direccion de memoria creada.
*/
Empleado* empleado_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Empleado* p;
    p=empleado_new();
    if(p!=NULL)
    {
        if( empleado_setNombre(p,nombreStr)==-1 ||
            empleado_setId(p,idStr)==-1 ||
            empleado_setHorasTrabajadas(p,horasTrabajadasStr) == -1)
        {
            empleado_delete(p);
            p=NULL;
        }
    }
    return p;
}
/**
    empleado_delete: borra un espacio en memoria
    @param this:el espacio en memoria a borrar
    @return 0 OK, -1 error.
*/
int empleado_delete(Empleado* this)
{
    int retorno=-1;
    if(this!=NULL)
    {
        free(this);
        retorno=0;
    }
    return retorno;
}
/**
    empleado_setNombre: recibe un nombre para guardarlo
    @param this: el espacio en memoria donde se guardara
    @param nombre: la cadena de caracteres con el nombre
    @return 0 OK, -1 error.
*/
int empleado_setNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    //validar!!
    if(this != NULL && isValidNombre(nombre)==0)
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno=0;
    }
    return retorno;
}
/**
    empleado_getNombre: recibe un dato tipo Empleado donde se buscara un nombre y se devolvera ese nombre
    @param this: el espacio en memoria de un dato tipo Empleado donde se buscara
    @param nombre: una cadena de caracteres donde se guardara el nombre a buscar
    @return 0 OK, -1 error.
*/
int empleado_getNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    //validar!!
    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno=0;
    }
    return retorno;
}
/**
    empleado_isValidHorasTrabajadas: recibe una cadena de caracteres de un nombre para validar que solo sean letras
    @param nombre: cadena de caracteres a validar
    @return 0 OK, -1 error.
*/
static int isValidNombre(char* nombre)
{
    int i=0;
    int retorno=0;
    int flag=0;
    while(nombre[i] != '\0')
    {
        if(flag==0)
        {
            nombre[i]=toupper(nombre[i]);
            flag=1;
        }else if ((nombre[i] < 'A' || nombre[i] > 'Z') &&
                (nombre[i] < 'a' || nombre[i] > 'z'))
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}
/**
    empleado_setId: recibe un Id para guardarlo
    @param this: el espacio en memoria donde se guardara
    @param id:la cadena de caracteres con el Id
    @return 0 OK, -1 error.
*/
int empleado_setId(Empleado* this,char* id)
{
    int retorno=-1;
    static int proximoId=-1;
    int idAuxiliar;
    if(this != NULL && isValidId(id)==0)
    {
        idAuxiliar=atoi(id);
        if(idAuxiliar==-1)
        {
            proximoId++;
            this->id=proximoId;
            retorno=0;
        }else if(idAuxiliar>proximoId)
        {
            proximoId=idAuxiliar;
            this->id=proximoId;
            retorno=0;
        }

    }
    return retorno;
}
/**
    empleado_getId: recibe un dato tipo Empleado donde se buscara un id y se devolvera ese id
    @param this: el espacio en memoria de un dato tipo Empleado donde se buscara
    @param id: el puntero a un int donde se guardara el Id a buscar
    @return 0 OK, -1 error.
*/
int empleado_getId(Empleado* this,int* id)
{
    int retorno=-1;
     if(this != NULL && id!= NULL)
     {
        *id=this->id;
        retorno=0;
     }
    return retorno;
}
/**
    empleado_isValidHorasTrabajadas: recibe una cadena de caracteres de un id para validar que solo sean numeros
    @param empleadoId: cadena de caracteres a validar
    @return 0 OK, -1 error.
*/
static int isValidId(char* empleadoId)
{
    int i=0;
    int retorno=0;
    int contadorDeGuiones=0;
    while(empleadoId[i] != '\0')
    {
        if(empleadoId[i] == '-' && contadorDeGuiones==0)
        {
            contadorDeGuiones++;
            i++;
            continue;
        }
        if(empleadoId[i] < '0' || empleadoId[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}
/**
    empleado_setHorasTrabajadas: recibe una cantidad de horas trabajadas para guardarla
    @param this: el espacio en memoria donde se guardara
    @param horasTrabajadas: la cadena de caracteres con las horas trabajadas
    @return 0 OK, -1 error.
*/
int empleado_setHorasTrabajadas(Empleado* this,char* horasTrabajadas)
{
    int retorno=-1;
    //validar!!
    if(this != NULL && isValidHorasTrabajadas(horasTrabajadas)==0)
    {
        this->horasTrabajadas=atoi(horasTrabajadas);
        retorno=0;
    }
    return retorno;
}
/**
    empleado_getHorasTrabajadas: recibe un dato tipo Empleado donde se buscara la cantidad de horas trabajadas y se devolvera esa cantidad
    @param this: el espacio en memoria de un dato tipo Empleado donde se buscara
    @param horasTrabajadas: el puntero a un int donde se guardara las horas a buscar
    @return 0 OK, -1 error.
*/
int empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
    int retorno=-1;
    //validar!!
     if(this != NULL && horasTrabajadas!= NULL)
     {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
     }
    return retorno;
}
/**
    empleado_isValidHorasTrabajadas: recibe una cadena de caracteres de horas trabajadas para validar que solo sean numeros
    @param horasTrabajadas: cadena de caracteres a validar
    @return 0 OK, -1 error.
*/
static int isValidHorasTrabajadas(char* horasTrabajadas)
{
    int i=0;
    int retorno=0;
    while(horasTrabajadas[i] != '\0')
    {
        if(horasTrabajadas[i] < '0' || horasTrabajadas[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}
/**
    empleado_setSueldo: recibe un sueldo para guardarlo
    @param this: el espacio en memoria donde se guardara
    @param sueldo: la cadena de caracteres con el sueldo
    @return 0 OK, -1 error.
*/
int empleado_setSueldo(Empleado* this,char* sueldo)
{
    int retorno=-1;
    //validar!!
    if(this != NULL && isValidSueldo(sueldo)==0)
    {
        this->sueldo=atoi(sueldo);
        retorno=0;
    }
    return retorno;
}
/**
    empleado_getSueldo: recibe un dato tipo Empleado donde se buscara un sueldo y se devolvera ese sueldo
    @param this: el espacio en memoria de un dato tipo Empleado donde se buscara
    @param sueldo: el puntero a un int donde se guardara el sueldo a buscar
    @return 0 OK, -1 error.
*/
int empleado_getSueldo(Empleado* this,int* sueldo)
{
    int retorno=-1;
    //validar!!
     if(this != NULL && sueldo!= NULL)
     {
        *sueldo=this->sueldo;
        retorno=0;
     }
    return retorno;
}
/**
    empleado_isValidSueldo: recibe una cadena de caracteres de sueldo para validar que solo sean numeros
    @param sueldo: cadena de caracteres a validar
    @return 0 OK, -1 error.
*/
static int isValidSueldo(char* sueldo)
{
    int i=0;
    int retorno=0;
    while(sueldo[i] != '\0')
    {
        if(sueldo[i] < '0' || sueldo[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}
/**
    empleado_alta: agrega nuevos datos al array LinkedList.
    @param arrayLinkedList: recibe el array en el que se cargaran los datos.
    @return 0 OK, -1 error.
*/
int empleado_alta(LinkedList* arrayEmpleado)
{
    int retorno=-1;
    char bufferNombre[1024];
    char bufferId[1024]="-1";
    int auxHorasTrabajadas;
    int auxSueldo;
    char bufferHorasTrabajadas[1024];
    Empleado* auxiliarPunteroEmpleado;

    if( utn_getNombre(bufferNombre,"Ingrese el nombre del empleado: ","Ese no es un nombre")==0 &&
        utn_getEnteroSinLimites(&auxHorasTrabajadas,10,"Ingrese las horas trabajadas del empleado: ","Ese no es un numero")==0 &&
        utn_getEnteroSinLimites(&auxSueldo,10,"Ingrese el sueldo del empleado: ","Ese no es un numero")==0)
    {
        sprintf(bufferHorasTrabajadas,"%d",auxHorasTrabajadas);
        auxiliarPunteroEmpleado=empleado_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas);
        if(auxiliarPunteroEmpleado!=NULL)
        {
            ll_add(arrayEmpleado,auxiliarPunteroEmpleado);
        }
        retorno=0;
    }

    return retorno;
}
/**
    empleado_modificacion: modifica datos actuales al array LinkedList.
    @param arrayLinkedList: recibe el array en el que se modificara el dato.
    @return 0 OK, -1 error.
*/
int empleado_modificar(LinkedList* arrayEmpleado)
{
    int retorno=-1;
    int empleadoId;
    int indice;
    char bufferNombre[1024];
    int auxHorasTrabajadas;
    int auxSueldo;
    Empleado* auxEmpleado;
    if(arrayEmpleado != NULL && utn_getEnteroSinLimites(&empleadoId,10,"Ingrese el ID del empleado a modificar: ","Ese id no es valido")==0)
    {
        indice=empleado_buscarPorId(arrayEmpleado,empleadoId);
        if(indice >=0)
        {
            auxEmpleado=ll_get(arrayEmpleado,indice);
            if( utn_getNombre(bufferNombre,"Ingrese el nuevo nombre del empleado: ","Ese no es un nombre\n")==0 &&
                utn_getEnteroSinLimites(&auxHorasTrabajadas,10,"Ingrese la nueva cantidad de horas trabajadas: ","Esas no es una hora valida")==0 &&
                utn_getEnteroSinLimites(&auxSueldo,10,"Ingrese el nuevo sueldo: ","Ese no es un sueldo valido\n")==0)
            {
                auxEmpleado->horasTrabajadas=auxHorasTrabajadas;
                auxEmpleado->sueldo=auxSueldo;
                strcpy(auxEmpleado->nombre,bufferNombre);
                retorno=0;
            }
        }else
        {
            printf("El Id no existe\n");
        }
    }
    return retorno;
}
/**
    empleado_borrar: borra datos actuales al array LinkedList.
    @param arrayLinkedList: recibe el array en el que se borrara el dato.
    @return 0 OK, -1 error.
*/
int empleado_borrar(LinkedList* arrayEmpleado)
{
    int retorno=-1;
    int empleadoId;
    int indice;
    Empleado* auxEmpleado;
    if(arrayEmpleado != NULL && utn_getEnteroSinLimites(&empleadoId,10,"Ingrese el ID del empleado a borrar: ","Ese id no es valido")==0)
    {
        indice=empleado_buscarPorId(arrayEmpleado,empleadoId);
        if(indice >=0)
        {
            auxEmpleado=ll_get(arrayEmpleado,indice);
            if(empleado_delete(auxEmpleado)==0)
            {
                retorno=0;
                ll_remove(arrayEmpleado,indice);
            }
        }else
        {
            printf("El Id no existe\n");
        }
    }
    return retorno;
}
/**
    empleado_buscarPorId: recibe una LinkedList y un int con un Id para encontrar en que posicio esta ese Id o si existe
    @param arrayEmpleado: el array a recorrer
    @param id: el id que se compara con los Id del array hasta encontrar el igual
    @return un int con la posicion de un array.
*/
int empleado_buscarPorId(LinkedList* pArrayEmpleado, int empleadoId)
{
    int retorno=-1;
    int i;
    int limite=ll_len(pArrayEmpleado);
    Empleado* auxEmpleado;
    if(pArrayEmpleado!=NULL)
    {
        for(i=0;i<limite;i++)
        {
            auxEmpleado=(Empleado*)ll_get(pArrayEmpleado,i);
            if(auxEmpleado!=NULL && auxEmpleado->id == empleadoId)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
/**
    empleado_mostrar: lista todo el contenido del array LinkedLista
    @param arrayLinkedList: recibe el array a mostrar
*/
void empleado_mostrar(LinkedList* arrayLinkedList)
{
    int i;
    int auxId;
    char auxNombre[1024];
    int auxHorasTrabajadas;
    int auxSueldo;
    int limite;
    limite=ll_len(arrayLinkedList);
    Empleado* auxEmpleado;
    for(i=0;i<limite;i++)
    {
        auxEmpleado=ll_get(arrayLinkedList,i);

        if( empleado_getId(auxEmpleado,&auxId)==0 &&
            empleado_getNombre(auxEmpleado,auxNombre)==0 &&
            empleado_getHorasTrabajadas(auxEmpleado,&auxHorasTrabajadas)==0 &&
            empleado_getSueldo(auxEmpleado,&auxSueldo)==0)
        {
            printf("ID: %d - Nombre: %s - Horas Trabajadas: %d - Sueldo: %d \n", auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
        }

    }
}
/**
    empleado_criterioNombre: utiliza el strcmp para comparar 2 nombres y retorna el valor del strcmp
    @param thisA: dato uno a comparar
    @param thisB: dato dos a comparar
    @return retorno: valor del strcmp
*/
int empleado_criterioNombre(void* thisA,void* thisB)
{
    int retorno=0;
    char nombreA[1024];
    char nombreB[1024];
    empleado_getNombre((Empleado*)thisA,nombreA);
    empleado_getNombre((Empleado*)thisB,nombreB);
    if(strcmp(nombreA,nombreB)>0)
    {
        retorno=1;
    }else if(strcmp(nombreA,nombreB)<0)
    {
        retorno=-1;
    }
    return retorno;
}
/**
    empleado_guardarTexto: guarda los datos del LinkedList en la ruta del archivo recibido en modo texto
    @param arrayLinkedList: recibe el array a guardar.
    @param path: nombre del archivo donde se guardaran los datos
    @return 0 OK, -1 error.
*/
int empleado_guardarTexto(LinkedList* pArrayEmpleado, char* path)
{
    int retorno=-1;
    int i;
    int limite;
    FILE* pFile;
    pFile=fopen(path,"w");
    limite=ll_len(pArrayEmpleado);
    Empleado* auxEmpleado;
    if(pFile !=NULL)
    {
        retorno=0;
        for(i=0;i<limite;i++)
        {
            auxEmpleado=ll_get(pArrayEmpleado,i);
            fprintf(pFile,"%d,%s,%d,%d\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
        }
    }
    fclose(pFile);
    return retorno;
}
/**
    empleado_guardarBinario: guarda los datos del LinkedList en la ruta del archivo recibido en modo binario
    @param arrayLinkedList: recibe el array a guardar.
    @param path: nombre del archivo donde se guardaran los datos
    @return 0 OK, -1 error.
*/

int empleado_guardarBinario(LinkedList* pArrayEmpleado,char* path)
{
    int retorno=-1;
    FILE* pArchivo=fopen(path,"wb");
    Empleado* pEmpleado;
    int i;
    int lenArray=ll_len(pArrayEmpleado);
    if(pArchivo != NULL)
    {
        retorno=0;
        for(i=0;i<lenArray;i++)
        {
            pEmpleado=ll_get(pArrayEmpleado,i);
            fwrite(pEmpleado,sizeof(Empleado),1,pArchivo);
        }
    }
    fclose(pArchivo);
    return retorno;
}

void em_calcularSueldo(void* p)
{

}
