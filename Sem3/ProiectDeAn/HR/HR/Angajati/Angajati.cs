using System;
using System.Collections;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Diagnostics.Eventing.Reader;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace HR.Employee
{
    class Angajati
    {
        public int ID { get; set; }

        public string Nume { get; set; }

        public int Varsta { get; set; }

        public string Functia { get; set; }

        public float Salariu { get; set; }

        public string Domiciliu { get; set; }

        public string Email { get; set; }

        public string Limba { get; set; }

        static string myconnstrng = ConfigurationManager.ConnectionStrings["connstrng"].ConnectionString;

        //Selectare date din DataBase
        public DataTable Select()
        {
            //1.Connectare
            SqlConnection conn = new SqlConnection(myconnstrng);
            DataTable dt = new DataTable();
            try
            {
                //Scriu SQL Query
                string sql = "SELECT * FROM TabelListaAngajati";
                //Creare cmd using si conn
                SqlCommand cmd = new SqlCommand(sql, conn);
                //Creare SQL Adapter using cmd
                SqlDataAdapter adapter = new SqlDataAdapter(cmd);
                conn.Open();
                adapter.Fill(dt);
            }
            catch (Exception ex)
            {

            }
            finally
            {
                conn.Close();
            }
            return dt;
        }
        //Scriere Date in DataBase
        public bool Insert(Angajati c)
        {
            //Crearea return type default
            bool isSuccess = false;
            //1.Conectare DataBase
            SqlConnection conn = new SqlConnection(myconnstrng);

            try
            {
                //Creare SQL Qwery pentru a inserta datele
                string sql = "INSERT INTO TabelListaAngajati(ID, Nume, Functia, Salariu, Varsta, Domiciliu, Email,Limba) VALUES(@ID, @Nume, @Functia, @Salariu, @Varsta, @Domiciliu, @Email,@Limba)";
                //Creare SQL comanda
                SqlCommand cmd = new SqlCommand(sql, conn);
                //Creare Parametri pentru a adauga datele
                cmd.Parameters.AddWithValue("@ID", c.ID);
                cmd.Parameters.AddWithValue("@Nume", c.Nume);
                cmd.Parameters.AddWithValue("@Functia", c.Functia);
                cmd.Parameters.AddWithValue("@Salariu", c.Salariu);
                cmd.Parameters.AddWithValue("@Varsta", c.Varsta);
                cmd.Parameters.AddWithValue("@Domiciliu", c.Domiciliu);
                cmd.Parameters.AddWithValue("@Email", c.Email);
                cmd.Parameters.AddWithValue("@Limba", c.Limba);

                //Conectarea Open
                conn.Open();
                int rows = cmd.ExecuteNonQuery();
                //Daca se Executa,rews va fi mai mare ca 0
                if (rows > 0) { isSuccess = true; } else { isSuccess = false; }
            }
            catch (Exception ex)
            {

            }
            finally
            {
                conn.Close();
            }
            return isSuccess;
        }
        //Actualizare date
        public bool Update(Angajati c)
        {
            bool isSuccess = false;
            SqlConnection conn = new SqlConnection(myconnstrng);
            try
            {
                string sql = "UPDATE TabelListaAngajati SET Nume=@Nume, Functia=@Functia, Salariu=@Salariu, Varsta=@Varsta, Domiciliu=@Domiciliu, Email=@Email,Limba=@Limba WHERE ID=@ID";
                SqlCommand cmd = new SqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@Nume", c.Nume);
                cmd.Parameters.AddWithValue("@Functia", c.Functia);
                cmd.Parameters.AddWithValue("@Salariu", c.Salariu);
                cmd.Parameters.AddWithValue("@Varsta", c.Varsta);
                cmd.Parameters.AddWithValue("@Domiciliu", c.Domiciliu);
                cmd.Parameters.AddWithValue("@Email", c.Email);
                cmd.Parameters.AddWithValue("@Limba", c.Limba);
                cmd.Parameters.AddWithValue("@ID", c.ID);
                conn.Open();
                int rows = cmd.ExecuteNonQuery();
                if (rows > 0)
                {
                    isSuccess = true;
                }
                else
                {
                    isSuccess = false;
                }
            }
            catch (Exception ex)
            {

            }
            finally
            {
                conn.Close();
            }
            return isSuccess;
        }


        public bool Delete(Angajati c)
        {
            //Crearea return type default
            bool isSuccess = false;
            //1.Conectare DataBase
            SqlConnection conn = new SqlConnection(myconnstrng);
            try
            {
                //Creare SQL Qwery pentru a Sterge datele
                string sql = "DELETE FROM TabelListaAngajati WHERE ID=@ID";
                //Creare SQL comanda
                SqlCommand cmd = new SqlCommand(sql, conn);
                //Creare Parametri pentru a adauga datele
                cmd.Parameters.AddWithValue("@ID", c.ID);
                //Conectarea Open
                conn.Open();
                int rows = cmd.ExecuteNonQuery();
                //Daca se Executa,rews va fi mai mare ca 0
                if (rows > 0) { isSuccess = true; } else { isSuccess = false; }
            }
            catch (Exception ex)
            {

            }
            finally
            {
                conn.Close();
            }
            return isSuccess;



        }

        public static void BubbleSort(DataTable dt, int sortColumnIndex)
        {
            int n = dt.Rows.Count;
            bool isUnsorted;
            do
            {
                isUnsorted = false;
                for (int i = 0; i < (n - 1); i++)
                {
                    if (Convert.ToInt32(dt.Rows[i][sortColumnIndex]) > Convert.ToInt32(dt.Rows[i+1][sortColumnIndex]))
                    {
                        isUnsorted = true;
                        for (; i < (n - 1); i++)
                        {
                            if (Convert.ToInt32(dt.Rows[i][sortColumnIndex]) > Convert.ToInt32(dt.Rows[i+1][sortColumnIndex]))
                            {
                                //Schimbare randuri
                                DataRow temp = dt.NewRow();
                                temp.ItemArray = dt.Rows[i].ItemArray;
                                dt.Rows[i].ItemArray = dt.Rows[i + 1].ItemArray;
                                dt.Rows[i + 1].ItemArray = temp.ItemArray;
                            }
                        }
                    }
                }
            } while (isUnsorted);
        }

        public DataTable SelectUpdate()
        {
            SqlConnection conn = new SqlConnection(myconnstrng);
            DataTable dt = new DataTable();
            try
            {
                string sql = "SELECT * FROM TabelListaAngajati";
                SqlCommand cmd = new SqlCommand(sql, conn);
                SqlDataAdapter adapter = new SqlDataAdapter(cmd);
                conn.Open();
                adapter.Fill(dt);

                //Sortarea Tabelului dupa ID utilizand bubble sort
                int[] ages = new int[dt.Rows.Count];
                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    ages[i] = Convert.ToInt32(dt.Rows[i]["ID"]);
                }
                BubbleSort(dt,0);//Indexul Id-Ului
                DataTable sortedDt = new DataTable();
                sortedDt.Columns.Add("ID", typeof(int));
                sortedDt.Columns.Add("Nume", typeof(string));
                sortedDt.Columns.Add("Functia", typeof(string));
                sortedDt.Columns.Add("Salariu", typeof(float));
                sortedDt.Columns.Add("Varsta", typeof(int));
                sortedDt.Columns.Add("Domiciliu", typeof(string));
                sortedDt.Columns.Add("Email", typeof(string));
                sortedDt.Columns.Add("Limba", typeof(string));
                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    DataRow row = sortedDt.NewRow();
                    row["ID"] = Convert.ToInt32(dt.Rows[i]["ID"]);
                    row["Nume"] = dt.Rows[i]["Nume"].ToString();
                    row["Functia"] = dt.Rows[i]["Functia"].ToString();
                    row["Salariu"] = Convert.ToSingle(dt.Rows[i]["Salariu"]);
                    row["Varsta"] = Convert.ToSingle(dt.Rows[i]["Varsta"]);
                    row["Domiciliu"] = dt.Rows[i]["Domiciliu"].ToString();
                    row["Email"] = dt.Rows[i]["Email"].ToString();
                    row["Limba"] = dt.Rows[i]["Limba"].ToString();
                    sortedDt.Rows.Add(row);
                }
                dt = sortedDt;
            }

            catch (Exception ex)
            {

            }
            finally
            {
                conn.Close();
            }
            return dt;
        }


        public bool SaveChangesToDB(DataTable dt)
        {
            bool isSuccess = false;
            SqlConnection conn = new SqlConnection(myconnstrng);
            //Stergere Datele 
            string sql = "DELETE FROM TabelListaAngajati";
            SqlCommand cmd = new SqlCommand(sql, conn);
            conn.Open();
            cmd.ExecuteNonQuery();
            //Update
            try
            {
                 sql = "SELECT * FROM TabelListaAngajati";
                SqlDataAdapter adapter = new SqlDataAdapter(sql, conn);
                SqlCommandBuilder builder = new SqlCommandBuilder(adapter);
                adapter.Update(dt);
                isSuccess = true;
            }
            catch (Exception ex)
            {

            }
            finally
            {
                conn.Close();
            }
            return isSuccess;
        }
    }
}
