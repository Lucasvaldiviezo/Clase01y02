#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
    char nombre[50];
    char apellido[50];
    float altura;

    int idEmpleado;

}Empleado;

Empleado* empleado_new();
Empleado* empleado_newConParametro(char* nombre, char* apellido,float altura);
void empleado_delete(Empleado* this);//This se refiere al que le acabo de pasar
void empleado_print(Empleado* this);

int empleado_setNombre(Empleado* this,char* nombre);
int empleado_getNombre(Empleado* this,char* nombre);//en este caso, el char nombre es donde le devolvemos el nombre

int empleado_setApellido(Empleado* this,char* apellido);
int empleado_getApellido(Empleado* this,char* apellido);//en este caso, el char apellido es donde le devolvemos el apellido

int empleado_setAltura(Empleado* this,float altura);
int empleado_getAltura(Empleado* this,float* altura);//en este caso, el float de altura recibe un puntero para guardar esa altura a devolver

int empleado_compareEmpleado(Empleado* thisA, Empleado* thisB);

//vamos a tener el constructor(new)
//el destructor(delete)
//setNombre o Apellido: recibe un nombre y lo guarda en un empleado y valida si el nombre es correcto
//getNombre o Apellido: Obtiene el nombre y lo devuelve
//Vamos a validar con IsValid(isLetra, isInt, isFloat)

#endif // EMPLEADO_H_INCLUDED
