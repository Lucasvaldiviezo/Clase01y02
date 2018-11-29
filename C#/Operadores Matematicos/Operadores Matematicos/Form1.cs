using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Operadores_Matematicos
{
    public partial class Form1 : Form
    {
        Numero n1;
        Numero n2;
        StringBuilder sb;
        public Form1()
        {
            InitializeComponent();
            sb = new StringBuilder();
            Numero n1 = new Numero();
            Numero n2 = new Numero();
        }

        private void Resultado_TextChanged(object sender, EventArgs e)
        {
            
        }
        
        private void Suma_Click(object sender, EventArgs e)
        {
            Resultado.Text = Numero.Suma(numero1, numero2).ToString();
        }

        private void Resta_Click(object sender, EventArgs e)
        {
            variablemonton1 = sb.ToString()
            sb = new StringBuilder()
            Resultado.Text = Numero.Resta(numero1, numero2).ToString();
        }

        private void Multiplicacion_Click(object sender, EventArgs e)
        {
            Resultado.Text = Numero.Multiplicacion(numero1, numero2).ToString();
        }

        private void Division_Click(object sender, EventArgs e)
        {
            Numero numero1 = new Numero();
            Numero numero2 = new Numero();
            numero1.SetNumero(20);
            numero2.SetNumero(10);
            Resultado.Text = Numero.Division(numero1, numero2).ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            sb.Append(t)
        }
        
    }
}
