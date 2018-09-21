#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

#endif // PRODUCTO_H_INCLUDED

typedef struct Sproducto{
char nombre[32];
char descripcion[128];
float precio;
int isEmpty;
}Producto;
int cargarDatosVacio(Producto* pProd,int limite);
int cargarIndice(Producto* pProd,int indice,int limite);
int utn_getEntero(int* pNum,int reint,char* msg,char* msgError,int maximo,int minimo);
int utn_getNumeroDecimal(float *pNum, int reint, char* msg, char* msgError,float maximo,float minimo);
int mostrarIndice(Producto* pProd,int indice);
int prod_getEmptyIndex(Producto* productos,int limite,int* indiceVacio);
