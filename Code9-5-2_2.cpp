#include <string>
using namespace std;
int main()
{
    string s = "some string", s2 = "some other string";
    s.insert(0, s2);    // insert a copy of s2 before position 0 in s
    // insert s2.size() characters form s2 starting at s2[0] before s[0]
    s.insert(0, s2, 0, s2.size());
    return 0;
}