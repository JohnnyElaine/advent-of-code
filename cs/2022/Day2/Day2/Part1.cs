using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Day2
{
    internal class Part1
    {
        public static int Solve(List<Round> rounds)
        {
            int sum = 0;
            for (int i = 0; i < rounds.Count; i++) sum += rounds[i].eval1();

            return sum;
        }
    }
}
