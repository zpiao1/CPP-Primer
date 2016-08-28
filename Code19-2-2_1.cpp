#include <typeinfo>
using namespace std;
int main()
{
    Derived *dp = new Derived;
    Base *dp = dp;  // both pointers points to a Derived object
    // compare the type of two objects at run time
    if (typeid(*bp) == typeid(*dp)) {
        // bp and dp point to objects of the same type
    }
    // test whether the run-time type is a specific type
    if (typeid(*bp) == typeid(Derived)) {
        // bp actually points to a Derived
    }
    // test always fails: the type of bp is pointer to Base
    if (typeid(bp) == typeid(Derived)) {
        // code never executed
    }
    return 0;
}