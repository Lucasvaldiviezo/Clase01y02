using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Operadores_Matematicos
{
    class Numero
    {
        public int numero;

        public Numero() { }

        public void SetNumero(int numero)
        {
            this.numero = numero;
        }

        public static int Suma(Numero numero1,Numero numero2)
        {
            int total = numero1.numero + numero2.numero;
            return total;
        }
        public static int Resta(Numero numero1, Numero numero2)
        {
            int total = numero1.numero - numero2.numero;
            return total;
        }
        public static int Multiplicacion(Numero numero1, Numero numero2)
        {
            int total = numero1.numero * numero2.numero;
            return total;
        }
        public static float Division(Numero numero1, Numero numero2)
        {
            float total = numero1.numero / numero2.numero;
            return total;
        }
    }
}
