using System;
using System.IO;
using System.Reflection;

namespace Day1
{
    internal class Program
    {
        static void Main(string[] args)
        {

            string input = Util.readInput("input.txt");
         
            // Part 1:
            Console.Write("Part 1: {0}", Part1.Solve(input));

            // Part 2:
            Console.Write("Part 2: {0}", Part2.Solve(input));

        }
    }


}