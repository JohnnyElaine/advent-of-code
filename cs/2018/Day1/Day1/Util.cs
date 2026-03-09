using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Day1
{
    class Util
    {
        public static List<int> readInput(string path)
        {
            List<int> list = new List<int>();

            using (StreamReader reader = new StreamReader(path))
            {
                string line;
                while ((line = reader.ReadLine()) != null)
                {
                    list.Add(int.Parse(line.Trim()));
                }
            }

            return list;
        }
    }
}
