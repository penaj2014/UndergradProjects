using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace c__program
{

////PURPOSE: To insert the data from the specified text file into a dynamic list.
////Precondition: Text file data is in the program's directory/
////Postcondidition: A copy of the text file is placed into a list during the program's execution.
    public class data_input
    {
        private List<string> dataStream  = new List<string>();
        private data_input()
        {
            string path = "data.txt";
                using (StreamReader sr = new StreamReader(path))
                {   
                    
                    while (sr.EndOfStream != true)
                        {
                            dataStream.Add(sr.ReadLine());
                        }
                    sr.Close();
                }
        }


    }       

////PURPOSE: To arrage the data from the txt file into seperate processes organized by CPU and I/O wait time.
////Precondition: Jumbled data from the txt file is in order from first CPU time, then I/O time, and a '$' used to seperate processes.
////Postcondidition: Each set of numbers is placed into a different object at the end of a '$'.
    class fcfs_process : data_input
    {
        private int k = 0;
        private List<string> process_list = new List<string>();
        private fcfs_process(){}
        public int OrganizeProcesses(int j)
        {
            k = j;
            while (dataStream[k] != "$" && dataStream[k] != " ")
            {
                Console.WriteLine(dataStream[k]);
               // process_list.Add(string.ReadLine());
                k++;  
            }
            j = ++k; 
        return j;
        }
    
    }

////PURPOSE: 
////Precondition: 
////Postcondidition: 
    class fcfs_scheduler
    {
        
    
    }

////PURPOSE: To be the driver of the program by calling the classes above/
////Precondition: 
////Postcondidition: 
    class Program
    {
        static void Main(string[] args)
        {
            int j = 0;
            data_input fcfs = new data_input();
            fcfs_process process_one = new fcfs_process();
            fcfs_process process_two = new fcfs_process();
            fcfs_process process_three = new fcfs_process();
            fcfs_process process_four = new fcfs_process();
            fcfs_process process_five = new fcfs_process();
            fcfs_process process_six = new fcfs_process();
            fcfs_process process_seven = new fcfs_process();
            fcfs_process process_eight = new fcfs_process();
            fcfs_process process_nine = new fcfs_process();
            if(j != ' ')
            {
                Console.WriteLine("Process: ");
                j = process_one.OrganizeProcesses(j);
            }
            if(j != ' ')
            {
                Console.WriteLine("Process: ");
                j = process_two.OrganizeProcesses(j);
            }
            if(j != ' ')
            {
                Console.WriteLine("Process: ");
                j = process_three.OrganizeProcesses(j);
            }
            if(j != ' ')
            {
                Console.WriteLine("Process: ");
                j = process_four.OrganizeProcesses(j);
            }
            if(j != ' ')
            {
                Console.WriteLine("Process: ");
                j = process_five.OrganizeProcesses(j);
            }
            if(j != ' ')
            {
                Console.WriteLine("Process: ");
                j = process_six.OrganizeProcesses(j);
            }
            if(j != ' ')
            {
                Console.WriteLine("Process: ");
                j = process_seven.OrganizeProcesses(j);
            }
            if(j != ' ')
            {
                Console.WriteLine("Process: ");
                j = process_eight.OrganizeProcesses(j);
            }
            if(j != ' ')
            {
                Console.WriteLine("Process: ");
                j = process_nine.OrganizeProcesses(j);
            }
            
        }
    }
}



