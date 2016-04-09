#include <functional>
#include <string>
#include <map>
#include "Sales_data.h"
using namespace std;
int add(int i, int j) { return i + j; }
Sales_data add(const Sales_data&, const Sales_data&);
int main()
{
    map<string, function<int(int, int)>> binops;
    binops.insert({"+", add});  // error: which add?
    int (*fp)(int, int) = add;  // pointer to the version of add that takes two ints
    binops.insert({"+", fp});   // ok: fp points to the right version
    // ok: use a lambda to disambiguate which version of add we want to use
    binops.insert({"+", [](int a, int b) { return add(a, b);} );
    return 0;
}