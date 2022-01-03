namespace TextAssetToLua
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
            this.BTN_Resources = new System.Windows.Forms.Button();
            this.TB_Resources = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.TB_Resolution = new System.Windows.Forms.TextBox();
            this.BTN_Resolution = new System.Windows.Forms.Button();
            this.BTN_Start = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // BTN_Resources
            // 
            this.BTN_Resources.Location = new System.Drawing.Point(469, 36);
            this.BTN_Resources.Name = "BTN_Resources";
            this.BTN_Resources.Size = new System.Drawing.Size(80, 20);
            this.BTN_Resources.TabIndex = 0;
            this.BTN_Resources.Text = "select";
            this.BTN_Resources.UseVisualStyleBackColor = true;
            this.BTN_Resources.Click += new System.EventHandler(this.BTN_Resources_Click);
            // 
            // TB_Resources
            // 
            this.TB_Resources.Location = new System.Drawing.Point(12, 36);
            this.TB_Resources.Name = "TB_Resources";
            this.TB_Resources.Size = new System.Drawing.Size(451, 20);
            this.TB_Resources.TabIndex = 1;
            this.TB_Resources.Text = "D:\\WRS_Modding\\UTINY_27.12.21\\globalgamemanagers\\Assets\\Resources\\lua";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 20);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(83, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Path Resources";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 77);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(82, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Path Resolution";
            // 
            // TB_Resolution
            // 
            this.TB_Resolution.Location = new System.Drawing.Point(12, 93);
            this.TB_Resolution.Name = "TB_Resolution";
            this.TB_Resolution.Size = new System.Drawing.Size(451, 20);
            this.TB_Resolution.TabIndex = 4;
            this.TB_Resolution.Text = "C:\\Users\\Tom\\Desktop\\Test";
            // 
            // BTN_Resolution
            // 
            this.BTN_Resolution.Location = new System.Drawing.Point(469, 93);
            this.BTN_Resolution.Name = "BTN_Resolution";
            this.BTN_Resolution.Size = new System.Drawing.Size(80, 20);
            this.BTN_Resolution.TabIndex = 5;
            this.BTN_Resolution.Text = "select";
            this.BTN_Resolution.UseVisualStyleBackColor = true;
            this.BTN_Resolution.Click += new System.EventHandler(this.BTN_Resolution_Click);
            // 
            // BTN_Start
            // 
            this.BTN_Start.Location = new System.Drawing.Point(12, 128);
            this.BTN_Start.Name = "BTN_Start";
            this.BTN_Start.Size = new System.Drawing.Size(537, 51);
            this.BTN_Start.TabIndex = 6;
            this.BTN_Start.Text = "Start";
            this.BTN_Start.UseVisualStyleBackColor = true;
            this.BTN_Start.Click += new System.EventHandler(this.BTN_Start_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(277, 185);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(186, 20);
            this.button1.TabIndex = 7;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(565, 211);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.BTN_Start);
            this.Controls.Add(this.BTN_Resolution);
            this.Controls.Add(this.TB_Resolution);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.TB_Resources);
            this.Controls.Add(this.BTN_Resources);
            this.Name = "Form1";
            this.Text = "TextAsset to Lua File";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button BTN_Resources;
        private System.Windows.Forms.TextBox TB_Resources;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox TB_Resolution;
        private System.Windows.Forms.Button BTN_Resolution;
        private System.Windows.Forms.Button BTN_Start;
        private System.Windows.Forms.Button button1;
    }
}

