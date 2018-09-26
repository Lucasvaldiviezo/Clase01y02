#ifndef PANTALLAS_H_INCLUDED
#define PANTALLAS_H_INCLUDED
#define TIPO_LED 0
#define TIPO_LCD 1

struct S_pantalla{
int ID;
int tipo;
char nombre[128];
char direccion[128];
float precio;
int isEmpty;
}typedef Pantalla;

int pan_cargarDatosVacio(Pantalla* pPantalla,int limite);
int pan_cargarIndice(Pantalla* pPantalla,int indice,int limite);
int pan_mostrarIndice(Pantalla* pPantalla,int indice);
int pan_getEmptyIndex(Pantalla* pPantalla,int limite,int* indiceVacio);
int pan_modificarIndice(Pantalla* pPantalla,int id, int limite);
int pan_buscarPantallaPorId(Pantalla* pPantalla,int limite,int id);
int pan_borrarPantalla(Pantalla* pPantalla,int limite,int id);

#endif // PANTALLAS_H_INCLUDED
