#include "HasPtr.h"
struct Foo {
    HasPtr h;
};
void swap(Foo &lhs, Foo &rhs)
{
    // WRONG: this function uses the library version of swap, not the HasPtr version
    std::swap(lhs.h, rhs.h);
    // swap other members of type Foo
}
void swap(Foo &lhs, Foo &rhs)
{
    using std::swap;
    swap(lhs.h, rhs.h); // uses the HasPtr version of swap
    // swap other members of type Foo
}
using namespace std;
int main()
{
    HasPtr temp = v1;   // make a temporary copy of the value of v1
    v1 = v2;            // assign the value of v2 to v1
    v2 = temp;          // assign the saved value of v1 to v2
    string *temp = v1.ps;   // make a temporary copy of the pointer in v1.ps
    v1.ps = v2.ps;          // assign the pointer in v2.ps to v1.ps
    v2.ps = temp;           // assign the saved pointer in v1.ps to v2.ps
    return 0;
}
