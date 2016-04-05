#include <iostream>
#include <string>
using namespace std;
void print(const string &);
void print(double);     // overloads the print function
void print(int);        // another overload function
void fooBar2(int ival)
{
    print("Value: ");   // calls print(const string &)
    print(ival);        // calls print(int)
    print(3.14);        // calls print(double)
}