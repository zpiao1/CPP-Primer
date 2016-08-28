#include <iostream>
#include <string>
#include <sstream>
using namespace std;
template <typename T> string debug_rep(const T& t);
template <typename T> string debug_rep(T *p);
// the following declaration must be in scope
// for the definition of debug_rep(char*) to do the right thing
string debug_rep(const string&);
string debug_rep(char* p)
{
    // if the declaration for the version that takes a const string& is not in scope
    // the return will call debug_rep(const T&) with T instantiated to string
    return debug_rep(string(p));
}