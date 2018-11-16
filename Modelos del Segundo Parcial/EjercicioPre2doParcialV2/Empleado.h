#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "LinkedList.h"
struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;
Empleado* empleado_new();
Empleado* empleado_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
int empleado_delete(Empleado* this);

int empleado_setId(Empleado* this,char* id);
int empleado_getId(Empleado* this,int* id);

int empleado_setNombre(Empleado* this,char* nombre);
int empleado_getNombre(Empleado* this,char* nombre);

int empleado_setHorasTrabajadas(Empleado* this,char* horasTrabajadas);
int empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);

int empleado_setSueldo(Empleado* this,char* sueldo);
int empleado_getSueldo(Empleado* this,int* sueldo);

void empleado_mostrar(LinkedList* arrayLinkedList);
int empleado_alta(LinkedList* arrayEmpleado);
int empleado_modificar(LinkedList* arrayEmpleado);
int empleado_borrar(LinkedList* arrayEmpleado);
int empleado_buscarPorId(LinkedList* pArrayEmpleado, int empleadoId);
int empleado_criterioNombre(void* thisA,void* thisB);
int empleado_guardarTexto(LinkedList* pArrayEmpleado, char* path);
int empleado_guardarBinario(LinkedList* pArrayEmpleado,char* path);
int em_calcularSueldo(void* p);

#endif // EMPLEADO_H_INCLUDED
