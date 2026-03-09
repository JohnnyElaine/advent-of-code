using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Day3
{
    internal class Part1
    {
        public static int Solve(List<Backpack> backpacks)
        {
            int sum = 0;
            foreach (Backpack backpack in backpacks) sum += backpack.GetCommonItemPriority();
           
            return sum;
        }
    }
}
