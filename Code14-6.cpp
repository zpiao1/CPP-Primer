#include "StrBlobPtr.h"
using namespace std;
int main()
{
    StrBlobPtr p(a1);   // p points to the vector inside a1
    p.operator++(0);    // call postfix operator++
    p.operator++();     // call prefix operator++
    return 0;
}