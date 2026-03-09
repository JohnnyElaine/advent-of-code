using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Day4
{
    internal class Util
    {
        static string execPath = Assembly.GetEntryAssembly().Location; // Get the path to the executable
        static string execFolderPath = Path.GetDirectoryName(execPath); // Get the folder of the executable
        static string resourcesPath = Path.Combine(execFolderPath, @"..\..\..\Resources"); // Go up 3 Levels to the Resources Folder

        public static List<Assignment> readInput(string filename)
        {
            string filePath = Path.Combine(resourcesPath, filename);
            List<Assignment> assignments = new List<Assignment>();

            IEnumerable<string> lines = File.ReadLines(filePath);
            foreach (string line in lines) assignments.Add(ConvertLineToAssignment(line.Trim()));

            return assignments;
        }

        private static int[] ConvertRangeToIntArr(string range)
        {
            string[] rangeSplit = range.Split("-");
            return new int[2] { int.Parse(rangeSplit[0]), int.Parse(rangeSplit[1]) };
        }

        private static Assignment ConvertLineToAssignment(string line)
        {
            string[] lineSplit = line.Split(',');

            int[] left = ConvertRangeToIntArr(lineSplit[0]);
            int[] right = ConvertRangeToIntArr(lineSplit[1]);

            return new Assignment(left, right);
        }
    }
}
