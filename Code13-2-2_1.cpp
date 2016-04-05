#include "HasPtrPtrLike.h"
#include <iostream>
using namespace std;
int main()
{
    HasPtr p1("Hiya!");
    HasPtr p2(p1);      // p1 and p2 point to the same string
    HasPtr p3(p1);      // p1, p2, and p3 all point to the same string
    return 0;
}