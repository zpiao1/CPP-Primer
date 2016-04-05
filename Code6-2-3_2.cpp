#include <iostream>
using namespace std;
int main()
{
    int i = 42;
    const int *cp = &i; // ok: but cp can't change i (§ 2.4.2 (p. 62))
    const int &r = i;   // ok: but r can't change i (§ 2.4.1 (p. 61))
    int *p = cp;        // error: types of p and cp don't match (§ 2.4.2 (p. 62))
    int &r3 = r;        // error: types of r3 and r don't match (§ 2.4.1 (p. 61))
    int &r4 = 42;       // error: can't initialize a plain reference from a literal (§ 2.3.1 (p.50))
    return 0;
}