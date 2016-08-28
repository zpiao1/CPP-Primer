#include <typeinfo>
using namespace std;
class Base;
class Derived;
void f(const Base &b)
{
    try {
        const Derived &d = dynamic_cast<const Derived&>(b);
    // use the Derived object to which b referred
    } catch (bad_cast) {
        // handle the fact that the cast failed
    }
}
int main()
{
    if (Derived *dp = dynamic_cast<Derived*>(bp))
    {
        // use the Derived object to which dp points
    } else {    // bp points at a Base object
        // use the Base object to which bp points
    }
    return 0;
}