#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    // the compiler determines the type of b and e; see § 2.5.2 (p. 68)
    // b denotes the first element and e denotes one past the last element in v
    auto b = v.begin(), e = v.end();    // b and e have the same type
    return 0;
}
