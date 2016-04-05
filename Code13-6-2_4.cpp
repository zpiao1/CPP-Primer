#include "HasPtr.h"
#include <utility>
int main()
{
    hp = hp2;   // hp2 is an lvalue; copy constructor used to copy hp2
    hp = std::move(hp2);    // move constructor moves hp2
    return 0;
}