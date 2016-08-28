#include <iostream>
using namespace std;
template <typename T> void f(T);
template <typename T> void f(const T*);
template <typename T> void g(T);
template <typename T> void g(T*);
int main()
{
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;
    g(42); g(p); g(ci); g(p2);
    f(42); f(p); f(ci); f(p2);
    return 0;
}
template <typename T> void f(T t)
{
    cout << "f(T)" << endl;
    cout << "t = " << t << endl;
}

template <typename T> void f(const T* t)
{
    cout << "f(const T*)" << endl;
    cout << "t = " << t << endl;
    cout << "*t = " << *t << endl;
}

template <typename T> void g(T t)
{
    cout << "g(T)" << endl;
    cout << "t = " << t << endl;
}

template <typename T> void g(T* t)
{
    cout << "g(T*)" << endl;
    cout << "t = " << t << endl;
    cout << "*t = " << *t << endl;
}