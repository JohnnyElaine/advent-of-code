using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.ConstrainedExecution;
using System.Text;
using System.Threading.Tasks;

namespace Day3
{
    internal class Part2
    {
        private static int groupSize = 3;
        public static int Solve(List<Backpack> backpacks)
        {
            
            HashSet<HashSet<char>> group = new HashSet<HashSet<char>>();
            int counter = 0;
            int sum = 0;

            foreach (Backpack backpack in backpacks)
            {
                group.Add(backpack.AsHashSet());

                counter = (counter + 1) % groupSize;

                if (counter == 0)
                {
                    char commonItem = GetCommonItem(group);
                    sum += Backpack.ConvertItemToPriority(commonItem);
                    group = new HashSet<HashSet<char>>();
                }
            }



            return sum;
        }

        private static char GetCommonItem(HashSet<HashSet<char>> group)
        {
            HashSet<char> set1 = group.First();
            foreach (HashSet<char> other in group) set1.IntersectWith(other);

            return set1.First();
        }
    }
}
