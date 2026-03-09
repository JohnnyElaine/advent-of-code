using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Day2
{
    internal class Round
    {
        /*
         * Win/Loss Matrix for Part 1
         * column = my move
         * row = opponents move
         * 
         * 
         *          Rock    Paper   Scissors
         * Rock     Draw    Win     Loss
         * Paper    Loss    Draw    Win
         * Scissors Win     Loss    Draw
         * 
         * The value of Rock/Paper/Scissors reflects the points one recieves when choosing the shape:
         * Rock = 1
         * Paper = 2
         * Scissors = 3
         * 
         * The intersection of my choice and the opponents choice is the points gained for:
         * Loss = 0
         * Draw = 3
         * Win = 6
         * 
         * Points = Shape chosen + outcome
         */

        private static int[,] winLossMatrix1 = new int[4, 4] {
            {0, 1, 2, 3},
            {1, 3, 6, 0},
            {2, 0, 3, 6},
            {3, 6, 0, 3}
            };

        /*
         * Win/Loss Matrix for Part 2
         * column = the outcome
         * row = opponents move
         * 
         * the intersection [row, column] = the move i need to play
         * 
         * 
         *          Loss        Draw        Win
         * Rock     Scissors    Rock        Paper
         * Paper    Rock        Paper       Scissors
         * Scissors Paper       Scissors    Rock
         * 
         * The value of Rock/Paper/Scissors reflects the points one recieves when choosing the shape:
         * Rock = 1
         * Paper = 2
         * Scissors = 3
         * 
         * Loss = 0
         * Draw = 3
         * Win = 6
         * 
         * Points = Shape chosen + outcome
         */
        private static int[,] winLossMatrix2 = new int[4, 4] {
            {0, 0, 3, 6},
            {1, 3, 1, 2},
            {2, 1, 2, 3},
            {3, 2, 3, 1}
            };

        private int opponentMove;
        private int myMove;
    

        public Round(int opponentMove, int myMove)
        {
            this.opponentMove = opponentMove;
            this.myMove = myMove;
        }
        /// <summary>
        /// Evaluates the round according to the rules of part 1
        /// </summary>
        /// <returns>The points gained for this round</returns>
        public int eval1()
        {
            return myMove + winLossMatrix1[opponentMove, myMove];
        }

        /// <summary>
        /// Evaluates the round according to the rules of part 2
        /// </summary>
        /// <returns>The points gained for this round</returns>
        public int eval2()
        {
            return convertMoveToOutcome(myMove) + winLossMatrix2[opponentMove, myMove];
        }

        /// <summary>
        /// Used for Part 2 Only. Converts a move (1,2,3)/(X/Y/Z) to the an outcome (0/3/6)/(Loss/Draw/Win)
        /// </summary>
        /// <param name="move"></param>
        /// <returns>The outcome (the points associated with the outcome)</returns>
        private int convertMoveToOutcome(int move)
        {
            // X = Loss
            if (myMove == 1)
            {
                return 0;
            }

            // Y = Draw
            if (myMove == 2)
            {
                return 3;
            }

            // Z = Win
            return 6;
        }

        public override string ToString()
        {
            return $"({opponentMove}, {myMove})";
        }
    }
}
