namespace Day4
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<Assignment> assignments = Util.readInput("input.txt");

            Console.WriteLine("Part 1: {0}", Part1.Solve(assignments));

            Console.WriteLine("Part 2: {0}", Part2.Solve(assignments));
        }
    }
}