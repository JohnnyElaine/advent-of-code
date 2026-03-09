using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Day1
{
    class Part1
    {
        public static int Solve(string path)
        {
            int sum = 0;
            using (StreamReader reader = new StreamReader(path))
            {
                string line;
                while ((line = reader.ReadLine()) != null)
                {
                    sum += int.Parse(line.Trim());
                }
            }

            return sum;
        }
    }
}
