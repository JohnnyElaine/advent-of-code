using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Day1
{
    internal class Part2
    {
        public static int Solve(List<int> input)
        {
            int count = 0;

            int previous = input[0] + input[1] + input[2];
            int current = 0;

            for (int i = 1; i < input.Count - 2; i++)
            {
                current = input[i] + input[i + 1] + input[i + 2];

                if (current > previous) count++;

                previous = current;
            }

            return count;
        }
    }
}
