using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Day1
{
    internal class Part2
    {
        public static int Solve(string input)
        {
            SortedSet<int> totalCaloriesPerElf = getTotalCaloriesPerElf(input);
            IEnumerator<int> enumerator = totalCaloriesPerElf.Reverse().GetEnumerator();

            int sum = 0;
            for (int i = 0; i < 3 && enumerator.MoveNext(); i++) sum += enumerator.Current;
            
            return sum;
        }

        /// <summary>
        /// Sums up all calories per elf and stores them in a SortedSet
        /// </summary>
        /// <param name="input">the puzzle input</param>
        /// <returns>SortedSet containing all calories per elf</returns>
        private static SortedSet<int> getTotalCaloriesPerElf(string input)
        {
            SortedSet<int> totalCaloriesPerElf = new SortedSet<int>();
            string[] allElfCaloires = input.Split(new string[] { "\r\n\r\n", "\n\n" }, StringSplitOptions.RemoveEmptyEntries);

            foreach (string elfCalories in allElfCaloires) totalCaloriesPerElf.Add(getSumForElf(elfCalories));

            return totalCaloriesPerElf;
        }


        /// <summary>
        /// Given a string containing alle the calories that a single elf has (calories are spereated by '\n'). 
        /// This function calculates the sum of all calories.
        /// </summary>
        /// <param name="elfCaloires">A String containing all calories of a single elf (separated by '\n')</param>
        /// <returns>The sum of all calories </returns>
        private static int getSumForElf(string elfCaloires)
        {
            string[] lines = elfCaloires.Split('\n');

            int sum = 0;
            foreach (string line in lines)
            {
                int calorie = int.Parse(line);
                sum += calorie;
            }

            return sum;
        }
    }
}
