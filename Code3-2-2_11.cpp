#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s4 = s1 + ", "; // ok: adding a string and a literal
    string s5 = "hello" + ", "; // error: no string operand
    string s6 = s1 + ", " + "world"; // ok: each + has a string operand
    string s7 = "hello" + ", " + s2; // error: can't add string literals
    return 0;
}
