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

namespace LogViewer
{
    public partial class Form1 : System.Windows.Forms.Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void freezeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            timer1.Enabled = !timer1.Enabled;
            if (!timer1.Enabled)
            {
                freeze.ForeColor = Color.Red;
            }
            else
            {
                freeze.ForeColor = Color.Green;
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

        private void LogView_Load_1(object sender, EventArgs e)
        {

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            string path = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments), "My Games", "GlobalCompanyFactorySimulator");

            if (File.Exists(path + "/LuaLogEditor.log"))
            {
                listBox1.Items.Clear();
                var lines = File.ReadAllLines(path + "/LuaLogEditor.log");
                listBox1.Items.AddRange(lines);

                this.Text = "Log View [" + DateTime.Now.ToString() + "] - Copyright (c) by Tom Wießner";
                listBox1.SelectedIndex = listBox1.Items.Count - 1;
                listBox1.SelectedIndex = -1;
                listBox1.DrawMode = DrawMode.OwnerDrawFixed;
            }
        }
    }
}
