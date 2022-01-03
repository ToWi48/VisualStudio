using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DownloadManager
{
    public partial class Form1 : Form
    {
        private string dlPath = Environment.GetFolderPath(Environment.SpecialFolder.UserProfile) + @"\Downloads";
        private string tempPath = "";
        private List<Tuple<string, string>> items = new List<Tuple<string, string>>();

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            MessageBox.Show(");
        }

        private void refreshList()
        {
            list.Items.Clear();
            
            foreach (Tuple<string, string> item in items)
            {
                liusite
            }
        }

        private void add_Click(object sender, EventArgs e)
        {
            items.Add(new Tuple<string, string>(name.Text, tempPath));
        }

        private void path_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog browse = new FolderBrowserDialog();

            if (browse.ShowDialog() == DialogResult.OK)
            {
                tempPath = browse.SelectedPath;
            }
        }
    }
}
