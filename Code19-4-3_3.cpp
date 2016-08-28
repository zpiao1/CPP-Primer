#include <string>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
using namespace std::placeholders;
int main()
{
    // bind each string in the range to the implicit first argument to empty
    auto it = find_if(svec.begin(), svec.end(), bind(&string::empty, _1));
    auto f = bind(&string::empty, _1);
    f(*svec.begin());   // ok: argument is a string f will use .* to call empty
    f(&svec[0]);    // ok: argument is a pointer to string f will use ->* to call empty
    return 0;
}