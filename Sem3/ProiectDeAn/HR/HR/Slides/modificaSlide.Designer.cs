namespace HR
{
    partial class modificaSlide
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle16 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle17 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle18 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle19 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle20 = new System.Windows.Forms.DataGridViewCellStyle();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.cautaNume = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.addNume = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.addID = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.afisareAngajati = new System.Windows.Forms.DataGridView();
            this.addLimba = new System.Windows.Forms.TextBox();
            this.addEmail = new System.Windows.Forms.TextBox();
            this.addDomiciliu = new System.Windows.Forms.TextBox();
            this.addVarsta = new System.Windows.Forms.TextBox();
            this.addSalariu = new System.Windows.Forms.TextBox();
            this.addFunctia = new System.Windows.Forms.TextBox();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.afisareAngajati)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.DarkSlateGray;
            this.label1.Font = new System.Drawing.Font("Century Gothic", 22.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(226, 16);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(546, 44);
            this.label1.TabIndex = 0;
            this.label1.Text = "Modifica Datele unui Angajat";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.DarkSlateGray;
            this.label2.Font = new System.Drawing.Font("Century Gothic", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(7, 64);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(477, 37);
            this.label2.TabIndex = 1;
            this.label2.Text = "Introduceti Numele Angajatului:";
            // 
            // cautaNume
            // 
            this.cautaNume.Font = new System.Drawing.Font("Century Gothic", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.cautaNume.Location = new System.Drawing.Point(478, 72);
            this.cautaNume.Multiline = true;
            this.cautaNume.Name = "cautaNume";
            this.cautaNume.Size = new System.Drawing.Size(234, 29);
            this.cautaNume.TabIndex = 5;
            this.cautaNume.TextChanged += new System.EventHandler(this.Nume_TextChanged);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.BackColor = System.Drawing.Color.DarkSlateGray;
            this.label8.Font = new System.Drawing.Font("Century Gothic", 19.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label8.Location = new System.Drawing.Point(481, 438);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(124, 40);
            this.label8.TabIndex = 30;
            this.label8.Text = "Limba:";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.BackColor = System.Drawing.Color.DarkSlateGray;
            this.label7.Font = new System.Drawing.Font("Century Gothic", 19.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label7.Location = new System.Drawing.Point(481, 375);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(110, 40);
            this.label7.TabIndex = 29;
            this.label7.Text = "Email:";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.BackColor = System.Drawing.Color.DarkSlateGray;
            this.label6.Font = new System.Drawing.Font("Century Gothic", 20.2F);
            this.label6.Location = new System.Drawing.Point(481, 326);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(173, 40);
            this.label6.TabIndex = 28;
            this.label6.Text = "Domiciliu:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.BackColor = System.Drawing.Color.DarkSlateGray;
            this.label5.Font = new System.Drawing.Font("Century Gothic", 20.2F);
            this.label5.Location = new System.Drawing.Point(86, 434);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(133, 40);
            this.label5.TabIndex = 27;
            this.label5.Text = "Salariu:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.Color.DarkSlateGray;
            this.label4.Font = new System.Drawing.Font("Century Gothic", 20.2F);
            this.label4.Location = new System.Drawing.Point(84, 374);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(148, 40);
            this.label4.TabIndex = 26;
            this.label4.Text = "Functia:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.Color.DarkSlateGray;
            this.label3.Font = new System.Drawing.Font("Century Gothic", 20.2F);
            this.label3.Location = new System.Drawing.Point(86, 492);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(130, 40);
            this.label3.TabIndex = 24;
            this.label3.Text = "Varsta:";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.BackColor = System.Drawing.Color.DarkSlateGray;
            this.label9.Font = new System.Drawing.Font("Century Gothic", 20.2F);
            this.label9.Location = new System.Drawing.Point(86, 316);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(124, 40);
            this.label9.TabIndex = 22;
            this.label9.Text = "Nume:";
            this.label9.Click += new System.EventHandler(this.label9_Click);
            // 
            // addNume
            // 
            this.addNume.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.addNume.Location = new System.Drawing.Point(238, 326);
            this.addNume.Multiline = true;
            this.addNume.Name = "addNume";
            this.addNume.Size = new System.Drawing.Size(183, 30);
            this.addNume.TabIndex = 21;
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.SeaGreen;
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button1.Location = new System.Drawing.Point(900, 489);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(115, 48);
            this.button1.TabIndex = 35;
            this.button1.Text = "Salvare";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.DarkSlateGray;
            this.panel1.Controls.Add(this.addID);
            this.panel1.Controls.Add(this.label11);
            this.panel1.Controls.Add(this.label10);
            this.panel1.Controls.Add(this.afisareAngajati);
            this.panel1.Controls.Add(this.button1);
            this.panel1.Controls.Add(this.addLimba);
            this.panel1.Controls.Add(this.cautaNume);
            this.panel1.Controls.Add(this.label5);
            this.panel1.Controls.Add(this.addEmail);
            this.panel1.Controls.Add(this.label4);
            this.panel1.Controls.Add(this.addDomiciliu);
            this.panel1.Controls.Add(this.label3);
            this.panel1.Controls.Add(this.addVarsta);
            this.panel1.Controls.Add(this.label9);
            this.panel1.Controls.Add(this.addSalariu);
            this.panel1.Controls.Add(this.addFunctia);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Controls.Add(this.label8);
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.label7);
            this.panel1.Controls.Add(this.label6);
            this.panel1.Controls.Add(this.addNume);
            this.panel1.Location = new System.Drawing.Point(91, 51);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1066, 561);
            this.panel1.TabIndex = 36;
            // 
            // addID
            // 
            this.addID.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.addID.Location = new System.Drawing.Point(669, 503);
            this.addID.Multiline = true;
            this.addID.Name = "addID";
            this.addID.ReadOnly = true;
            this.addID.Size = new System.Drawing.Size(175, 30);
            this.addID.TabIndex = 40;
            this.addID.UseWaitCursor = true;
            this.addID.TextChanged += new System.EventHandler(this.addID_TextChanged);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.BackColor = System.Drawing.Color.DarkSlateGray;
            this.label11.Font = new System.Drawing.Font("Century Gothic", 19.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label11.Location = new System.Drawing.Point(481, 490);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(59, 40);
            this.label11.TabIndex = 39;
            this.label11.Text = "ID:";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.BackColor = System.Drawing.Color.DarkSlateGray;
            this.label10.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label10.Location = new System.Drawing.Point(8, 113);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(285, 34);
            this.label10.TabIndex = 38;
            this.label10.Text = "Selectati Angajatul:";
            // 
            // afisareAngajati
            // 
            dataGridViewCellStyle16.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            dataGridViewCellStyle16.ForeColor = System.Drawing.Color.Black;
            dataGridViewCellStyle16.SelectionBackColor = System.Drawing.Color.PaleTurquoise;
            dataGridViewCellStyle16.SelectionForeColor = System.Drawing.Color.Black;
            this.afisareAngajati.AlternatingRowsDefaultCellStyle = dataGridViewCellStyle16;
            this.afisareAngajati.BackgroundColor = System.Drawing.Color.White;
            dataGridViewCellStyle17.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle17.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle17.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            dataGridViewCellStyle17.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle17.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle17.SelectionForeColor = System.Drawing.Color.Black;
            dataGridViewCellStyle17.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.afisareAngajati.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle17;
            this.afisareAngajati.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridViewCellStyle18.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle18.BackColor = System.Drawing.Color.White;
            dataGridViewCellStyle18.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            dataGridViewCellStyle18.ForeColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle18.SelectionBackColor = System.Drawing.SystemColors.GradientActiveCaption;
            dataGridViewCellStyle18.SelectionForeColor = System.Drawing.Color.Black;
            dataGridViewCellStyle18.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
            this.afisareAngajati.DefaultCellStyle = dataGridViewCellStyle18;
            this.afisareAngajati.Location = new System.Drawing.Point(14, 150);
            this.afisareAngajati.Name = "afisareAngajati";
            dataGridViewCellStyle19.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle19.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle19.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            dataGridViewCellStyle19.ForeColor = System.Drawing.Color.Black;
            dataGridViewCellStyle19.SelectionBackColor = System.Drawing.SystemColors.GradientActiveCaption;
            dataGridViewCellStyle19.SelectionForeColor = System.Drawing.Color.Black;
            dataGridViewCellStyle19.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.afisareAngajati.RowHeadersDefaultCellStyle = dataGridViewCellStyle19;
            this.afisareAngajati.RowHeadersWidth = 51;
            dataGridViewCellStyle20.BackColor = System.Drawing.Color.White;
            dataGridViewCellStyle20.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            dataGridViewCellStyle20.ForeColor = System.Drawing.Color.Black;
            dataGridViewCellStyle20.SelectionBackColor = System.Drawing.Color.PaleTurquoise;
            dataGridViewCellStyle20.SelectionForeColor = System.Drawing.Color.Black;
            this.afisareAngajati.RowsDefaultCellStyle = dataGridViewCellStyle20;
            this.afisareAngajati.RowTemplate.Height = 24;
            this.afisareAngajati.Size = new System.Drawing.Size(1001, 150);
            this.afisareAngajati.TabIndex = 37;
            this.afisareAngajati.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.afisareAngajati_CellContentClick);
            this.afisareAngajati.RowHeaderMouseClick += new System.Windows.Forms.DataGridViewCellMouseEventHandler(this.afisareAngajati_RowHeaderMouseClick);
            // 
            // addLimba
            // 
            this.addLimba.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.addLimba.Location = new System.Drawing.Point(669, 443);
            this.addLimba.Multiline = true;
            this.addLimba.Name = "addLimba";
            this.addLimba.Size = new System.Drawing.Size(175, 30);
            this.addLimba.TabIndex = 36;
            // 
            // addEmail
            // 
            this.addEmail.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.addEmail.Location = new System.Drawing.Point(669, 385);
            this.addEmail.Multiline = true;
            this.addEmail.Name = "addEmail";
            this.addEmail.Size = new System.Drawing.Size(175, 30);
            this.addEmail.TabIndex = 35;
            // 
            // addDomiciliu
            // 
            this.addDomiciliu.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.addDomiciliu.Location = new System.Drawing.Point(669, 336);
            this.addDomiciliu.Multiline = true;
            this.addDomiciliu.Name = "addDomiciliu";
            this.addDomiciliu.Size = new System.Drawing.Size(175, 30);
            this.addDomiciliu.TabIndex = 34;
            // 
            // addVarsta
            // 
            this.addVarsta.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.addVarsta.Location = new System.Drawing.Point(238, 502);
            this.addVarsta.Multiline = true;
            this.addVarsta.Name = "addVarsta";
            this.addVarsta.Size = new System.Drawing.Size(183, 30);
            this.addVarsta.TabIndex = 33;
            // 
            // addSalariu
            // 
            this.addSalariu.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.addSalariu.Location = new System.Drawing.Point(238, 444);
            this.addSalariu.Multiline = true;
            this.addSalariu.Name = "addSalariu";
            this.addSalariu.Size = new System.Drawing.Size(183, 30);
            this.addSalariu.TabIndex = 32;
            // 
            // addFunctia
            // 
            this.addFunctia.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.addFunctia.Location = new System.Drawing.Point(238, 381);
            this.addFunctia.Multiline = true;
            this.addFunctia.Name = "addFunctia";
            this.addFunctia.Size = new System.Drawing.Size(183, 30);
            this.addFunctia.TabIndex = 31;
            this.addFunctia.TextChanged += new System.EventHandler(this.addVarsta_TextChanged);
            // 
            // modificaSlide
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 23F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Teal;
            this.ClientSize = new System.Drawing.Size(1226, 700);
            this.Controls.Add(this.panel1);
            this.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.ForeColor = System.Drawing.SystemColors.Control;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "modificaSlide";
            this.Text = "modificaSlide";
            this.Load += new System.EventHandler(this.modificaSlide_Load);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.afisareAngajati)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox cautaNume;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox addNume;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.TextBox addLimba;
        private System.Windows.Forms.TextBox addEmail;
        private System.Windows.Forms.TextBox addDomiciliu;
        private System.Windows.Forms.TextBox addVarsta;
        private System.Windows.Forms.TextBox addSalariu;
        private System.Windows.Forms.TextBox addFunctia;
        private System.Windows.Forms.DataGridView afisareAngajati;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox addID;
        private System.Windows.Forms.Label label11;
    }
}