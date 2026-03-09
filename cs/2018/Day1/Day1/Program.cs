namespace Day1
{
    internal class Program
    {

        private const string PATH_TO_INPUT_TXT = "../../../Input/input.txt";
        static void Main(string[] args)
        {
            Console.WriteLine("Part 1: " + Part1.Solve(PATH_TO_INPUT_TXT));


            Console.WriteLine("Part 2: " + Part2.Solve(Util.readInput(PATH_TO_INPUT_TXT)));
        }
    }
}