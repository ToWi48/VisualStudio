
namespace DownloadManager
{
    partial class Form1
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
            this.list = new System.Windows.Forms.ListBox();
            this.name = new System.Windows.Forms.TextBox();
            this.path = new System.Windows.Forms.Button();
            this.add = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // list
            // 
            this.list.FormattingEnabled = true;
            this.list.Location = new System.Drawing.Point(12, 12);
            this.list.Name = "list";
            this.list.Size = new System.Drawing.Size(423, 121);
            this.list.TabIndex = 0;
            // 
            // name
            // 
            this.name.Location = new System.Drawing.Point(12, 139);
            this.name.Name = "name";
            this.name.Size = new System.Drawing.Size(261, 20);
            this.name.TabIndex = 1;
            // 
            // path
            // 
            this.path.Location = new System.Drawing.Point(279, 136);
            this.path.Name = "path";
            this.path.Size = new System.Drawing.Size(75, 23);
            this.path.TabIndex = 2;
            this.path.Text = "Pfad";
            this.path.UseVisualStyleBackColor = true;
            this.path.Click += new System.EventHandler(this.path_Click);
            // 
            // add
            // 
            this.add.Location = new System.Drawing.Point(360, 136);
            this.add.Name = "add";
            this.add.Size = new System.Drawing.Size(75, 23);
            this.add.TabIndex = 3;
            this.add.Text = "Anlegen";
            this.add.UseVisualStyleBackColor = true;
            this.add.Click += new System.EventHandler(this.add_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(447, 577);
            this.Controls.Add(this.add);
            this.Controls.Add(this.path);
            this.Controls.Add(this.name);
            this.Controls.Add(this.list);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox list;
        private System.Windows.Forms.TextBox name;
        private System.Windows.Forms.Button path;
        private System.Windows.Forms.Button add;
    }
}

