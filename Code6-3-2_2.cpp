#include <iostream>
using namespace std;
int factorial(int val)
{
    if (val > 1)
        return factorial(val-1) * val;
    return 1;
}