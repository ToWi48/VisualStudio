using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace TextAssetToLua
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void BTN_Resources_Click(object sender, EventArgs e)
        {
            using (var fbd = new FolderBrowserDialog())
            {
                DialogResult result = fbd.ShowDialog();

                TB_Resources.Text = fbd.SelectedPath;
            }
        }

        private void BTN_Resolution_Click(object sender, EventArgs e)
        {
            using (var fbd = new FolderBrowserDialog())
            {
                DialogResult result = fbd.ShowDialog();

                TB_Resolution.Text = fbd.SelectedPath;
            }
        }

        private void BTN_Start_Click(object sender, EventArgs e)
        {
            this.BackColor = Color.Red;
            string currentFolder = TB_Resources.Text;

            foreach (string path in Directory.EnumerateFileSystemEntries(currentFolder))
            {
                if (File.Exists(path))
                {
                    // This path is a file
                    ProcessFile(path);
                }
                else if (Directory.Exists(path))
                {
                    // This path is a directory
                    ProcessDirectory(path);
                }
                else
                {
                    Console.WriteLine("{0} is not a valid file or directory.", path);
                }
            }
            this.BackColor = Form1.DefaultBackColor;
        }

        // Process all files in the directory passed in, recurse on any directories 
        // that are found, and process the files they contain.
        public void ProcessDirectory(string targetDirectory)
        {
            // Process the list of files found in the directory.
            string[] fileEntries = Directory.GetFiles(targetDirectory);
            foreach (string fileName in fileEntries)
                ProcessFile(fileName);

            // Recurse into subdirectories of this directory.
            string[] subdirectoryEntries = Directory.GetDirectories(targetDirectory);
            foreach (string subdirectory in subdirectoryEntries)
                ProcessDirectory(subdirectory);
        }

        // Insert logic for processing found files here.
        public void ProcessFile(string path)
        {
            if(!Path.GetFileName(path).Contains(".meta"))
                setLua(path, TB_Resolution.Text);
        }

        private void setLua(string getPath, string setPath)
        {
            List<string> codeLines = new List<string>();
            List<string> codeLinesNew = new List<string>();

            // put all lines in a list
            foreach (string line in File.ReadLines(getPath))
            {
                codeLines.Add(line);
            }

            // cut lines 1 - 14
            for (int i = 0; i < 13; i++)
            {
                codeLines.RemoveAt(0);
            }

            // cut last line
            codeLines.RemoveAt(codeLines.Count-1);

            string firstLine = codeLines[0];
            codeLines[0] = firstLine.Remove(0, 5);


            string lastLine = codeLines[codeLines.Count - 1];
            codeLines[codeLines.Count - 1] = lastLine.Remove(lastLine.Length - 1, 1); ;

            if(codeLines.Count() > 1)
            {
                int c = 1;
                // remove offset
                foreach (string line in codeLines)
                {
                    if (c == 1)
                    {
                        if (line.Length <= 4)
                            codeLinesNew.Add(line);
                        else
                            codeLinesNew.Add(line.Remove(0, 4));
                        c = 0;
                    }
                    else
                        c++;
                }
            }else
            {
                // add line breaks
                string ff = codeLines[0];
                ff = ff.Remove(0, 4);

                foreach (string line in ff.Split(new[] { "\\r\\n" }, StringSplitOptions.None).ToList())
                {
                    codeLinesNew.Add(line.Replace("\\t", "\t").Replace("\\\"", "\""));
                }
            }

            // last we safe it to the new location
            string fileName = Path.GetFileName(getPath);
            string baseDir = getPath.Replace(fileName, "").Replace(TB_Resources.Text, TB_Resolution.Text);

            Directory.CreateDirectory(baseDir);
            //MessageBox.Show(baseDir);
            File.WriteAllLines(Path.Combine(baseDir, fileName.Replace(".asset", ".lua")), codeLinesNew);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            char[] text = "Tom ist megamäßig!".ToCharArray();
            String mystring = new String(text);
            MessageBox.Show(mystring);
        }
    }
}
