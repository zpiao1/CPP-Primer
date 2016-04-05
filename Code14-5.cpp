#include "StrVec.h"
using namespace std;
int main()
{
    // assume svec is a StrVec
    const StrVec cvec = svec;   // copy elements from svec into cvec
    // if svec has any elements, run the string empty function on the first one
    if (svec.size() && svec[0].empty()) {
        svec[0] = "zero";   // ok: subscript returns a reference to a string
        cvec[0] = "Zip";    // error: subscripting cvec returns a reference to const
    }
    return 0;
}