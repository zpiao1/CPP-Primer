#include <functional>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    find_if(svec.begin(), svec.end(), mem_fn(&string::empty));
    auto f = mem_fn(&string::empty);    // f takes a string or a string*
    f(*svec.begin());   // ok: passes a string object; f uses .* to call empty
    f(&svec[0]);    // ok: passes a pointer to string; f uses .-> to call empty
    return 0;
}