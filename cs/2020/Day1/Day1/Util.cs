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

        public static HashSet<int> ReadInput(string filename)
        {
            HashSet<int> values = new HashSet<int>();
            string filepath = Path.Combine(resourcesPath, filename);

            using (StreamReader reader = new StreamReader(filepath))
            {
                string line;
                while ((line = reader.ReadLine()) != null)
                {
                    values.Add(Int32.Parse(line.Trim()));
                }
            }

            return values;
        }
    }
}
