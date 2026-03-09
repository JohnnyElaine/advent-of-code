using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Day1
{
    internal class Part1
    {
        public static int Solve(List<int> input)
        {
            int count = 0;
            for (int i = 0; i < input.Count - 1; i++) if (input[i] < input[i + 1]) count++;
            
            return count;
        }
    }
}
