#include <iostream>
#include "Chapter6.h"
using namespace std;
int main()
{
    //f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}
void f()
{
    cout << "From f()" << endl;
}
void f(int a)
{
    cout << "From f(int a)" << endl;
}
void f(int a, int b)
{
    cout << "From f(int a, int b)" << endl;
}
void f(double a, double b)
{
    cout << "From f(double a, double b = 3.14)" << endl;
}