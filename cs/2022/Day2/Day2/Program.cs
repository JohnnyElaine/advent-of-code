using System.IO;

namespace Day2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<Round> rounds = Util.readInput("input.txt");     

            //Part 1:
            Console.WriteLine("Part 1: {0}", Part1.Solve(rounds));

            //Part 2:
            Console.WriteLine("Part 2: {0}", Part2.Solve(rounds));
        }
    }
}