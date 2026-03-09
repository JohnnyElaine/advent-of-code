using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Day3
{
    internal class Backpack
    {
        private string items;
        
        public Backpack(string contents) 
        {   
            this.items = contents;
        }

        public int GetCommonItemPriority()
        {
            return ConvertItemToPriority(GetCommonItem());
        }

        private char GetCommonItem()
        {
            int middle = items.Length / 2;

            HashSet<char> leftCompartmentSet = ItemsToHashSet(items.Substring(0, middle));
            HashSet<char> rightCompartmentSet = ItemsToHashSet(items.Substring(middle, middle));

            leftCompartmentSet.IntersectWith(rightCompartmentSet);
      
            return leftCompartmentSet.First();
        }

        public static int ConvertItemToPriority(char item)
        {
            return item >= 'a' && item <= 'z' ? item - 96 : item - 38;
        }

        private static HashSet<char> ItemsToHashSet(string items)
        {
            HashSet<char> itemsSet = new HashSet<char>();
            for (int i = 0; i < items.Length; i++) itemsSet.Add(items[i]);

            return itemsSet;
        }

        public HashSet<char> AsHashSet()
        {
            return ItemsToHashSet(items);
        }

        public override string ToString()
        {
            return $"({items})";
        }
    }
}
