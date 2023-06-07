using HR.Employee;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HR
{
    public partial class modificaSlide : Form
    {
        public modificaSlide()
        {
            InitializeComponent();
        }
        Angajati c = new Angajati();
        static string myconnstr = ConfigurationManager.ConnectionStrings["connstrng"].ConnectionString;
        private void label9_Click(object sender, EventArgs e)
        {

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
            cautaNume.Text = "";
        }

        private void Nume_TextChanged(object sender, EventArgs e)
        {
            DataTable dt = c.Select();
            afisareAngajati.DataSource = dt;
            string keyword = cautaNume.Text;
            SqlConnection conn = new SqlConnection(myconnstr);
            SqlDataAdapter sda = new SqlDataAdapter("SELECT * from TabelListaAngajati WHERE Nume LIKE '%" + keyword + "%'", conn);
            dt = new DataTable();
            sda.Fill(dt);
            afisareAngajati.DataSource = dt;
        }

        private void afisareAngajati_RowHeaderMouseClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            //Introducere date in Casete
            int rowIndex = e.RowIndex;
            addID.Text = afisareAngajati.Rows[rowIndex].Cells[0].Value.ToString();
            addNume.Text = afisareAngajati.Rows[rowIndex].Cells[1].Value.ToString();
            addFunctia.Text = afisareAngajati.Rows[rowIndex].Cells[2].Value.ToString();
            addSalariu.Text = afisareAngajati.Rows[rowIndex].Cells[3].Value.ToString();
            addVarsta.Text = afisareAngajati.Rows[rowIndex].Cells[4].Value.ToString();
            addDomiciliu.Text = afisareAngajati.Rows[rowIndex].Cells[5].Value.ToString();
            addEmail.Text = afisareAngajati.Rows[rowIndex].Cells[6].Value.ToString();
            addLimba.Text = afisareAngajati.Rows[rowIndex].Cells[7].Value.ToString();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            //DataTable dt = c.Select();
            //afisareAngajati.DataSource = dt;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //Obtine Valori
            c.ID = int.Parse(addID.Text);
            c.Nume = addNume.Text;
            //String->Int
            c.Varsta = int.Parse(addVarsta.Text);
            c.Functia = addFunctia.Text;
            c.Salariu = float.Parse(addSalariu.Text);
            c.Domiciliu = addDomiciliu.Text;
            c.Email = addEmail.Text;
            c.Limba = addLimba.Text;
            //Inserta Date
            bool success = c.Update(c);
            if (success == true) 
            {
                MessageBox.Show("Datele Angajatului au fost Actualizate");
                DataTable dt = c.Select();
                afisareAngajati.DataSource = dt;
                Clear();
            } 
            else 
            { 
                MessageBox.Show("Eroare");  
                Clear();
            }

        }
        private void addVarsta_TextChanged(object sender, EventArgs e)
        {

        }

        private void modificaSlide_Load(object sender, EventArgs e)
        {

        }

        private void afisareAngajati_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            DataTable dt = c.Select();
            afisareAngajati.DataSource = dt;
        }

        private void addID_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
