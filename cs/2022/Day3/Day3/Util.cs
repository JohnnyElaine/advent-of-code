using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Day3
{
    internal class Util
    {
        static string execPath = Assembly.GetEntryAssembly().Location; // Get the path to the executable
        static string execFolderPath = Path.GetDirectoryName(execPath); // Get the folder of the executable
        static string resourcesPath = Path.Combine(execFolderPath, @"..\..\..\Resources"); // Go up 3 Levels to the Resources Folder

        public static List<Backpack> readInput(string filename)
        {
            string filePath = Path.Combine(resourcesPath, filename);
            List<Backpack> backpacks = new List<Backpack>();
                           
            IEnumerable<string> lines = File.ReadLines(filePath);
            foreach (string line in lines) backpacks.Add(new Backpack(line.Trim()));
                          
            return backpacks;
        }
    }
}
