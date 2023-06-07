using HR.Employee;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;
//using System.Data.SqlClient;

namespace HR
{
    public partial class adaugaSlide : Form
    {
    
        public adaugaSlide()
        {
            InitializeComponent();
        }
        Angajati c = new Angajati();
        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void AdaugaButton_Click(object sender, EventArgs e)
        {
            //Obtine Valori
            c.Nume = addNume.Text;
            //String->Int
            c.Varsta = int.Parse(addVarsta.Text);
            c.Functia = addFunctia.Text;
            c.Salariu = int.Parse(addSalariu.Text);
            c.Domiciliu = addDomiciliu.Text;
            c.Email = addEmail.Text;
            c.Limba = addLimba.Text;
            c.ID = int.Parse(addID.Text);

            //Inserta Date
            bool success = c.Insert(c);
            if(success == true) { MessageBox.Show("Nou Angajat Adaugat in Baza de Date");Clear(); } else { MessageBox.Show("Eroare");Clear(); }

        }
        public void Clear()
        {
            addNume.Text = "";
            addVarsta.Text = "";
            addFunctia.Text = "";
            addSalariu.Text = "";
            addDomiciliu.Text = "";
            addEmail.Text = "";
            addLimba.Text = "";
            addID.Text = "";

        }
        private void adaugaSlide_Load(object sender, EventArgs e)
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void addLimba_TextChanged(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void DomiciliuLabel_Click(object sender, EventArgs e)
        {

        }
    }
}
