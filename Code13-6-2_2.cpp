#include "StrVec.h"
#include <iostream>
using namespace std;
StrVec getVec(istream &);   // getVec returns an rvalue
int main()
{
    StrVec v1, v2;
    v1 = v2;        // v2 is an lvalue; copy assignment
    v2 = getVec(cin);   // getVec(cin) is an rvalue; move assignment
    return 0;
}