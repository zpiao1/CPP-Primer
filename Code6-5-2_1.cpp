#include <iostream>
#include <string>
using namespace std;
// inline version: find the shorter of two strings
inline const string & shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}
constexpr int new_sz() { return 42; }
constexpr int foo = new_sz();   // ok : foo is a constant expression
// scale(arg) is a constant expression if arg is a constant expression
constexpr size_t scale(size_t cnt) { return new_sz() * cnt; }
int arr[scale(2)];  // ok: scale(2) is a constant expression
int i = 2;          // i is not a constant expression
int a2[scale(i)];   // error: scale(i) is not a constant expression