#ifndef CONTRATACION_H_INCLUDED
#define CONTRATACION_H_INCLUDED

struct S_contratacion{
int ID;
int dias;
char nombreVideo[128];
char cuitCliente[128];
int idPantalla;
int isEmpty;
}typedef Contratacion;

int con_cargarIndice(Contratacion* pContratacion,int indice,int limite,int idPantalla);
int con_cargarDatosVacio(Contratacion* pContratacion, int limite);
int con_getEmptyIndex(Contratacion* pContratacion,int limite,int* indiceVacio);
int con_modificarIndice(Contratacion* pContratacion,int id,int limite);
int con_buscarContratacionPorId(Contratacion* pContratacion,int limite,int id);
#endif // CONTRATACION_H_INCLUDED
