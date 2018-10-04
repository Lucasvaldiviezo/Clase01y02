typedef struct
{
    char cuit[50];
    float importe;
    int cantContrataciones;
    //------------
    int isEmpty;
}Cliente;


int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit);
int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas);
int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas);

int informar_OrdenarPantallasPorPrecioNombre(Pantalla* pantallas, int lenPantallas);
int informar_ListarPantallasMenoresIguales(Pantalla* pantallas,int lenPantallas, int valorComparativo);
int informar_ListarPantallasMayores(Pantalla* pantallas,int lenPantallas, int valorComparativo);
int informar_ListarPantallasMayoresPromedio(Pantalla* pantallas,int lenPantallas, int valorComparativo);

