
using HR.Employee;
using HR.Slides;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace HR
{
    public partial class Main : Form
    {
        public Main()
        {
            InitializeComponent();
        }

        public void loadform(object Form)
        {
            if (this.mainpanel.Controls.Count > 0)
                this.mainpanel.Controls.RemoveAt(0);
            Form f =Form as Form;
            f.TopLevel = false;
            f.Dock = DockStyle.Fill;
            this.mainpanel.Controls.Add(f);
            this.mainpanel.Tag = f;
            f.Show();
        }
        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void but_lista_Click(object sender, EventArgs e)
        {
            loadform(new afisareAngajatiSlide());
        }
        private void adauga2_Load(object sender, EventArgs e)
        {

        }

        private void panou_Paint(object sender, PaintEventArgs e)
        {
       
        }

        private void but_adauga_Click(object sender, EventArgs e)
        {
            loadform(new adaugaSlide());
        }

        private void but_elimina_Click(object sender, EventArgs e)
        {
            loadform(new eliminaSlide());
        }

        private void but_modifica_Click(object sender, EventArgs e)
        {
            loadform(new modificaSlide());
        }

        private void but_cauta_Click(object sender, EventArgs e)
        {
            loadform(new cautaSlide());
        }

        private void Main_Load(object sender, EventArgs e)
        {

        }

        private void but_setari_Click(object sender, EventArgs e)
        {
            loadform(new Detalii());

        }
    }
}
