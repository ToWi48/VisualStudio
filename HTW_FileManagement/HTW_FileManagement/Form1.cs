using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.IO;
using PdfSharp.Pdf;
using PdfSharp.Pdf.IO;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using HTW_FileManagement.Properties;

// <summary>
// Tom Wiessner
// 21.10.2020
// 
// PDF Merger
// (c) Tom Wießner 2020
// 
// </summary>
namespace HTW_FileManagement
{
    public partial class FileManagement : Form
    {
        public FileManagement()
        {
            InitializeComponent();
        }
        
        string getPath;
        string mainPath;

        private void Form1_Load(object sender, EventArgs e)
        {
            getPath = Settings.Default["getPath"].ToString();
            mainPath = Settings.Default["mainPath"].ToString();
            textBox1.Text = getPath;
            textBox2.Text = mainPath;

            if (getPath != "" && mainPath != "")
            {
                updateBox();
                comboBox1.SelectedIndex = Convert.ToInt32(Settings.Default["group"].ToString());
                comboBox2.SelectedIndex = Convert.ToInt32(Settings.Default["file"].ToString());
            }
            checkBox1.Checked = Convert.ToBoolean(Settings.Default["autodelete"].ToString());
            checkBox2.Checked = Convert.ToBoolean(Settings.Default["update"].ToString());
        }

        private void button1_Click(object sender, EventArgs e)
        {
            updateBox();
        }

        private void updateBox()
        {
            string[] dirs = Directory.GetDirectories(mainPath);

            comboBox1.Items.Clear();
            foreach (string item2 in dirs)
            {
                FileInfo f = new FileInfo(item2);
                comboBox1.Items.Add(f.Name);
            }
        }

        private void textBox2_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog fbd = new FolderBrowserDialog();
            DialogResult result = fbd.ShowDialog();
            mainPath = fbd.SelectedPath;
            textBox2.Text = mainPath;
        }

        private void textBox1_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog fbd = new FolderBrowserDialog();
            DialogResult result = fbd.ShowDialog();
            getPath = fbd.SelectedPath;
            textBox1.Text = getPath;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            setPage();
        }

        private void setPage()
        {
            if (Convert.ToString(comboBox2.SelectedItem) != "" && getFile(getPath) != "")
            {
                string path = mainPath + "/" + comboBox1.SelectedItem + "/" + comboBox2.SelectedItem;
                PdfDocument outputDocument = PdfReader.Open(path, PdfDocumentOpenMode.Import);
                PdfDocument inputDocument = PdfReader.Open(getFile(getPath), PdfDocumentOpenMode.Import);

                // Iterate all pages
                int count = inputDocument.PageCount;
                for (int idx = 0; idx < count; idx++)
                {
                    PdfPage page = inputDocument.Pages[idx];
                    outputDocument.AddPage(page);
                }
                outputDocument.Save(path);

                if (checkBox1.Checked)
                    File.Delete(getFile(getPath));
            }
            else if (!checkBox2.Checked)
                MessageBox.Show("Bitte definieren Sie eine Bais - PDF!");
        }

        private string getFile(string path)
        {
            DirectoryInfo di = new DirectoryInfo(path);
            FileInfo[] files = di.GetFiles("*.pdf");

            if (files.Length > 0)
                return files[0].FullName;
            else
                return "";
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            //string[] files = Directory.GetFiles(getPath);
            DirectoryInfo di = new DirectoryInfo(mainPath + "/" + comboBox1.SelectedItem);
            FileInfo[] files = di.GetFiles("*.pdf");

            comboBox2.Items.Clear();

            foreach (FileInfo item in files)
            {
                comboBox2.Items.Add(item.Name);
            }
            if (comboBox2.Items.Count > 0)
                comboBox2.SelectedIndex = 0;
            else
                comboBox2.Text = "";
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            Settings.Default["getPath"] = getPath;
            Settings.Default["mainPath"] = mainPath;
            Settings.Default["group"] = comboBox1.SelectedIndex;
            Settings.Default["file"] = comboBox2.SelectedIndex;
            Settings.Default["autodelete"] = checkBox1.Checked;
            Settings.Default["update"] = checkBox2.Checked;
            Settings.Default.Save();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (getPath != "")
                label5.Text = getFile(getPath);
                    if (checkBox2.Checked)
                        setPage();
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }
    }
}
