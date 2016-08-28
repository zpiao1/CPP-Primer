#include <iostream>
using namespace std;
template <typename T, typename... Args> ostream& 
print(ostream& os, const T& t, const Args&... rest) // expand Args
{
    os << t << ", ";
    return print(os, rest...);  // expand rest
}