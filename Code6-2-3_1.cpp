#include <iostream>
using namespace std;
int main()
{
    const int ci = 42;  // we cannot change ci; const is top-level
    int i = ci;         // ok: when we copy ci, its top-level const is ignored
    int * const p = &i; // const is top-level; we can't assign to p
    *p = 0;             // ok: changes through p are allowed; i is now 0
}
void fcn(const int i) { /* fcn can read but not write to i */ }
void fcn(int i) { /* . . . */ } // error: redefines fcn(int)