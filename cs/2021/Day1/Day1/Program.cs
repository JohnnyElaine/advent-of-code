namespace Day1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<int> input = Util.ReadInput("input.txt");

            Console.WriteLine("Part 1: {0}", Part1.Solve(input));
            Console.WriteLine("Part 2: {0}", Part2.Solve(input));
        }
    }
}