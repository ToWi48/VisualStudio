using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace LogView
{
    public partial class Form1 : Form
    {
        string path;
        public Form1(string lpath = "")
        {
            InitializeComponent();
            path = lpath;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            if (path == "")
            {
                using (OpenFileDialog openFileDialog = new OpenFileDialog())
                {
                    openFileDialog.InitialDirectory = "c:\\";
                    openFileDialog.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
                    openFileDialog.FilterIndex = 2;
                    openFileDialog.RestoreDirectory = true;

                    if (openFileDialog.ShowDialog() == DialogResult.OK)
                    {
                        //Get the path of specified file
                        path = openFileDialog.FileName;
                    }
                }
            }
        }

        private void listBox1_DrawItem(object sender, DrawItemEventArgs e)
        {
            try
            {
                e.DrawBackground();
                Brush myBrush = Brushes.Yellow;

                //int sayi = Convert.ToInt32(((ListBox)sender).Items[e.Index].ToString());
                if (((ListBox)sender).Items[e.Index].ToString().Contains("|!|"))
                {
                    myBrush = Brushes.Red;
                }
                else if (((ListBox)sender).Items[e.Index].ToString().Contains("|A|"))
                {
                    myBrush = Brushes.Yellow;
                }
                else if (((ListBox)sender).Items[e.Index].ToString().Contains("|*|"))
                {
                    myBrush = Brushes.Green;
                }
                else if (((ListBox)sender).Items[e.Index].ToString().Contains("***"))
                {
                    myBrush = Brushes.Orange;
                }
                else
                {
                    myBrush = Brushes.Gray;
                }

                e.Graphics.DrawString(((ListBox)sender).Items[e.Index].ToString(),
                e.Font, myBrush, e.Bounds, StringFormat.GenericDefault);

                e.DrawFocusRectangle();
            }
            catch
            {
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            //string path = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments), "My Games", "GlobalCompanyFactorySimulator");

            if (File.Exists(path))
            {
                listBox1.Items.Clear();
                var lines = File.ReadAllLines(path);

                listBox1.Items.AddRange(lines);

                this.Text = "Log View [" + DateTime.Now.ToString() + "] - " + path;
                listBox1.SelectedIndex = listBox1.Items.Count - 1;
                listBox1.SelectedIndex = -1;
                listBox1.DrawMode = DrawMode.OwnerDrawFixed;
            }
        }

        private void listBox1_Click(object sender, EventArgs e)
        {
            timer1.Enabled = !timer1.Enabled;
            if (!timer1.Enabled)
            {
                this.BackColor = Color.Red;
            }
            else
            {
                this.BackColor = Color.Green;
            }
        }
    }
}
