#include <iostream>
using namespace std;
void fcn3()
{
    size_t v1 = 42; // loca variable
    // f can change the value of the variables it captures
    auto f = [v1] () mutable { return ++v1; };
    v1 = 0;
    auto j = f();   // j is 43;
}
void fcn4()
{
    size_t v1 = 42; // local variable
    // v1 is a reference to a non const variable
    // we can change that variable through the reference inside f2
    auto f2 = [&v1] { return ++v1; };
    v1 = 0;
    auto j = f2();  // j is 1;
}