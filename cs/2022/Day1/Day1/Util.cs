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
        public static string readInput(string filename)
        {
            string execPath = Assembly.GetEntryAssembly().Location; // Get the path to the current executable
            string execFolderPath = Path.GetDirectoryName(execPath);
            string resourcesPath = Path.Combine(execFolderPath, @"..\..\..\Resources"); // Go up 3 Levels to the Resources Folder

            string filePath = Path.Combine(resourcesPath, filename);

            return File.ReadAllText(filePath);
        }
    }
}
