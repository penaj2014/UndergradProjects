//Classic string reversing in C++ done within a method of an object
#include <iostream>
using namespace std;

class StringReverse
{
public:
    StringReverse();
    ~StringReverse();
    void StringSet();
private:
string in;
};

StringReverse::StringReverse()
{
    StringSet();
}

StringReverse::~StringReverse()
{

}
void StringReverse::StringSet()
{
    cin >> in;
    cout << "echo: " << in << endl;
}

int main ()
{
    int interger = 0;
    cin >> interger;
    StringReverse test;
    return 0;
}