#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
    auto fp = &string::empty;   // fp points to the string empty function
    // error: must use .* or ->* to call a pointer to member
    find_if(svec.begin(), svec.end(), fp);
    function<bool (const string&)> fcn = &string::empty;
    find_if(svec.begin(), svec.end(), fcn);
    vector<string*> pvec;
    function<bool (const string*)> fp = &string::empty;
    // fp takes a pointer to string and uses the ->* to call empty
    find_if(pvec.begin(), pvec.end(), fp);
    return 0;
}
// code inside find_if
// check whether the given predicate applied to the current element yields true
// if (fp(*it))    // error: must use ->* to call through a pointer to member
// assuming it is the iterator inside find_if, so *it is an object in the given range
// if (fcn(*it))   // assuming fcn is the name of the callabble inside find_if
// function class translate the code above
// assuming it is the iterator inside find_if, so *it is an object in the given range
// if (((*it).*p)())   // assuming p is the pointer to member funtion inside fcn