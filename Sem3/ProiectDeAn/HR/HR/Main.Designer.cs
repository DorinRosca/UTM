namespace HR
{
    partial class Main
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Main));
            this.bar = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.meniu = new System.Windows.Forms.Panel();
            this.mainpanel = new System.Windows.Forms.Panel();
            this.but_setari = new System.Windows.Forms.Button();
            this.but_cauta = new System.Windows.Forms.Button();
            this.but_modifica = new System.Windows.Forms.Button();
            this.but_elimina = new System.Windows.Forms.Button();
            this.but_adauga = new System.Windows.Forms.Button();
            this.but_lista = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.label3 = new System.Windows.Forms.Label();
            this.bar.SuspendLayout();
            this.meniu.SuspendLayout();
            this.mainpanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // bar
            // 
            this.bar.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(24)))), ((int)(((byte)(36)))), ((int)(((byte)(36)))));
            this.bar.Controls.Add(this.label1);
            this.bar.Controls.Add(this.pictureBox1);
            this.bar.Dock = System.Windows.Forms.DockStyle.Top;
            this.bar.Location = new System.Drawing.Point(0, 0);
            this.bar.Margin = new System.Windows.Forms.Padding(4);
            this.bar.Name = "bar";
            this.bar.Size = new System.Drawing.Size(1516, 74);
            this.bar.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Century Gothic", 19.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(98, 20);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(297, 40);
            this.label1.TabIndex = 1;
            this.label1.Text = "HR Manager App";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // meniu
            // 
            this.meniu.BackColor = System.Drawing.Color.White;
            this.meniu.Controls.Add(this.but_setari);
            this.meniu.Controls.Add(this.but_cauta);
            this.meniu.Controls.Add(this.but_modifica);
            this.meniu.Controls.Add(this.but_elimina);
            this.meniu.Controls.Add(this.but_adauga);
            this.meniu.Controls.Add(this.but_lista);
            this.meniu.Dock = System.Windows.Forms.DockStyle.Left;
            this.meniu.Location = new System.Drawing.Point(0, 74);
            this.meniu.Margin = new System.Windows.Forms.Padding(4);
            this.meniu.Name = "meniu";
            this.meniu.Size = new System.Drawing.Size(324, 639);
            this.meniu.TabIndex = 1;
            // 
            // mainpanel
            // 
            this.mainpanel.BackColor = System.Drawing.Color.Teal;
            this.mainpanel.Controls.Add(this.label3);
            this.mainpanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.mainpanel.ForeColor = System.Drawing.Color.Transparent;
            this.mainpanel.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.mainpanel.Location = new System.Drawing.Point(324, 74);
            this.mainpanel.Name = "mainpanel";
            this.mainpanel.Size = new System.Drawing.Size(1192, 639);
            this.mainpanel.TabIndex = 0;
            this.mainpanel.Paint += new System.Windows.Forms.PaintEventHandler(this.panou_Paint);
            // 
            // but_setari
            // 
            this.but_setari.ForeColor = System.Drawing.Color.Black;
            this.but_setari.Image = ((System.Drawing.Image)(resources.GetObject("but_setari.Image")));
            this.but_setari.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.but_setari.Location = new System.Drawing.Point(38, 504);
            this.but_setari.Name = "but_setari";
            this.but_setari.Size = new System.Drawing.Size(239, 59);
            this.but_setari.TabIndex = 5;
            this.but_setari.Text = "     Detalii";
            this.but_setari.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.but_setari.UseVisualStyleBackColor = true;
            this.but_setari.Click += new System.EventHandler(this.but_setari_Click);
            // 
            // but_cauta
            // 
            this.but_cauta.ForeColor = System.Drawing.Color.Black;
            this.but_cauta.Image = ((System.Drawing.Image)(resources.GetObject("but_cauta.Image")));
            this.but_cauta.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.but_cauta.Location = new System.Drawing.Point(38, 378);
            this.but_cauta.Name = "but_cauta";
            this.but_cauta.Size = new System.Drawing.Size(239, 59);
            this.but_cauta.TabIndex = 4;
            this.but_cauta.Text = "  Cauta angajat";
            this.but_cauta.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.but_cauta.UseVisualStyleBackColor = true;
            this.but_cauta.Click += new System.EventHandler(this.but_cauta_Click);
            // 
            // but_modifica
            // 
            this.but_modifica.ForeColor = System.Drawing.Color.Black;
            this.but_modifica.Image = ((System.Drawing.Image)(resources.GetObject("but_modifica.Image")));
            this.but_modifica.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.but_modifica.Location = new System.Drawing.Point(38, 297);
            this.but_modifica.Name = "but_modifica";
            this.but_modifica.Size = new System.Drawing.Size(239, 59);
            this.but_modifica.TabIndex = 3;
            this.but_modifica.Text = "Modifica angajat";
            this.but_modifica.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.but_modifica.UseVisualStyleBackColor = true;
            this.but_modifica.Click += new System.EventHandler(this.but_modifica_Click);
            // 
            // but_elimina
            // 
            this.but_elimina.ForeColor = System.Drawing.Color.Black;
            this.but_elimina.Image = ((System.Drawing.Image)(resources.GetObject("but_elimina.Image")));
            this.but_elimina.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.but_elimina.Location = new System.Drawing.Point(38, 212);
            this.but_elimina.Name = "but_elimina";
            this.but_elimina.Size = new System.Drawing.Size(239, 59);
            this.but_elimina.TabIndex = 2;
            this.but_elimina.Text = "Elimina angajat";
            this.but_elimina.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.but_elimina.UseVisualStyleBackColor = true;
            this.but_elimina.Click += new System.EventHandler(this.but_elimina_Click);
            // 
            // but_adauga
            // 
            this.but_adauga.ForeColor = System.Drawing.Color.Black;
            this.but_adauga.Image = ((System.Drawing.Image)(resources.GetObject("but_adauga.Image")));
            this.but_adauga.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.but_adauga.Location = new System.Drawing.Point(38, 127);
            this.but_adauga.Name = "but_adauga";
            this.but_adauga.Size = new System.Drawing.Size(239, 59);
            this.but_adauga.TabIndex = 1;
            this.but_adauga.Text = "Adauga angajat";
            this.but_adauga.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.but_adauga.UseVisualStyleBackColor = true;
            this.but_adauga.Click += new System.EventHandler(this.but_adauga_Click);
            // 
            // but_lista
            // 
            this.but_lista.BackColor = System.Drawing.Color.Transparent;
            this.but_lista.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.but_lista.ForeColor = System.Drawing.Color.Black;
            this.but_lista.Image = ((System.Drawing.Image)(resources.GetObject("but_lista.Image")));
            this.but_lista.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.but_lista.Location = new System.Drawing.Point(38, 48);
            this.but_lista.Name = "but_lista";
            this.but_lista.Size = new System.Drawing.Size(239, 59);
            this.but_lista.TabIndex = 0;
            this.but_lista.TabStop = false;
            this.but_lista.Text = "Lista angajatilor";
            this.but_lista.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.but_lista.UseVisualStyleBackColor = false;
            this.but_lista.Click += new System.EventHandler(this.but_lista_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.Location = new System.Drawing.Point(0, 0);
            this.pictureBox1.Margin = new System.Windows.Forms.Padding(4);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(129, 81);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // label3
            // 
            this.label3.AccessibleRole = System.Windows.Forms.AccessibleRole.None;
            this.label3.AutoSize = true;
            this.label3.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.label3.Location = new System.Drawing.Point(543, 315);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(247, 25);
            this.label3.TabIndex = 1;
            this.label3.Text = "Select an option to start";
            // 
            // Main
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 23F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(55)))), ((int)(((byte)(150)))), ((int)(((byte)(131)))));
            this.ClientSize = new System.Drawing.Size(1516, 713);
            this.Controls.Add(this.mainpanel);
            this.Controls.Add(this.meniu);
            this.Controls.Add(this.bar);
            this.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.ForeColor = System.Drawing.Color.Transparent;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Main";
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "Human Resources Managing System";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.Load += new System.EventHandler(this.Main_Load);
            this.bar.ResumeLayout(false);
            this.bar.PerformLayout();
            this.meniu.ResumeLayout(false);
            this.mainpanel.ResumeLayout(false);
            this.mainpanel.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel bar;
        private System.Windows.Forms.Panel meniu;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button but_setari;
        private System.Windows.Forms.Button but_cauta;
        private System.Windows.Forms.Button but_modifica;
        private System.Windows.Forms.Button but_elimina;
        private System.Windows.Forms.Button but_adauga;
        public System.Windows.Forms.Button but_lista;
        private System.Windows.Forms.Panel mainpanel;
        private System.Windows.Forms.Label label3;
    }
}

