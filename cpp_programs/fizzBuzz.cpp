////Classic fizzbuzz question completed inside a function written in C++.
#include <iostream>
using namespace std;

void fizzBuzzer(int);
void fizzBuzzer(int x)
{
    for (int  i = 1; i < x; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
            cout << "fizzbuzz";
        else if (i % 3 == 0)
            cout << "fizz";
        else if (i % 5 == 0)
            cout << "buzz";
        else 
            cout << i;
        cout << ", ";
    }
}

int main()
{
    fizzBuzzer(100);    
    return 0;
}