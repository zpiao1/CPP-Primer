#include <iostream>
using namespace std;
void fcn1()
{
    size_t v1 = 42; // local variable
    // copies v1 into the callable object named f
    auto f = [v1] { return v1; };
    v1 = 0;
    auto j = f();   // j is 42; f stored copy of v1 when we created it
}
void fcn2()
{
    size_t v1 = 42; // local variable
    // the object f2 contains a reference to v1
    auto f2 = [&v1] { return v1; };
    v1 = 0;
    auto j = f2();  // j is 0; f2 refers to v1; it doesn't store it
}