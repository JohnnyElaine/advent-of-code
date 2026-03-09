using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Day1
{
    internal class Part2
    {
        private const int target = 2020;

        public static int Solve(HashSet<int> values)
        {
            foreach (int val1 in values)
            {
                foreach(int val2 in values)
                {
                    int diff = target - val1 - val2;
                    if (values.Contains(diff)) return val1 * val2 * diff;
                }
            }

            return 0;
        }
    }
}
