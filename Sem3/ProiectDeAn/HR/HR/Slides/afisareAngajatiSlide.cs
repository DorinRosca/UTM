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

namespace HR.Slides
{
    public partial class afisareAngajatiSlide : Form
    {

        public afisareAngajatiSlide()
        {
            InitializeComponent();
        }
        Angajati c = new Angajati();
        private void label1_Click(object sender, EventArgs e)
        {
        }
        private void AfisareButton_Click(object sender, EventArgs e)
        {
            DataTable dt = c.Select();
            dataGridView1.DataSource = dt;
        }
        private void afisareAngajatiSlide_Load(object sender, EventArgs e)
        {

        }
        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void dataGridView1_CellContentClick_1(object sender, DataGridViewCellEventArgs e)
        {
            DataTable dt = c.Select();
            dataGridView1.DataSource = dt;
        }

        private void SortareButton_Click(object sender, EventArgs e)
        {
            if (dataGridView1.DataSource != null)
            {
                Angajati a = new Angajati();
                DataTable dt = a.SelectUpdate();
                dataGridView1.DataSource = dt;
                a.SaveChangesToDB(dt);

            }
            else
            {
                MessageBox.Show("Nu sunt date!");
            }
        }
    }
}
