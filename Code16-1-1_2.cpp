#include <iostream>
#include <cstring>
using namespace std;
// ok: same type used for the return type and parameter
template <typename T> T foo(T* p)
{
    T tmp = *p; // tmp will have the type to which p points
    // ...
    return tmp;
}
// error: must precede U with either typename or class
template <typename T, U> T calc(const T&, const U&);
// ok: no distinction between typename and class in a template parameter list
template <typename T, class U> calc(const T&, const U&);
template <unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
}
int main()
{
    compare("hi", "mom");
    // instantiate
    // int compare(const char (&p1)[3], const char (&p2)[4])
    return 0;
}