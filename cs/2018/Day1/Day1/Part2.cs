using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Day1
{
    class Part2
    {
        public static int Solve(List<int> input)
        {
            int currFrequency = 0;
            HashSet<int> visited = new HashSet<int>();

            int i = 0;
            while (!visited.Contains(currFrequency))
            {
                
                visited.Add(currFrequency);
                currFrequency += input[i];

                i = (i + 1) % input.Count;
            }


            return currFrequency;
        }
    }
}
