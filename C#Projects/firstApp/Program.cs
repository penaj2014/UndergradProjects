//PROGRAM PURPOSE:
//To convey the use of objects in C# with the purpose of altering fields in a class via 
//use of methods.
////
////

using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;


 
////MAIN PROGRAM
////
////
namespace firstApp
{
    class Program
    {
        static void Main(string[] args)
        {
            int pay;
            Staff staff1 = new Staff("Jorge");
            staff1.HoursWorked = 160;
            pay = staff1.CalculatePay(1000,400);
            Console.WriteLine("Pay = {0}", pay);


        }
    }
}

////DESCRIPTION:
////This class holds private fields that contain weekly pay for a sample employee
////Default constructors assign a name to the staff member
////
////
class Staff
{
    private string nameOfStaff;
    private const int hourlyRate = 30;
    private int hWorked;

    public int HoursWorked
    {
        get{return hWorked;}
        set{
            if (value > 0)
            hWorked = value;
            else
                hWorked = 0;
        }
    }
    public void PrintMessage()
    {
        Console.WriteLine("Calculating....");
    }
    public int CalculatePay()
    { 
        PrintMessage();
        int staffPay;
        staffPay = hWorked *hourlyRate;
        if (hWorked > 0)
            return staffPay;
        else    
            return 0; 
    }
    public int CalculatePay(int bonus, int allowance)
    { 
        PrintMessage();
        if (hWorked > 0)
            return hWorked *hourlyRate +bonus + allowance;
        else    
            return 0; 
    }
    public Staff(string name)
    {
        nameOfStaff = name;
        Console.WriteLine("\n" + nameOfStaff);
        Console.WriteLine("______________________________");
    }
    public Staff(string firstName, string lastName)
    {
        nameOfStaff = firstName + " " + lastName;
        Console.WriteLine("\n" + nameOfStaff);
        Console.WriteLine("______________________________");
    }
}
