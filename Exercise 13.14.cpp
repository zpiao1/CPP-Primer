#include <iostream>
using namespace std;
int i = 0;
struct numbered {
    int mysn;
    numbered():
        mysn(i++) {};
};
void f(numbered s);
int main()
{
    numbered a, b = a, c = b;
    f(a); f(b); f(c);
    return 0;
}
void f(numbered s)
{
    cout << s.mysn << endl;
}