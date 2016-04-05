#include <iostream>
#include <utility>
using namespace std;
int main()
{
    int i = 42;
    int &r = i; // ok: r refers to i
    int &&rr = i;   // error: cannot bind an rvalue reference to an lvalue
    int &r2 = i * 42;   // error: i * 42 is an rvalue
    const int &r3 = i * 42; // ok: we can bind a reference to const to an rvalue
    int &&rr2 = i * 42; // ok: bind rr2 to the result of the multiplication
    int &&rr1 = 42;     // ok: literals are rvalues
    int &&rr2 = rr1;    // error: the expression rr1 is an lvalue!
    int &&rr3 = std::move(rr1); // ok
    return 0;
}