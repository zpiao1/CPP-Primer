#include <iostream>
int main()
{
    int n = 0, i = 42;
    int &r = n;         // r is bounded to n (i.e., r is another name for n)
    r = 42;             // n is now 42
    r = i;              // n now has the same value as i
    i = r;              // i has the same value as n
    return 0;
}