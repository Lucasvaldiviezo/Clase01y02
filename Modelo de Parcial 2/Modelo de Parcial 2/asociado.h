#ifndef ASOCIADO_H_INCLUDED
#define ASOCIADO_H_INCLUDED

struct S_asociado
{
    int ID;
    char DNI[20];
    char nombre[128];
    char apellido[128];
    int edad;
    int motivo;
    int estado;
    int isEmpty;
}typedef Asociado;

int aso_cargarForzadaIndice(Asociado* pAsociado,int limite,char* nombrePantalla, char* direccion,int tipo, int precio);
int aso_cargarDatosVacio(Asociado* pAsociado, int limite);
int aso_cargarIndice(Asociado* pAsociado,int indice,int limite);
int aso_modificarIndice(Asociado* pAsociado,int id, int limite);
int aso_buscarPantallaPorId(Asociado* pAsociado,int limite,int id);
int aso_borrarPantalla(Asociado* pAsociado,int limite,int id);
int aso_mostrarIndices(Asociado* pAsociado,int limite);
int aso_mostrarUnIndice(Asociado* pAsociado,int limite,int indice);

#endif // ASOCIADO_H_INCLUDED
