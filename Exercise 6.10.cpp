#include <iostream>
#include "Chapter6.h"
using namespace std;
int main()
{
    int a = 5, b = 10;
    swap_int(&a, &b);
    cout << a << ' ' << b << endl;
    return 0;
}
void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}