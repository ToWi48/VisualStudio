using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Mathe
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if (textBox1.Text != "")
            {
                double nennwert = Convert.ToDouble(textBox1.Text);
                double abw = 0.05;

                double res = abw * nennwert;
                textBox2.Text = Convert.ToString(nennwert - res);
                textBox3.Text = Convert.ToString(nennwert + res);
            }
        }
    }
}
