using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Day4
{
    internal class Assignment
    {
        // [0] ==> start index
        // [1] ==> end index
        private int[] leftRange;
        private int[] rightRange;

        public Assignment(int[] leftRange, int[] rightRange) 
        {
            this.leftRange = leftRange;
            this.rightRange = rightRange;
        }

        public bool IsFullyOverlapping()
        {
            return (leftRange[0] >= rightRange[0] && leftRange[1] <= rightRange[1]) || (leftRange[0] <= rightRange[0] && leftRange[1] >= rightRange[1]);
        }

        public bool IsOverlapping()
        {
            return (leftRange[1] >= rightRange[0]) && (leftRange[0] <= rightRange[1]);
        }

    }
}
