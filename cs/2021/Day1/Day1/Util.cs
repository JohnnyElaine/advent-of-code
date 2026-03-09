using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Day1
{
    internal class Util
    {

        static string execPath = Assembly.GetEntryAssembly().Location; // Get the path to the executable
        static string execFolderPath = Path.GetDirectoryName(execPath); // Get the folder of the executable
        static string resourcesPath = Path.Combine(execFolderPath, @"..\..\..\Resources"); // Go up 3 Levels to the Resources Folder

        public static List<int> ReadInput(string filename)
        {
            string filepath = Path.Combine(resourcesPath, filename);

            List<int> l = new List<int>();

            using (StreamReader sr = new StreamReader(filepath))
            {
                string line = "";

                while ((line = sr.ReadLine()) != null)
                {
                    l.Add(Int32.Parse(line.Trim()));
                }
            }

            return l;
        }
    }
}
