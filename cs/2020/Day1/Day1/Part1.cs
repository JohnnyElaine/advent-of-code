using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Day1
{
    internal class Part1
    {
        private const int target = 2020;

        public static int Solve(HashSet<int> values)
        {
            foreach (int value in values)
            {
                int diff = target - value;
                if (values.Contains(diff)) return value * diff;
            }

            return 0;
        }
    }
}
