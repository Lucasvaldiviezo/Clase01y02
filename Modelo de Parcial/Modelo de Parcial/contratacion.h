#ifndef CONTRATACION_H_INCLUDED
#define CONTRATACION_H_INCLUDED
#include "pantallas.h"

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
int con_modificarIndice(Contratacion* pContratacion,int indiceContratacion,int limite);
int con_buscarContratacionPorId(Contratacion* pContratacion,int limite,int id);
int con_imprimirContratacionesCuit(Contratacion* pContratacion,int limite,Pantalla* pPantalla,int limite2,char* cuitVacio);
int con_borrarContratacion(Contratacion* pContratacion,int limite,int indiceContratacion);
int con_buscarContratacionPorIdyCuit(Contratacion* pContratacion,int limite,int idPantalla,char* cuit);
int con_mostrarIndices(Contratacion* pContratacion,int limite, Pantalla* pPantalla, int limite2);
int con_calcularFacturaciones(Contratacion* pContratacion,int limite,Pantalla* pPantalla,int limite2);
#endif // CONTRATACION_H_INCLUDED
