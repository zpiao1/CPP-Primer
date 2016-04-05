#include <iostream>
#include "Chapter6.h"
using namespace std;
int main()
{
    int a = 1, b = 2;
    int *pa = &a, *pb = &b;
    cout << pa << endl;
    cout << pb << endl;
    swap_ptrs(pa, pb);
    cout << pa << endl;
    cout << pb << endl;
    cout << *pa << ' ' << a << endl;
    cout << *pb << ' ' << b << endl;
    return 0;
}
void swap_ptrs(int *(&pa), int *(&pb))
{
    int *temp = pa;
    pa = pb;
    pb = temp;
}