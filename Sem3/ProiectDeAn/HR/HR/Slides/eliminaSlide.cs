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
    public partial class eliminaSlide : Form
    {
        public eliminaSlide()
        {
            InitializeComponent();
        }
        Angajati c = new Angajati();
        static string myconnstr = ConfigurationManager.ConnectionStrings["connstrng"].ConnectionString;
        private void eliminaSlide_Load(object sender, EventArgs e)
        {

        }
        public void Clear()
        {
            Nume.Text = "";
            ID.Text = "";
        }
        private void button1_Click(object sender, EventArgs e)
        {
            c.ID = Convert.ToInt32(ID.Text);
            bool succes = c.Delete(c);
            if (succes==true) 
            {
                MessageBox.Show("Angajatul a fost Sters cu Succes!");
                Clear();
            }
            else 
            {
                MessageBox.Show("Eroare! Incercati din nou");
                Clear();
            }
        }

        private void Nume_TextChanged(object sender, EventArgs e)
        {
            DataTable dt = c.Select();
            dataGridView1.DataSource = dt;
            string keyword = Nume.Text;
            SqlConnection conn = new SqlConnection(myconnstr);
            SqlDataAdapter sda = new SqlDataAdapter("SELECT * from TabelListaAngajati WHERE Nume LIKE '%" + keyword + "%' ", conn);
            dt = new DataTable();
            sda.Fill(dt);
            dataGridView1.DataSource = dt;
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            DataTable dt = c.Select();
            dataGridView1.DataSource = dt;
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }
    }
}
