#include <iostream>
using namespace std;
int main()
{
    int n = 0, i = 42;
    int *p = &n, *q = &i;   // p points to n; q points to i
    *p = 42;                // value in n is changed; p is unchanged
    p = q;                  // p now points to i; values in i and n are unchanged
    return 0;
}