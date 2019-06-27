
////C# syntax practice
////Basics display of C#; this is a placeholder for an upcoming project
////that will simulate a FCFS CPU scheduler 03.20.19
////
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
//using static System.Console;              

////Main Loop showscases simple C# I/O 
////
////
////
namespace firstApp
{
    class Program
    {
        static void Main(string[] args)
        {
            int age = 23;
            int [] luckyNumbers;                      //declaring an array
            luckyNumbers = new[] {7, 77, 777};      //note: copying from a source to a destination can be done by Array.Copy(source, dest, 3); will copy first 3 elements
            char initials = 'j';
            string sample = "";

            Console.WriteLine("Why don't you go ahead and type your age in: ");
            age = Convert.ToInt32(Console.Read());

            if(age > 21)
            {
                Console.WriteLine("I recommend you try Founder's Breakfast Stout!");
            }
            else 
            {
                Console.WriteLine("Come back when you're over 21.");
                Console.WriteLine("These are the birthdays you're missing :");
                for (int i = ++age; i < 21; i++)
                {
                    Console.Write("{0} ", i);
                }
            }
                
            Console.Read();
        }
    }
}


