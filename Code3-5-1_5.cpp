#include <iostream>
using namespace std;
int main()
{
    int *ptrs[10];              // ptrs is an array of ten pointers to int
    int &refs[10] = /* ? */;    // error: no arrays of references
    int (*Parray)[10] = &arr;   // Parray points to an array of ten ints
    int (&arrRef)[10] = arr;    // arrRef refers to an array of ten ints
    int *(&arry)[10] = ptrs;    // arry is a reference to an array of ten pointers
    return 0;
}