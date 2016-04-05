#include <string>
// error: cannot redefine the build-in operator for ints
int operator+(int, int);
int main()
{
    x == y + z;
    x == (y + z);
    // equivalent calls to a nonmember operator function
    data1 + data2;  // normal expression
    operator+(data1, data2);    // equivalent function call
    data1 += data2; // expression-based "call"
    data1.operator+=(data2);
    string s = "world";
    string t = s + "!"; // ok: we can add a const char * to a string
    string u = "hi" + s;    // would be a member of string
    return 0;
}