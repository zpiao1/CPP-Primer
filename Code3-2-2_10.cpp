#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1 = "hello", s2 = "world";    // no punctuation in s1 or s2
    string s3 = s1 + ", " + s2 + '\n';
    string s4 = s1 + ", "; // ok: adding a string and a literal
    string s5 = "hello" + ", "; // error: no string operand
    string s6 = s1 + ", " + "world"; // ok: each + has a string operand
    string s7 = "hello" + ", " + s2; // error: can't add string literals
    return 0;
}
