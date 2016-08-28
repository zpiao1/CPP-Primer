#include <string>
using namespace std;
template <typename T> T fobj(T, T); // arguments are copied
template <typename T> T fref(const T&, const T&);   // references
int main()
{
    string s1("a value");
    const string s2("another value");
    fobj(s1, s2);   // calls fobj(string, string); const is ignored
    fref(s1, s2);   // calls fref(const string&, const string&)
                    // uses permissible conversion to const on s1
    int a[10], b[42];
    fobj(a, b); // calls f(int*, int*)
    fref(a, b); // error: array types don't match
    return 0;
}