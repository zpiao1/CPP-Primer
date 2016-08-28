#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template <typename T> string debug_rep(const T& t)
{
    ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T> string debug_rep(T* p)
{
    ostringstream ret;
    ret << "pointer: " << p;
    if (p)
        ret << " " << debug_rep(*p);
    else
        ret << " null pointer";
    return ret.str();
}
// Specialization to string debug_rep(const T& t)
template <> string debug_rep(const string& s)
{
    return '"' + s + '"';
}
// Specializations to string debug_rep(T* p)
template <> string debug_rep(char* p)
{
    return debug_rep(string(p));
}

template <> string debug_rep(const char* p)
{
    return debug_rep(string(p));
}

int main()
{
    char carr[] = "hi world!";
    char* cp = carr;
    const char* ccp = "hi world!";
    cout << debug_rep(cp) << endl;
    cout << debug_rep(ccp) << endl;
    return 0;
}