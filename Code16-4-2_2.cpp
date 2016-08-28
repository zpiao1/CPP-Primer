#include <iostream>
#include <string>
using namespace std;
template <typename T>
ostream& print(ostream& os, const T& t);

template <typename T>
ostream& print(ostream& os, const T& t, const Args&... args);

// call debug_rep on each argument in the call to print
template <typename... Args>
ostream& errorMsg(ostream &os, const Args&... rest)
{
    // print(os, debug_rep(a1), debug_rep(a2), ..., debug_rep(an))
    return print(os, debug_rep(rest)...);
}

int main()
{
    errorMsg(cerr, fcnName, code.num(), otherData, "other", item);
    // executed as
    // print(cerr, debug_rep(fcnName), debug_rep(code.num()), debug_rep(otherData), debug_rep("other"), debug_rep(item));
    // passes the pack to debug_rep; print(os, debug_rep(a1, a2, ..., an))
    print(os, debug_rep(rest...));  // error: no matching function to call
    // same as follows
    print(os, debug_rep(fcnName, code.num(), otherData, "other", item));
    return 0;
}