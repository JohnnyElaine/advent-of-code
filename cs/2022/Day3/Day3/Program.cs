namespace Day3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<Backpack> backpacks = Util.readInput("input.txt");

            Console.WriteLine("Part 1: {0}", Part1.Solve(backpacks));
            Console.WriteLine("Part 2: {0}", Part2.Solve(backpacks));
        }
    }
}