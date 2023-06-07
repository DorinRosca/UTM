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
    public partial class cautaSlide : Form
    {
        public cautaSlide()
        {
            InitializeComponent();
        }
        Angajati c = new Angajati();
        private void label1_Click(object sender, EventArgs e)
        {

        }
        static string myconnstr = ConfigurationManager.ConnectionStrings["connstrng"].ConnectionString; 
        private void CautaNume_TextChanged(object sender, EventArgs e)
        {
            DataTable dt = c.Select();
            dataGridView1.DataSource = dt;
            string keyword = CautaNume.Text;
            SqlConnection conn = new SqlConnection(myconnstr);
            SqlDataAdapter sda = new SqlDataAdapter("SELECT * from TabelListaAngajati WHERE Nume LIKE '%" +keyword+ "%' OR  ID LIKE '%" +keyword+ "%' OR  Functia LIKE '%" +keyword+ "%' OR Email LIKE '%" +keyword+ "%'", conn);
             dt = new DataTable();
            sda.Fill(dt);
            dataGridView1.DataSource = dt;


        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            DataTable dt = c.Select();
            dataGridView1.DataSource = dt;
        }

        private void cautaSlide_Load(object sender, EventArgs e)
        {

        }
    }
}
