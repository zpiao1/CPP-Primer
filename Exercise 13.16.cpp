#include <iostream>
using namespace std;
int i = 0;
struct numbered {
    int mysn = 0;
    numbered():
        mysn(i++) {}
    numbered(const numbered &s):
        mysn(s.mysn + 1) {}
};
void f(const numbered &s);
int main()
{
    numbered a, b = a, c = b;
    f(a); f(b); f(c);
    return 0;
}
void f(const numbered &s)
{
    cout << s.mysn << endl;
}