using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Day1
{
    internal class Part1
    {
        public static int Solve(string input)
        {
            SortedSet<int> totalCaloriesPerElf = new SortedSet<int>();
            string[] inputSplit = input.Split(new string[] { "\r\n\r\n", "\n\n" }, StringSplitOptions.RemoveEmptyEntries);

            foreach (string elfCalories in inputSplit) totalCaloriesPerElf.Add(SumCaloiresForSignleElf(elfCalories));
            
            return totalCaloriesPerElf.Max;
        }

        private static int SumCaloiresForSignleElf(string elfCalories)
        {
            string[] lines = elfCalories.Split('\n');

            int sum = 0;
            foreach (string calorie in lines)
            {
                sum += int.Parse(calorie);
            }

            return sum;
        }

    }
}
